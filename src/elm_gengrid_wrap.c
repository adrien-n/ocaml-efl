#include "include.h"

PREFIX void ml_Elm_Gengrid_Item_Class(
        Elm_Gen_Item_Class** class, void** data, value v)
{
        Elm_Gen_Item_Class* c = elm_gengrid_item_class_new();
        if(c == NULL) caml_raise_out_of_memory();

        c->item_style = String_val(Field(v, 0));
        c->func.text_get = ml_Elm_Gen_Item_Text_Get_Cb;
        c->func.content_get = ml_Elm_Gen_Item_Content_Get_Cb;
        c->func.state_get = ml_Elm_Gen_Item_State_Get_Cb;
        c->func.del = ml_Elm_Gen_Item_Del_Cb_free;

        value* v_data = ml_register_value(v);

        *class = c;
        *data = v_data;
}

PREFIX value ml_elm_gengrid_add(value v_parent)
{
        Evas_Object* obj = elm_gengrid_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_gengrid_add");
        return (value) obj;
}

PREFIX value ml_elm_gengrid_item_append(
        value v_obj, value v_class, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = ml_register_value(v_func);

        Elm_Object_Item* item = elm_gengrid_item_append((Evas_Object*) v_obj,
                class, data, ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) {
                ml_remove_value(data);
                ml_remove_value(data_func);
        }
        ml_Elm_Object_Item_gc_value(item, data_func);
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_prepend(
        value v_obj, value v_class, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = ml_register_value(v_func);

        Elm_Object_Item* item = elm_gengrid_item_prepend((Evas_Object*) v_obj,
                class, data, ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) {
                ml_remove_value(data);
                ml_remove_value(data_func);
                caml_failwith("elm_gengrid_item_prepend");
        }
        ml_Elm_Object_Item_gc_value(item, data_func);
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_insert_before(
        value v_obj, value v_class, value v_rel, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = ml_register_value(v_func);

        Elm_Object_Item* item = elm_gengrid_item_insert_before(
                (Evas_Object*) v_obj, class, data, (Elm_Object_Item*) v_rel,
                ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) {
                ml_remove_value(data);
                ml_remove_value(data_func);
                caml_failwith("elm_gengrid_item_insert_before");
        }
        ml_Elm_Object_Item_gc_value(item, data_func);
        return (value) item;
}

PREFIX value ml_elm_gengrid_item_insert_after(
        value v_obj, value v_class, value v_rel, value v_func)
{
        Elm_Gengrid_Item_Class* class;
        void* data;
        ml_Elm_Gengrid_Item_Class(&class, &data, v_class);

        value* data_func = ml_register_value(v_func);

        Elm_Object_Item* item = elm_gengrid_item_insert_after(
                (Evas_Object*) v_obj, class, data, (Elm_Object_Item*) v_rel,
                ml_Evas_Smart_Cb, data_func);
        elm_gengrid_item_class_free(class);

        if(item == NULL) {
                ml_remove_value(data);
                ml_remove_value(data_func);
                caml_failwith("elm_gengrid_item_insert_after");
        }
        ml_Elm_Object_Item_gc_value(item, data_func);
        return (value) item;
}

PREFIX value ml_elm_gengrid_selected_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_gengrid_selected_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_gengrid_selected_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_gengrid_selected_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_gengrid_realized_items_get(value v_obj)
{
        Eina_List* list = elm_gengrid_realized_items_get((Evas_Object*) v_obj);
        value v = copy_Eina_List_Elm_Object_Item(list);
        eina_list_free(list);
        return v;
}

PREFIX value ml_elm_gengrid_first_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_gengrid_first_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_gengrid_last_item_get(value v_obj)
{
        Elm_Object_Item* item = elm_gengrid_last_item_get(
                (Evas_Object*) v_obj);
        if(item == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) item);
        return v;
}

PREFIX value ml_elm_gengrid_item_next_get(value v_it)
{
        Elm_Object_Item* next = elm_gengrid_item_next_get(
                (Elm_Object_Item*) v_it);
        if(next == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) next);
        return v;
}

PREFIX value ml_elm_gengrid_item_prev_get(value v_it)
{
        Elm_Object_Item* prev = elm_gengrid_item_prev_get(
                (Elm_Object_Item*) v_it);
        if(prev == NULL) return Val_int(0);
        value v = caml_alloc(1, 0);
        Store_field(v, 0, (value) prev);
        return v;
}

PREFIX value ml_elm_gengrid_item_tooltip_content_cb_set(
        value v_it, value v_func, value v_del_cb)
{
        CAMLparam3(v_it, v_func, v_del_cb);
        value* data = caml_stat_alloc(sizeof(value));
        *data = caml_alloc(2, 0);
        Store_field(*data, 0, v_func);
        Store_field(*data, 1, v_del_cb);
        caml_register_generational_global_root(data);
        elm_gengrid_item_tooltip_content_cb_set((Elm_Object_Item*) v_it,
                ml_Elm_Tooltip_Item_Content_Cb_0, data,
                ml_Evas_Smart_Cb_1_free);
        CAMLreturn(Val_unit);
}
PREFIX value ml_elm_gengrid_item_cursor_get(value v_it)
{
        CAMLparam1(v_it);
        CAMLlocal1(v_cursor);
        const char* cursor =
                elm_gengrid_item_cursor_get((Elm_Object_Item*) v_it);
        if(cursor == NULL) v_cursor = Val_int(0);
        else {
                v_cursor = caml_alloc(1, 0);
                Store_field(v_cursor, 0, copy_string(cursor));
        }
        CAMLreturn(v_cursor);
}

PREFIX value ml_elm_gengrid_item_cursor_style_get(value v_it)
{
        CAMLparam1(v_it);
        CAMLlocal1(v_style);
        const char* style =
                elm_gengrid_item_cursor_style_get((Elm_Object_Item*) v_it);
        if(style == NULL) v_style = Val_int(0);
        else {
                v_style = caml_alloc(1, 0);
                Store_field(v_style, 0, copy_string(style));
        }
        CAMLreturn(v_style);
}

PREFIX value ml_elm_gengrid_item_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_gengrid_item_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_gengrid_group_item_size_get(value v_obj)
{
        Evas_Coord w, h;
        elm_gengrid_group_item_size_get((Evas_Object*) v_obj, &w, &h);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(w));
        Store_field(v_r, 1, Val_int(h));
        return v_r;
}

PREFIX value ml_elm_gengrid_align_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_r);
        double x, y;
        elm_gengrid_align_get((Evas_Object*) v_obj, &x, &y);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(x));
        Store_field(v_r, 1, copy_double(y));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_gengrid_item_pos_get(value v_it)
{
        unsigned int x, y;
        elm_gengrid_item_pos_get((Elm_Object_Item*) v_it, &x, &y);
        value v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, Val_int(x));
        Store_field(v_r, 1, Val_int(y));
        return v_r;
}

PREFIX value ml_elm_gengrid_nth_item_get(value v_obj, value v_k)
{
        Elm_Object_Item* it = elm_gengrid_nth_item_get((Evas_Object*) v_obj,
                Int_val(v_k));
        if(it == NULL) return Val_int(0);
        value v_r = caml_alloc(1, 0);
        Store_field(v_r, 0, (value) it);
        return v_r;
}

