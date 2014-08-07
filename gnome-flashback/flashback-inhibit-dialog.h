/*
 * Copyright (C) 2008 William Jon McCann <mccann@jhu.edu>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GSM_INHIBIT_DIALOG_H
#define __GSM_INHIBIT_DIALOG_H

#include <glib-object.h>
#include <gtk/gtk.h>

#include "gsm-store.h"

G_BEGIN_DECLS

#define GSM_TYPE_INHIBIT_DIALOG         (gsm_inhibit_dialog_get_type ())
#define GSM_INHIBIT_DIALOG(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), GSM_TYPE_INHIBIT_DIALOG, GsmInhibitDialog))
#define GSM_INHIBIT_DIALOG_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), GSM_TYPE_INHIBIT_DIALOG, GsmInhibitDialogClass))
#define GSM_IS_INHIBIT_DIALOG(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), GSM_TYPE_INHIBIT_DIALOG))
#define GSM_IS_INHIBIT_DIALOG_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), GSM_TYPE_INHIBIT_DIALOG))
#define GSM_INHIBIT_DIALOG_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), GSM_TYPE_INHIBIT_DIALOG, GsmInhibitDialogClass))

typedef struct GsmInhibitDialogPrivate GsmInhibitDialogPrivate;

typedef enum
{
        GSM_LOGOUT_ACTION_LOGOUT,
        GSM_LOGOUT_ACTION_SWITCH_USER,
        GSM_LOGOUT_ACTION_SHUTDOWN,
        GSM_LOGOUT_ACTION_REBOOT,
        GSM_LOGOUT_ACTION_HIBERNATE,
        GSM_LOGOUT_ACTION_SLEEP
} GsmLogoutAction;

typedef struct
{
        GtkDialog                parent;
        GsmInhibitDialogPrivate *priv;
} GsmInhibitDialog;

typedef struct
{
        GtkDialogClass   parent_class;
} GsmInhibitDialogClass;

GType                  gsm_inhibit_dialog_get_type           (void);

GtkWidget            * gsm_inhibit_dialog_new                (int action,
                                                              int seconds,
                                                              const char *const *inhibitor_paths);

G_END_DECLS

#endif /* __GSM_INHIBIT_DIALOG_H */
