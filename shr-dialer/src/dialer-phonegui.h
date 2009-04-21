/*
 *  Copyright (C) 2008
 *      Authors (alphabetical) :
 *              quickdev
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Public License as published by
 *  the Free Software Foundation; version 2 of the license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser Public License for more details.
 */

#ifndef _DIALER_PHONEGUI_H
#define _DIALER_PHONEGUI_H

#include <frameworkd-phonegui/frameworkd-phonegui.h>

void (*phonegui_init)(int argc, char **argv, void (*exit_callback)());
void (*phonegui_dialer_show)();

void phonegui_connect();

#endif
