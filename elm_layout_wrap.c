#include "include.h"

typedef struct _value_ptr_list {
        value* hd;
        struct _value_ptr_list* tl;
} value_ptr_list;

PREFIX value ml_elm_layout_add(value v_parent)
{
        Evas_Object* layout = elm_layout_add((Evas_Object*) v_parent);
        if(layout == NULL) caml_failwith("layout");
        return (value) layout;
}

PREFIX value ml_elm_layout_box_append_with_bool(
        value v_obj, value v_part, value v_child)
{
        return Val_Eina_Bool(elm_layout_box_append((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child));
}

PREFIX value ml_elm_layout_box_insert_at_with_bool(
        value v_obj, value v_part, value v_child, value v_pos)
{
        return Val_Eina_Bool(elm_layout_box_insert_at((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child,
                Int_val(v_pos)));
}

PREFIX value ml_elm_layout_box_insert_before_with_bool(
        value v_obj, value v_part, value v_child, value v_ref)
{
        return Val_Eina_Bool(elm_layout_box_insert_before((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child,
                (Evas_Object*) v_ref));
}

PREFIX value ml_elm_layout_box_prepend_with_bool(
        value v_obj, value v_part, value v_child)
{
        return Val_Eina_Bool(elm_layout_box_prepend((Evas_Object*) v_obj,
                String_val(v_part), (Evas_Object*) v_child));
}

PREFIX ml_elm_layout_file_set_with_bool(
        value v_obj, value v_file, value v_group)
{
        return Val_Eina_Bool(elm_layout_file_set((Evas_Object*) v_obj,
                String_val(v_file), String_val(v_group)));
}

PREFIX ml_elm_layout_theme_set_with_bool(
        value v_obj, value v_clas, value v_group, value v_style)
{
        return Val_Eina_Bool(elm_layout_theme_set((Evas_Object*) v_obj,
                String_val(v_clas), String_val(v_group), String_val(v_style)));
}

PREFIX ml_elm_layout_signal_emit(value v_obj, value v_emission, value v_source)
{
        elm_layout_signal_emit((Evas_Object*) v_obj, String_val(v_emission),
                String_val(v_source));
        return Val_unit;
}

PREFIX ml_elm_layout_signal_callback_add(
        value v_obj, value v_emission, value v_source, value v_fun)
{
        value *data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_layout_signal_callback_add((Evas_Object*) v_obj,
                String_val(v_emission), String_val(v_source),
                ml_Edje_Signal_Cb, data);
        return Val_unit;
}

PREFIX ml_elm_layout_signal_callback_del(
        value v_obj, value v_emission, value v_source, value v_fun)
{
        Evas_Object* obj = (Evas_Object*) v_obj;
        const char* emission = (const char*) String_val(v_emission);
        const char* source = (const char*) String_val(v_source);
        value* data;
        value_ptr_list* list = NULL;
        value_ptr_list* list1;
        while(1) {
                data = elm_layout_signal_callback_del(obj, emission, source,
                        ml_Edje_Signal_Cb);
                if(*data == v_fun) {
                        caml_remove_global_root(data);
                        free(data);
                        break;
                } else {
                        list1 = list;
                        list = caml_stat_alloc(sizeof(value_ptr_list));
                        list->hd = data;
                        list->tl = list1;
                }
        }
        while(list != NULL) {
                elm_layout_signal_callback_add(obj, emission, source,
                        ml_Edje_Signal_Cb, list->hd);
                list1 = list->tl;
                free(list1);
                list = list1;
        }
        return Val_unit;
}


