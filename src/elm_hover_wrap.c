#include "include.h"

PREFIX value ml_elm_hover_add(value v_parent)
{
        Evas_Object* obj = elm_hover_add(Evas_Object_val(v_parent));
        if(obj == NULL) caml_failwith("elm_hover_add");
        return copy_Evas_Object(obj);
}

PREFIX value ml_elm_hover_target_get(value v_obj)
{
        Evas_Object* target = elm_hover_target_get(Evas_Object_val(v_obj));
        if(target == NULL) caml_failwith("elm_hover_target_get");
        return copy_Evas_Object(target);
}

PREFIX value ml_elm_hover_parent_get(value v_obj)
{
        Evas_Object* parent = elm_hover_parent_get(Evas_Object_val(v_obj));
        if(parent == NULL) caml_failwith("elm_hover_parent_get");
        return copy_Evas_Object(parent);
}

PREFIX value ml_elm_hover_best_content_location_get(value v_obj, value v_axis)
{
        CAMLparam2(v_obj, v_axis);
        CAMLlocal1(v_loc);
        const char* loc = elm_hover_best_content_location_get(
                Evas_Object_val(v_obj), Elm_Hover_Axis_val(v_axis));
        if(loc == NULL) v_loc = Val_int(0);
        else {
                v_loc = caml_alloc(1, 0);
                Store_field(v_loc, 0, copy_string(loc));
        }
        CAMLreturn(v_loc);
}

