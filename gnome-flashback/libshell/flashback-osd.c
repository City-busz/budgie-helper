/*
 * Copyright (C) 2015 Alberts Muktupāvels
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

#include <config.h>
#include "flashback-osd.h"

struct _FlashbackOsd
{
  GObject parent;
};

G_DEFINE_TYPE (FlashbackOsd, flashback_osd, G_TYPE_OBJECT)

static void
flashback_osd_class_init (FlashbackOsdClass *osd_class)
{
}

static void
flashback_osd_init (FlashbackOsd *osd)
{
}

FlashbackOsd *
flashback_osd_new (void)
{
  return g_object_new (FLASHBACK_TYPE_OSD, NULL);
}

void
flashback_osd_show (FlashbackOsd *osd,
                    GVariant     *params)
{
  g_warning ("shell: show osd");
}
