/* 
 * Copyright (C) 2014 Alberts Muktupāvels
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

#include <glib/gi18n.h>
#include <gtk/gtk.h>
#include "config.h"
#include "flashback-application.h"
#include "libautomount-manager/gsd-automount-manager.h"
#include "libdesktop-background/desktop-background.h"
#include "libdisplay-config/flashback-display-config.h"
#include "libend-session-dialog/flashback-end-session-dialog.h"
#include "libidle-monitor/meta-idle-monitor-dbus.h"
#include "libsound-applet/gvc-applet.h"

#define FLASHBACK_SCHEMA       "org.gnome.gnome-flashback"
#define KEY_AUTOMOUNT_MANAGER  "automount-manager"
#define KEY_DESKTOP_BACKGROUND "desktop-background"
#define KEY_DISPLAY_CONFIG     "display-config"
#define KEY_END_SESSION_DIALOG "end-session-dialog"
#define KEY_IDLE_MONITOR       "idle-monitor"
#define KEY_SOUND_APPLET       "sound-applet"

struct _FlashbackApplicationPrivate {
	GSettings                  *settings;
	GsdAutomountManager        *automount;
	DesktopBackground          *background;
	FlashbackDisplayConfig     *config;
	FlashbackEndSessionDialog  *dialog;
	MetaIdleMonitorDBus        *idle_monitor;
	GvcApplet                  *applet;
};

G_DEFINE_TYPE_WITH_PRIVATE (FlashbackApplication, flashback_application, GTK_TYPE_APPLICATION);

static void
flashback_application_settings_changed (GSettings   *settings,
                                        const gchar *key,
                                        gpointer     user_data)
{
	FlashbackApplication *app = FLASHBACK_APPLICATION (user_data);

	if (key == NULL || g_strcmp0 (key, KEY_AUTOMOUNT_MANAGER) == 0) {
		if (g_settings_get_boolean (settings, KEY_AUTOMOUNT_MANAGER)) {
			if (app->priv->automount == NULL) {
				app->priv->automount = gsd_automount_manager_new ();
			}
		} else {
			if (app->priv->automount) {
				g_object_unref (app->priv->automount);
				app->priv->automount = NULL;
			}
		}
	}

	if (key == NULL || g_strcmp0 (key, KEY_DESKTOP_BACKGROUND) == 0) {
		if (g_settings_get_boolean (settings, KEY_DESKTOP_BACKGROUND)) {
			if (app->priv->background == NULL) {
				app->priv->background = desktop_background_new ();
			}
		} else {
			if (app->priv->background) {
				g_object_unref (app->priv->background);
				app->priv->background = NULL;
			}
		}
	}
	
	if (key == NULL || g_strcmp0 (key, KEY_DISPLAY_CONFIG) == 0) {
		if (g_settings_get_boolean (settings, KEY_DISPLAY_CONFIG)) {
			if (app->priv->config == NULL) {
				app->priv->config = flashback_display_config_new ();
			}
		} else {
			if (app->priv->config) {
				g_object_unref (app->priv->config);
				app->priv->config = NULL;
			}
		}
	}

	if (key == NULL || g_strcmp0 (key, KEY_END_SESSION_DIALOG) == 0) {
		if (g_settings_get_boolean (settings, KEY_END_SESSION_DIALOG)) {
			if (app->priv->dialog == NULL) {
				app->priv->dialog = flashback_end_session_dialog_new ();
			}
		} else {
			if (app->priv->dialog) {
				g_object_unref (app->priv->dialog);
				app->priv->dialog = NULL;
			}
		}
	}
	
	if (key == NULL || g_strcmp0 (key, KEY_IDLE_MONITOR) == 0) {
		if (g_settings_get_boolean (settings, KEY_IDLE_MONITOR)) {
			if (app->priv->idle_monitor == NULL) {
				app->priv->idle_monitor = meta_idle_monitor_dbus_new ();
			}
		} else {
			if (app->priv->idle_monitor) {
				g_object_unref (app->priv->idle_monitor);
				app->priv->idle_monitor = NULL;
			}
		}
	}

	if (key == NULL || g_strcmp0 (key, KEY_SOUND_APPLET) == 0) {
		if (g_settings_get_boolean (settings, KEY_SOUND_APPLET)) {
			if (app->priv->applet == NULL) {
				app->priv->applet = gvc_applet_new ();
			}
		} else {
			if (app->priv->applet) {
				g_object_unref (app->priv->applet);
				app->priv->applet = NULL;
			}
		}
	}
}

static void
flashback_application_activate (GApplication *application)
{
}

static void
flashback_application_startup (GApplication *application)
{
	FlashbackApplication *app = FLASHBACK_APPLICATION (application);

	G_APPLICATION_CLASS (flashback_application_parent_class)->startup (application);

	bindtextdomain (GETTEXT_PACKAGE, GNOMELOCALEDIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);

	app->priv->settings = g_settings_new (FLASHBACK_SCHEMA);

	g_signal_connect (app->priv->settings, "changed",
	                  G_CALLBACK (flashback_application_settings_changed), app);
	flashback_application_settings_changed (app->priv->settings, NULL, app);

	g_application_hold (application);
}

static void
flashback_application_shutdown (GApplication *application)
{
	FlashbackApplication *app = FLASHBACK_APPLICATION (application);

	if (app->priv->automount) {
		g_object_unref (app->priv->automount);
		app->priv->automount = NULL;
	}

	if (app->priv->background) {
		g_object_unref (app->priv->background);
		app->priv->background = NULL;
	}

	if (app->priv->config) {
		g_object_unref (app->priv->config);
		app->priv->config = NULL;
	}

	if (app->priv->dialog) {
		g_object_unref (app->priv->dialog);
		app->priv->dialog = NULL;
	}

	if (app->priv->idle_monitor) {
		g_object_unref (app->priv->idle_monitor);
		app->priv->idle_monitor = NULL;
	}

	g_clear_object (&app->priv->applet);

	if (app->priv->settings) {
		g_object_unref (app->priv->settings);
		app->priv->settings = NULL;
	}

	G_APPLICATION_CLASS (flashback_application_parent_class)->shutdown (application);
}

static void
flashback_application_init (FlashbackApplication *application)
{
	application->priv = flashback_application_get_instance_private (application);
}

static void
flashback_application_class_init (FlashbackApplicationClass *class)
{
	GApplicationClass *application_class = G_APPLICATION_CLASS (class);

	application_class->startup  = flashback_application_startup;
	application_class->shutdown = flashback_application_shutdown;
	application_class->activate = flashback_application_activate;
}

FlashbackApplication *
flashback_application_new (void)
{
	return g_object_new (FLASHBACK_TYPE_APPLICATION,
	                     "application-id", "org.gnome.gnome-flashback",
	                     "flags", G_APPLICATION_FLAGS_NONE,
	                     "register-session", TRUE,
	                     NULL);
}
