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

#include "ophonekitd-phonegui.h"

void phonegui_connect() {
    phonegui_init = phonegui_get_function("phonegui_init");
    phonegui_sim_auth_show = phonegui_get_function("phonegui_sim_auth_show");
    phonegui_sim_auth_hide = phonegui_get_function("phonegui_sim_auth_hide");
    phonegui_incoming_call_show = phonegui_get_function("phonegui_incoming_call_show");
    phonegui_incoming_call_hide = phonegui_get_function("phonegui_incoming_call_hide");
    phonegui_outgoing_call_show = phonegui_get_function("phonegui_outgoing_call_show");
    phonegui_outgoing_call_hide = phonegui_get_function("phonegui_outgoing_call_hide");
    phonegui_message_show = phonegui_get_function("phonegui_message_show");
    phonegui_message_hide = phonegui_get_function("phonegui_message_hide");
    phonegui_dialog_show = phonegui_get_function("phonegui_dialog_show");
    phonegui_dialog_hide = phonegui_get_function("phonegui_dialog_hide");
    phonegui_ussd_show = phonegui_get_function("phonegui_ussd_show");
    phonegui_ussd_hide = phonegui_get_function("phonegui_ussd_hide");
    phonegui_message_receipt_show = phonegui_get_function("phonegui_message_receipt_show");
    phonegui_message_receipt_hide = phonegui_get_function("phonegui_message_receipt_hide");
}

