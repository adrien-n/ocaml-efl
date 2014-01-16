#include "include.h"

PREFIX value ml_elm_hoversel_add(value v_parent)
{
        Evas_Object* obj = elm_hoversel_add((Evas_Object*) v_parent);
        if(obj == NULL) caml_failwith("elm_hoversel_add");
        return (value) obj;
}

PREFIX value ml_elm_hoversel_horizontal_set(value v_box, value v_flag)
{
        elm_hoversel_horizontal_set((Evas_Object*) v_box, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_hoversel_horizontal_get(value v_obj)
{
        return Val_bool(elm_hoversel_horizontal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_hoversel_hover_parent_set(value v_obj, value v_parent)
{
        elm_hoversel_hover_parent_set((Evas_Object*) v_obj,
                (Evas_Object*) v_parent);
        return Val_unit;
}

PREFIX value ml_elm_hoversel_hover_parent_get(value v_obj)
{
        return (value) elm_hoversel_hover_parent_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_hoversel_hover_begin(value v_obj)
{
        elm_hoversel_hover_begin((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_hoversel_hover_end(value v_obj)
{
        elm_hoversel_hover_end((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_hoversel_expanded_get(value v_obj)
{
        return Val_bool(elm_hoversel_expanded_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_hoversel_clear(value v_obj)
{
        elm_hoversel_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_hoversel_items_get(value v_obj)
{
        return copy_Eina_List_Elm_Object_Item(elm_hoversel_items_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_hoversel_item_add(
        value v_obj, value v_label, value v_icon, value v_func, value v_unit)
{
        const char* label;
        if(v_label == Val_int(0)) label = NULL;
        else label = String_val(Field(v_label, 0));
        const char* icon_file;
        Elm_Icon_Type icon_type;
        if(v_icon == Val_int(0)) {
                icon_file = NULL;
                icon_type = 0;
        } else {
                value v = Field(v_icon, 0);
                icon_file = String_val(Field(v, 0));
                icon_type = Elm_Icon_Type_val(Field(v, 1));
        }
        Evas_Smart_Cb func;
        value* data;
        if(v_func == Val_int(0)) {
                func = NULL;
                data = NULL;
        } else {
                func = ml_Evas_Smart_Cb;
                data = (value*) caml_stat_alloc(sizeof(value));
                *data = Field(v_func, 0);
                caml_register_global_root(data);
        }
        Elm_Object_Item* item = elm_hoversel_item_add((Evas_Object*) v_obj,
                label, icon_file, icon_type, func, data);
        if(item == NULL) {
                if(data != NULL) {
                        caml_remove_global_root(data);
                        free(data);
                }
                caml_failwith("elm_hoversel_item_add");
        }
        return (value) item;
}

