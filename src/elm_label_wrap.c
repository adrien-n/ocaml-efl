#include "include.h"

PREFIX value ml_elm_label_add(value v_parent)
{
        Evas_Object* lb = elm_label_add((Evas_Object*) v_parent);
        if(lb == NULL) caml_failwith("elm_label_add");
        return (value) lb;
}

PREFIX value ml_elm_label_line_wrap_set(value v_obj, value v_wrap)
{
        elm_label_line_wrap_set((Evas_Object*) v_obj,
                Elm_Wrap_Type_val(v_wrap));
        return Val_unit;
}

PREFIX value ml_elm_label_line_wrap_get(value v_obj)
{
        return Val_Elm_Wrap_Type(elm_label_line_wrap_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_label_wrap_width_set(value v_obj, value v_w)
{
        elm_label_wrap_width_set((Evas_Object*) v_obj, Int_val(v_w));
        return Val_unit;
}

PREFIX value ml_elm_label_wrap_width_get(value v_obj)
{
        return Val_int(elm_label_wrap_width_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_label_ellipsis_set(value v_obj, value v_ellipsis)
{
        elm_label_ellipsis_set((Evas_Object*) v_obj, Eina_Bool_val(v_ellipsis));
        return Val_unit;
}

PREFIX value ml_elm_label_ellipsis_get(value v_obj)
{
        return Val_Eina_Bool(elm_label_ellipsis_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_label_slide_mode_set(value v_obj, value v_slide)
{
        elm_label_slide_mode_set((Evas_Object*) v_obj, Eina_Bool_val(v_slide));
        return Val_unit;
}

PREFIX value ml_elm_label_slide_mode_get(value v_obj)
{
        return Val_Eina_Bool(elm_label_slide_mode_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_label_slide_duration_set(value v_label, value v_d)
{
        elm_label_slide_duration_set((Evas_Object*) v_label, Double_val(v_d));
        return Val_unit;
}

PREFIX value ml_elm_label_slide_duration_get(value v_label)
{
        return copy_double(elm_label_slide_duration_get(
                (Evas_Object*) v_label));
}

PREFIX value ml_elm_label_slide_speed_set(value v_label, value v_d)
{
        elm_label_slide_speed_set((Evas_Object*) v_label, Double_val(v_d));
        return Val_unit;
}

PREFIX value ml_elm_label_slide_speed_get(value v_label)
{
        return copy_double(elm_label_slide_speed_get(
                (Evas_Object*) v_label));
}

PREFIX value ml_elm_label_slide_go(value v_obj)
{
        elm_label_slide_go((Evas_Object*) v_obj);
        return Val_unit;
}

