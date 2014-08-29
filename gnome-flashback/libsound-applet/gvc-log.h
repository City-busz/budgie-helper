/*
 * Copyright (C) 2009 Red Hat, Inc.
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

#ifndef __GVC_LOG_H
#define __GVC_LOG_H

#include <glib.h>

G_BEGIN_DECLS


void gvc_log_init      (void);
void gvc_log_set_debug (gboolean debug);


G_END_DECLS

#endif /* __GVC_LOG_H */
