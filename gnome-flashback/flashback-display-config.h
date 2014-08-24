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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FLASHBACK_DISPLAY_CONFIG_H
#define FLASHBACK_DISPLAY_CONFIG_H

#include <glib-object.h>

G_BEGIN_DECLS

#define FLASHBACK_TYPE_DISPLAY_CONFIG (flashback_display_config_get_type ())
#define FLASHBACK_DISPLAY_CONFIG(o)   (G_TYPE_CHECK_INSTANCE_CAST ((o), FLASHBACK_TYPE_DISPLAY_CONFIG, FlashbackDisplayConfig))

typedef struct _FlashbackDisplayConfig        FlashbackDisplayConfig;
typedef struct _FlashbackDisplayConfigClass   FlashbackDisplayConfigClass;
typedef struct _FlashbackDisplayConfigPrivate FlashbackDisplayConfigPrivate;

struct _FlashbackDisplayConfig {
	GObject                        parent;
	FlashbackDisplayConfigPrivate *priv;
};

struct _FlashbackDisplayConfigClass {
    GObjectClass parent_class;
};

GType                   flashback_display_config_get_type (void);
FlashbackDisplayConfig *flashback_display_config_new      (void);

G_END_DECLS

#endif
