#include "views.h"

struct DialogViewData {
    struct Window *win;
    Evas_Object *bt_close;
};

static void dialog_view_close_clicked(void *userdata, Evas_Object *obj, void *event_info);


struct DialogViewData *dialog_view_show(struct Window *win, GHashTable *options) {
    struct DialogViewData *data = g_slice_alloc0(sizeof(struct DialogViewData));
    data->win = win;

    window_layout_set(win, DIALOG_FILE, "dialog");
    window_text_set(win, "content", "Your storage is full. Please delete some messages or you are not going to receive messages anymore!");

    data->bt_close = elm_button_add(win);
    elm_button_label_set(data->bt_close, "Close");
    evas_object_smart_callback_add(data->bt_close, "clicked", dialog_view_close_clicked, win);
    window_swallow(win, "button_close", data->bt_close);
    evas_object_show(data->bt_close);
}

void dialog_view_hide(struct DialogViewData *data) {
    evas_object_del(data->bt_close);
}

static void dialog_view_close_clicked(void *userdata, Evas_Object *obj, void *event_info) {
    struct DialogViewData *data = (struct DialogViewData *) userdata;
    window_destroy(data->win, NULL);
}


