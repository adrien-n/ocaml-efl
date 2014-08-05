#include "include.h"

void ml_Elm_Transit_Effect_Transition_Cb(
        Elm_Transit_Effect* effect, Elm_Transit* tr, double progress)
{
        CAMLparam0();
        CAMLlocal1(v_progress);
        value* v_fun = (value*) effect;
        v_progress = copy_double(progress);
        caml_callback2(*v_fun, (value) tr, v_progress);
        CAMLreturn0;
}

void ml_Elm_Transit_Effect_End_Cb_free_only(
        Elm_Transit_Effect* effect, Elm_Transit* tr)
{
        value* v_fun = (value*) effect;
        ml_remove_value(v_fun);
}

void ml_Elm_Transit_Del_Cb(void* data, Elm_Transit* tr)
{
        value* v_fun = (value*) data;
        caml_callback(*v_fun, (value) tr);
        ml_remove_value(v_fun);
}

inline value copy_Eina_List_Elm_Transit(const Eina_List* list)
{
        CAMLparam0();
        CAMLlocal2(v, v1);
        Eina_List* it;
        Elm_Transit* obj;
        v = Val_int(0);
        EINA_LIST_REVERSE_FOREACH(list, it, obj) {
                v1 = v;
                v = caml_alloc(2, 0);
                Store_field(v, 0, (value) obj);
                Store_field(v, 1, v1);
        }
        CAMLreturn(v);
}

PREFIX value ml_elm_transit_add(value v_unit)
{
        Elm_Transit* tr = elm_transit_add();
        if(tr == NULL) caml_failwith("elm_transit_add");
        return (value) tr;
}

PREFIX value ml_elm_transit_effect_add(value v_tr, value v_fun)
{
        CAMLparam2(v_tr, v_fun);
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        elm_transit_effect_add((Elm_Transit*) v_tr,
                ml_Elm_Transit_Effect_Transition_Cb, data,
                ml_Elm_Transit_Effect_End_Cb_free_only);
        CAMLreturn(Val_unit);
}

PREFIX value ml_elm_transit_objects_get(value v_tr)
{
        return copy_Eina_List_Evas_Object(elm_transit_objects_get(
                (Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_del_cb_set(value v_tr, value v_fun)
{
        value* data = ml_register_value(v_fun);
        elm_transit_del_cb_set((Elm_Transit*) v_tr, ml_Elm_Transit_Del_Cb,
                data);
        return Val_unit;
}

PREFIX value ml_elm_transit_tween_mode_factor_get(value v_tr)
{
        CAMLparam1(v_tr);
        CAMLlocal1(v_r);
        double v1, v2;
        elm_transit_tween_mode_factor_get((Elm_Transit*) v_tr, &v1, &v2);
        v_r = caml_alloc(2, 0);
        Store_field(v_r, 0, copy_double(v1));
        Store_field(v_r, 1, copy_double(v2));
        CAMLreturn(v_r);
}

PREFIX value ml_elm_transit_chain_transits_get(value v_tr)
{
        return copy_Eina_List_Elm_Transit(elm_transit_chain_transits_get(
                (Elm_Transit*) v_tr));
}

PREFIX value ml_elm_transit_effect_image_animation_add(value v_tr, value v_list)
{
        elm_transit_effect_image_animation_add((Elm_Transit*) v_tr,
                Eina_List_string_val(v_list));
        return Val_unit;
}

