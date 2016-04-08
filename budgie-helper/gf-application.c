/*
 * Copyright (C) 2014 - 2015 Alberts Muktupāvels
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#include <glib/gi18n.h>
#include <gtk/gtk.h>

#include "gf-application.h"
#include "libautomount-manager/gsd-automount-manager.h"
#include "libdesktop-background/gf-desktop-background.h"
#include "libworkarounds/gf-workarounds.h"

struct _GfApplication
{
  GObject                 parent;

  gint                    bus_name;

  GSettings              *settings;

  GtkCssProvider         *provider;

  GsdAutomountManager    *automount;
  GfDesktopBackground    *background;
  GfWorkarounds          *workarounds;
};

G_DEFINE_TYPE (GfApplication, gf_application, G_TYPE_OBJECT)

static void
remove_style_provider (GfApplication *application,
                       GdkScreen     *screen)
{
  GtkStyleProvider *provider;

  if (application->provider == NULL)
    return;

  provider = GTK_STYLE_PROVIDER (application->provider);
  gtk_style_context_remove_provider_for_screen (screen, provider);
  g_clear_object (&application->provider);
}

static void
settings_changed (GSettings   *settings,
                  const gchar *key,
                  gpointer     user_data)
{
  GfApplication *application;

  application = GF_APPLICATION (user_data);

#define SETTING_CHANGED(variable_name, setting_name, function_name) \
  if (key == NULL || g_strcmp0 (key, setting_name) == 0)            \
    {                                                               \
      if (g_settings_get_boolean (settings, setting_name))          \
        {                                                           \
          if (application->variable_name == NULL)                   \
            application->variable_name = function_name ();          \
        }                                                           \
      else                                                          \
        {                                                           \
          g_clear_object (&application->variable_name);             \
        }                                                           \
    }

  SETTING_CHANGED (automount, "automount-manager", gsd_automount_manager_new)
  SETTING_CHANGED (background, "desktop-background", gf_desktop_background_new)
  SETTING_CHANGED (workarounds, "workarounds", gf_workarounds_new)

#undef SETTING_CHANGED

}

static void
gf_application_dispose (GObject *object)
{
  GfApplication *application;
  GdkScreen *screen;

  application = GF_APPLICATION (object);
  screen = gdk_screen_get_default ();

  g_clear_object (&application->settings);

  remove_style_provider (application, screen);

  g_clear_object (&application->automount);
  g_clear_object (&application->background);
  g_clear_object (&application->workarounds);

  G_OBJECT_CLASS (gf_application_parent_class)->dispose (object);
}

static void
gf_application_init (GfApplication *application)
{
  GtkSettings *settings;

  application->settings = g_settings_new ("com.solus-project.budgie-helper");
  settings = gtk_settings_get_default ();

  g_signal_connect (application->settings, "changed",
                    G_CALLBACK (settings_changed), application);

  settings_changed (application->settings, NULL, application);
}

static void
gf_application_class_init (GfApplicationClass *application_class)
{
  GObjectClass *object_class;

  object_class = G_OBJECT_CLASS (application_class);

  object_class->dispose = gf_application_dispose;
}

GfApplication *
gf_application_new (void)
{
  return g_object_new (GF_TYPE_APPLICATION, NULL);
}
