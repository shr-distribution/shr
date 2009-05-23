#include "views.h"
#include "call-common.h"

struct CallIncomingViewData {
    struct CallViewData parent;
    Evas_Object *bt1, *bt2;
    Evas_Object *information, *number;
};

static void call_button_accept_clicked(struct CallIncomingViewData *data, Evas_Object *obj, void *event_info);

struct CallIncomingViewData*
call_incoming_view_show(struct Window *win, GHashTable *options) {
	g_debug("call_incoming_view_show()");

	struct CallIncomingViewData *data = g_slice_alloc0(sizeof(struct CallIncomingViewData));
	data->parent.options = options;
	data->parent.win = win;
	data->parent.id = GPOINTER_TO_INT(g_hash_table_lookup(options, "id"));
	data->parent.number = g_hash_table_lookup(options, "number");
	data->parent.dtmf_active = FALSE;

	window_layout_set(win, CALL_FILE, "incoming_call");

	data->number = elm_label_add( window_evas_object_get(win) );
	elm_label_label_set( data->number,  data->parent.number);
	window_swallow(win, "number", data->number);
	evas_object_show(data->number);

	data->information = elm_label_add( window_evas_object_get(win) );
	elm_label_label_set( data->information,  D_("Incoming call"));
	window_swallow(win, "information", data->information);
	evas_object_show(data->information);

	data->bt1 = elm_button_add(window_evas_object_get(win));
	elm_button_label_set(data->bt1, D_("Accept"));
	evas_object_smart_callback_add(data->bt1, "clicked", call_button_accept_clicked, data);
	window_swallow(win, "button_accept", data->bt1);
	evas_object_show(data->bt1);

	data->bt2 = elm_button_add(window_evas_object_get(win));
	elm_button_label_set(data->bt2, D_("Release"));
	evas_object_smart_callback_add(data->bt2, "clicked", call_button_release_clicked, data);
	window_swallow(win, "button_release", data->bt2);
	evas_object_show(data->bt2);

	return data;
}

void
call_incoming_view_hide(struct CallIncomingViewData *data) {
	g_debug("call_incoming_view_hide()");

	struct Window *win = data->parent.win;

	evas_object_del(data->information);
	evas_object_del(data->number);
	evas_object_del(data->bt1);
	evas_object_del(data->bt2);

	if(data->parent.dtmf_active) {
		call_dtmf_disable(&data->parent);
	}

	if(speaker_active) {
		call_speaker_disable();
	}
}


static void
call_button_accept_clicked(struct CallIncomingViewData *data, Evas_Object *obj, void *event_info)
{
	g_debug("accept_clicked()");
	ogsmd_call_activate(data->parent.id, NULL, NULL);

	GHashTable *options = g_hash_table_new(g_str_hash, g_str_equal);
	g_hash_table_insert(options, "id", GINT_TO_POINTER(data->parent.id));
	g_hash_table_insert(options, "number", strdup(data->parent.number));
	window_view_show(data->parent.win, options, call_active_view_show, call_active_view_hide);
}


