#include "include.h"

PREFIX Eina_Bool ml_Elm_Naviframe_Item_Pop_Cb(void* data, Elm_Object_Item* it)
{
      
        value* v_fun = (value*) data;
        Eina_Bool b = Bool_val(caml_callback(*v_fun, (value) it));
      
        return b;
}

PREFIX value ml_elm_naviframe_add(value v_parent)
{
        Evas_Object* obj = elm_naviframe_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_naviframe_add");
        return (value) obj;
}

PREFIX value ml_elm_naviframe_item_push_native(
        value v_obj, value v_title_label, value v_prev_btn, value v_next_btn,
        value v_content, value v_item_style, value v_unit)
{
        Evas_Object *prev_btn, *next_btn;
        if(v_prev_btn == Val_int(0)) prev_btn = NULL;
        else prev_btn = (Evas_Object*) Field(v_prev_btn, 0);
        if(v_next_btn == Val_int(0)) next_btn = NULL;
        else next_btn = (Evas_Object*) Field(v_next_btn, 0);
        char *title_label, *item_style;
        if(v_title_label == Val_int(0)) title_label = NULL;
        else title_label = String_val(Field(v_title_label, 0));
        if(v_item_style == Val_int(0)) item_style = NULL;
        else item_style = String_val(Field(v_item_style, 0));
        Elm_Object_Item* item = elm_naviframe_item_push((Evas_Object*) v_obj,
                title_label, prev_btn, next_btn, (Evas_Object*) v_content,
                item_style);
        if(item == NULL) caml_failwith("elm_naviframe_item_push");
        return (value) item;
}

PREFIX value ml_elm_naviframe_item_push_byte(value* argv, int argn)
{
        return ml_elm_naviframe_item_push_native(argv[0], argv[1], argv[2],
                argv[3], argv[4], argv[5], argv[6]);
}

PREFIX value ml_elm_naviframe_item_insert_before_native(
        value v_obj, value v_before, value v_title_label, value v_prev_btn,
        value v_next_btn, value v_content, value v_item_style, value v_unit)
{
        Evas_Object *prev_btn, *next_btn;
        if(v_prev_btn == Val_int(0)) prev_btn = NULL;
        else prev_btn = (Evas_Object*) Field(v_prev_btn, 0);
        if(v_next_btn == Val_int(0)) next_btn = NULL;
        else next_btn = (Evas_Object*) Field(v_next_btn, 0);
        char *title_label, *item_style;
        if(v_title_label == Val_int(0)) title_label = NULL;
        else title_label = String_val(Field(v_title_label, 0));
        if(v_item_style == Val_int(0)) item_style = NULL;
        else item_style = String_val(Field(v_item_style, 0));
        Elm_Object_Item* item = elm_naviframe_item_insert_before(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_before, title_label,
                prev_btn, next_btn, (Evas_Object*) v_content, item_style);
        if(item == NULL) caml_failwith("elm_naviframe_item_insert_before");
        return (value) item;
}
        
PREFIX value ml_elm_naviframe_item_insert_before_byte(value* argv, int argn)
{
        return ml_elm_naviframe_item_insert_before_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

PREFIX value ml_elm_naviframe_item_insert_after_native(
        value v_obj, value v_after, value v_title_label, value v_prev_btn,
        value v_next_btn, value v_content, value v_item_style, value v_unit)
{
        Evas_Object *prev_btn, *next_btn;
        if(v_prev_btn == Val_int(0)) prev_btn = NULL;
        else prev_btn = (Evas_Object*) Field(v_prev_btn, 0);
        if(v_next_btn == Val_int(0)) next_btn = NULL;
        else next_btn = (Evas_Object*) Field(v_next_btn, 0);
        char *title_label, *item_style;
        if(v_title_label == Val_int(0)) title_label = NULL;
        else title_label = String_val(Field(v_title_label, 0));
        if(v_item_style == Val_int(0)) item_style = NULL;
        else item_style = String_val(Field(v_item_style, 0));
        Elm_Object_Item* item = elm_naviframe_item_insert_after(
                (Evas_Object*) v_obj, (Elm_Object_Item*) v_after, title_label,
                prev_btn, next_btn, (Evas_Object*) v_content, item_style);
        if(item == NULL) caml_failwith("elm_naviframe_item_insert_after");
        return (value) item;
}
        
PREFIX value ml_elm_naviframe_item_insert_after_byte(value* argv, int argn)
{
        return ml_elm_naviframe_item_insert_after_native(argv[0], argv[1],
                argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
}

PREFIX value ml_elm_naviframe_item_pop(value v_obj)
{
        Evas_Object* top = elm_naviframe_item_pop((Evas_Object*) v_obj);
        if(top == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) top);
        return v;
}

PREFIX value ml_elm_naviframe_item_pop_to(value v_it)
{
        elm_naviframe_item_pop_to((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_naviframe_item_promote(value v_it)
{
        elm_naviframe_item_promote((Elm_Object_Item*) v_it);
        return Val_unit;
}

PREFIX value ml_elm_naviframe_content_preserve_on_pop_set(
        value v_obj, value v_flag)
{
        elm_naviframe_content_preserve_on_pop_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_naviframe_content_preserve_on_pop_get(value v_obj)
{
        return Val_Eina_Bool(elm_naviframe_content_preserve_on_pop_get(
        (Evas_Object*) v_obj));
}

PREFIX value ml_elm_naviframe_top_item_get(value v_obj)
{
        Elm_Object_Item* it = elm_naviframe_top_item_get((Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_naviframe_bottom_item_get(value v_obj)
{
        Elm_Object_Item* it = elm_naviframe_bottom_item_get(
                (Evas_Object*) v_obj);
        if(it == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) it);
        return v;
}

PREFIX value ml_elm_naviframe_item_style_set(value v_it, value v_style)
{
        const char* style;
        if(v_style == Val_int(0)) style = NULL;
        else style = String_val(Field(v_style, 0));
        elm_naviframe_item_style_set((Elm_Object_Item*) v_it, style);
        return Val_unit;
}

PREFIX value ml_elm_naviframe_item_style_get(value v_it)
{
        return copy_string(elm_naviframe_item_style_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_naviframe_item_title_visible_set(value v_it, value v_flag)
{
        elm_naviframe_item_title_visible_set((Elm_Object_Item*) v_it,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_naviframe_item_title_visible_get(value v_it)
{
        return Val_Eina_Bool(elm_naviframe_item_title_visible_get(
                (Elm_Object_Item*) v_it));
}

PREFIX value ml_elm_naviframe_item_pop_cb_set(value v_it, value v_fun)
{
        CAMLparam2(v_it, v_fun);
        Elm_Object_Item* it = (Elm_Object_Item*) v_it;
        value* data = ml_Elm_Object_Item_register_value(it, v_fun);
        elm_naviframe_item_pop_cb_set(it, ml_Elm_Naviframe_Item_Pop_Cb, data);
        CAMLreturn(Val_unit);
}

PREFIX value ml_elm_naviframe_prev_btn_auto_pushed_set(value v_obj, value v_flag)
{
        elm_naviframe_prev_btn_auto_pushed_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_naviframe_prev_btn_auto_pushed_get(value v_obj)
{
        return Val_Eina_Bool(elm_naviframe_prev_btn_auto_pushed_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_naviframe_items_get(value v_obj)
{
        Eina_List* list = elm_naviframe_items_get((Evas_Object*) v_obj);
        value v_list = copy_Eina_List_Elm_Object_Item(list);
        eina_list_free(list);
        return v_list;
}

PREFIX value ml_elm_naviframe_event_enabled_set(value v_obj, value v_flag)
{
        elm_naviframe_event_enabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_naviframe_event_enabled_get(value v_obj)
{
        return Val_Eina_Bool(elm_naviframe_event_enabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_naviframe_item_simple_promote(value v_obj, value v_content)
{
        elm_naviframe_item_simple_promote((Evas_Object*) v_obj,
                (Evas_Object*) v_content);
        return Val_unit;
}

