#  This file is part of Mapnik (c++ mapping toolkit)
#  Copyright (C) 2005 Artem Pavlenko, Jean-Francois Doyon
#
#  Mapnik is free software; you can redistribute it and/or
#  modify it under the terms of the GNU General Public License
#  as published by the Free Software Foundation; either version 2
#  of the License, or any later version.
# 
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
# 
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
# 
# $Id$

import os
import glob

Import('env')

# grab all the deja vu fonts
includes = glob.glob('*/*/*.ttf')

# grab single unifont ttf (available at http://unifoundry.com/unifont.html)
includes.extend(glob.glob('unifont*.ttf'))

if 'uninstall' not in COMMAND_LINE_TARGETS and not env['SYSTEM_FONTS']:
    env.Alias(target='install', source=env.Install(env['MAPNIK_FONTS_DEST'], includes))