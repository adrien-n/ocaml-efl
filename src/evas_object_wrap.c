#include "evas_object_wrap.h"

PREFIX value ml_evas_object_smart_callback_add(
        value v_obj, value v_event, value v_func)
{
        CAMLparam3(v_obj, v_event, v_func);
        Evas_Object* obj = (Evas_Object*) v_obj;
        value* data = ml_Evas_Object_register_value(obj, v_func);
        const char* event = String_val(v_event);
        evas_object_smart_callback_add(obj, event, ml_Evas_Smart_Cb, data);
        CAMLreturn(Val_unit);
}

PREFIX value ml_evas_object_rectangle_add(value v_e)
{
        return (value) evas_object_rectangle_add((Evas*) v_e);
}

PREFIX void ml_Evas_Object_Box_Layout_0(
        Evas_Object* obj, Evas_Object_Box_Data* priv, void* user_data)
{
        CAMLparam0();
        CAMLlocal1(v_fun);
        value* v_user_data = (value*) user_data;
        v_fun = Field(*v_user_data, 0);
        caml_callback2(v_fun, (value) obj, (value) priv);
        CAMLreturn0;
}

PREFIX value ml_evas_object_box_layout_flow_horizontal(
        value v_obj, value v_priv)
{
        evas_object_box_layout_flow_horizontal((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_horizontal(
        value v_obj, value v_priv)
{
        evas_object_box_layout_horizontal((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_vertical(
        value v_obj, value v_priv)
{
        evas_object_box_layout_vertical((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_homogeneous_vertical(
        value v_obj, value v_priv)
{
        evas_object_box_layout_homogeneous_vertical((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_homogeneous_horizontal(
        value v_obj, value v_priv)
{
        evas_object_box_layout_homogeneous_horizontal((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_flow_vertical(
        value v_obj, value v_priv)
{
        evas_object_box_layout_flow_vertical((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

PREFIX value ml_evas_object_box_layout_stack(
        value v_obj, value v_priv)
{
        evas_object_box_layout_stack((Evas_Object*) v_obj,
                (Evas_Object_Box_Data*) v_priv, NULL);
        return Val_unit;
}

void ml_Evas_Object_Event_Cb_on_del(
        void* data, Evas* e, Evas_Object* obj, void* event_info)
{
        value* v_fun = (value*) data;
        ml_remove_value(v_fun);
}

inline value* ml_Evas_Object_register_value(Evas_Object* obj, value v)
{
        value* data = ml_register_value(v);
        evas_object_event_callback_add(obj, EVAS_CALLBACK_FREE,
                ml_Evas_Object_Event_Cb_on_del, data);
        return data;
}

inline void ml_Evas_Object_gc_value(Evas_Object* obj, value* data)
{
        evas_object_event_callback_add(obj, EVAS_CALLBACK_FREE,
                ml_Evas_Object_Event_Cb_on_del, data);
}

/* Basic Object Manipulation */

PREFIX value ml_evas_object_clip_set(value v_obj, value v_clip)
{
        evas_object_clip_set((Evas_Object*) v_obj, (Evas_Object*) v_clip);
        return Val_unit;
}

PREFIX value ml_evas_object_ref(value v_obj)
{
        evas_object_ref((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_unref(value v_obj)
{
        evas_object_unref((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_ref_get(value v_obj)
{
        return Val_int(evas_object_ref_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_del(value v_obj)
{
        evas_object_del((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_move(value v_obj, value v_x, value v_y)
{
        evas_object_move((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_resize(value v_obj, value v_x, value v_y)
{
        evas_object_resize((Evas_Object*) v_obj, Int_val(v_x), Int_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_geometry_get(value v_obj)
{
        Evas_Coord x, y, w, h;
        evas_object_geometry_get((Evas_Object*) v_obj, &x, &y, &w, &h);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(w));
        Store_field(v, 3, Val_int(h));
        return v;
}

PREFIX value ml_evas_object_geometry_set(
        value v_obj, value v_x, value v_y, value v_w, value v_h)
{
        evas_object_geometry_set((Evas_Object*) v_obj, Int_val(v_x),
                Int_val(v_y), Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_object_show(value v_obj)
{
        evas_object_show((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_hide(value v_obj)
{
        evas_object_hide((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_visible_get(value v_obj)
{
        return Val_Eina_Bool(evas_object_visible_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_color_set(
        value v_obj, value v_r, value v_g, value v_b, value v_a)
{
        evas_object_color_set((Evas_Object*) v_obj, Int_val(v_r), Int_val(v_g),
                Int_val(v_b), Int_val(v_a));
        return Val_unit;
}

PREFIX value ml_evas_object_color_get(value v_obj)
{
        int r, g, b, a;
        evas_object_color_get((Evas_Object*) v_obj, &r, &g, &b, &a);
        value v_r = caml_alloc(4, 0);
        Store_field(v_r, 0, Val_int(r));
        Store_field(v_r, 1, Val_int(g));
        Store_field(v_r, 2, Val_int(b));
        Store_field(v_r, 3, Val_int(a));
        return v_r;
}

PREFIX value ml_evas_object_evas_get(value v_obj)
{
        return (value) evas_object_evas_get((Evas_Object*) v_obj);
}

PREFIX value ml_evas_object_clip_get(value v_obj)
{
        return copy_Evas_Object_opt(evas_object_clip_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_clip_unset(value v_obj)
{
        evas_object_clip_unset((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_clipees_get(value v_obj)
{
        return copy_Eina_List_Evas_Object(evas_object_clipees_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_clipees_has(value v_obj)
{
        return Val_bool(evas_object_clipees_has((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_focus_set(value v_obj, value v_flag)
{
        evas_object_focus_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_object_focus_get(value v_obj)
{
        return Val_bool(evas_object_focus_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_layer_set(value v_obj, value v_l)
{
        evas_object_layer_set((Evas_Object*) v_obj, Int_val(v_l));
        return Val_unit;
}

PREFIX value ml_evas_object_layer_get(value v_obj)
{
        return Val_int(evas_object_layer_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_name_set(value v_obj, value v_s)
{
        evas_object_name_set((Evas_Object*) v_obj, String_val(v_s));
        return Val_unit;
}

PREFIX value ml_evas_object_name_get(value v_obj)
{
        return copy_string(evas_object_name_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_type_get(value v_obj)
{
        return copy_string(evas_object_type_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_raise(value v_obj)
{
        evas_object_raise((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_lower(value v_obj)
{
        evas_object_lower((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_evas_object_stack_above(value v_obj, value v_above)
{
        evas_object_stack_above((Evas_Object*) v_obj, (Evas_Object*) v_above);
        return Val_unit;
}

PREFIX value ml_evas_object_stack_below(value v_obj, value v_below)
{
        evas_object_stack_below((Evas_Object*) v_obj, (Evas_Object*) v_below);
        return Val_unit;
}

PREFIX value ml_evas_object_above_get(value v_obj)
{
        return copy_Evas_Object_opt(evas_object_above_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_below_get(value v_obj)
{
        return copy_Evas_Object_opt(evas_object_below_get(
                (Evas_Object*) v_obj));
}

/* UV Mapping */

PREFIX value ml_evas_object_map_enable_set(value v_obj, value v_flag)
{
        evas_object_map_enable_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_object_map_enable_get(value v_obj)
{
        return Val_bool(evas_object_map_enable_get((Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_map_set(value v_obj, value v_m)
{
        evas_object_map_set((Evas_Object*) v_obj, (Evas_Map*) v_m);
        return Val_unit;
}

PREFIX value ml_evas_object_map_get(value v_obj)
{
        const Evas_Map* m = evas_object_map_get((Evas_Object*) v_obj);
        if(m == NULL) caml_failwith("evas_object_map_get");
        return (value) m;
}

/* Size Hints */

inline Evas_Display_Mode Evas_Display_Mode_val(value v)
{
        switch(v) {
                case Val_none: return EVAS_DISPLAY_MODE_NONE;
                case Val_compress: return EVAS_DISPLAY_MODE_COMPRESS;
                case Val_expand: return EVAS_DISPLAY_MODE_EXPAND;
                case Val_dont_change: return EVAS_DISPLAY_MODE_DONT_CHANGE;
        }
        caml_failwith("Evas_Display_Mode_val");
        return EVAS_DISPLAY_MODE_NONE;
}

inline value Val_Evas_Display_Mode(Evas_Display_Mode m)
{
        switch(m) {
                case EVAS_DISPLAY_MODE_NONE: return Val_none;
                case EVAS_DISPLAY_MODE_COMPRESS: return Val_compress;
                case EVAS_DISPLAY_MODE_EXPAND: return Val_expand;
                case EVAS_DISPLAY_MODE_DONT_CHANGE: return Val_dont_change;
        }
        caml_failwith("Val_Evas_Display_Mode");
        return Val_none;
}

PREFIX value ml_evas_object_size_hint_min_get(value v_obj)
{
        Evas_Coord w, h;
        evas_object_size_hint_min_get((Evas_Object*) v_obj, &w, &h);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(w));
        Store_field(v, 1, Val_int(h));
        return v;
}

PREFIX value ml_evas_object_size_hint_min_set(value v_obj, value v_w, value v_h)
{
        evas_object_size_hint_min_set((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_max_get(value v_obj)
{
        Evas_Coord w, h;
        evas_object_size_hint_max_get((Evas_Object*) v_obj, &w, &h);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(w));
        Store_field(v, 1, Val_int(h));
        return v;
}

PREFIX value ml_evas_object_size_hint_max_set(value v_obj, value v_w, value v_h)
{
        evas_object_size_hint_max_set((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_display_mode_get(value v_obj)
{
        return Val_Evas_Display_Mode(evas_object_size_hint_display_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_size_hint_display_mode_set(value v_obj, value v_m)
{
        evas_object_size_hint_display_mode_set((Evas_Object*) v_obj,
                Evas_Display_Mode_val(v_m));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_request_get(value v_obj)
{
        Evas_Coord w, h;
        evas_object_size_hint_request_get((Evas_Object*) v_obj, &w, &h);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(w));
        Store_field(v, 1, Val_int(h));
        return v;
}

PREFIX value ml_evas_object_size_hint_request_set(
        value v_obj, value v_w, value v_h)
{
        evas_object_size_hint_request_set((Evas_Object*) v_obj, Int_val(v_w),
                Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_aspect_get(value v_obj)
{
        Evas_Aspect_Control ac;
        Evas_Coord w, h;
        evas_object_size_hint_aspect_get((Evas_Object*) v_obj, &ac, &w, &h);
        value v = caml_alloc(3, 0);
        Store_field(v, 0, Val_Evas_Aspect_Control(ac));
        Store_field(v, 1, Val_int(w));
        Store_field(v, 2, Val_int(h));
        return v;
}

PREFIX value ml_evas_object_size_hint_aspect_set(
        value v_obj, value v_aspect, value v_w, value v_h)
{
        evas_object_size_hint_aspect_set((Evas_Object*) v_obj,
                Evas_Aspect_Control_val(v_aspect), Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_align_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        double x, y;
        evas_object_size_hint_align_get((Evas_Object*) v_obj, &x, &y);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_double(x));
        Store_field(v, 1, copy_double(y));
        CAMLreturn(v);
}

PREFIX value ml_evas_object_size_hint_align_set(
        value v_obj, value v_x, value v_y)
{
        evas_object_size_hint_align_set((Evas_Object*) v_obj, Double_val(v_x),
                Double_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_weight_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        double x, y;
        evas_object_size_hint_weight_get((Evas_Object*) v_obj, &x, &y);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_double(x));
        Store_field(v, 1, copy_double(y));
        CAMLreturn(v);
}

PREFIX value ml_evas_object_size_hint_weight_set(
        value v_obj, value v_x, value v_y)
{
        evas_object_size_hint_weight_set((Evas_Object*) v_obj, Double_val(v_x),
                Double_val(v_y));
        return Val_unit;
}

PREFIX value ml_evas_object_size_hint_padding_get(value v_obj)
{
        Evas_Coord l, r, t, b;
        evas_object_size_hint_padding_get((Evas_Object*) v_obj, &l, &r, &t, &b);
        value v = caml_alloc(4, 0);
        Store_field(v_obj, 0, Val_int(l));
        Store_field(v_obj, 1, Val_int(r));
        Store_field(v_obj, 2, Val_int(t));
        Store_field(v_obj, 3, Val_int(b));
        return v;
}

PREFIX value ml_evas_object_size_hint_padding_set(
        value v_obj, value v_l, value v_r, value v_t, value v_b)
{
        evas_object_size_hint_padding_set((Evas_Object*) v_obj, Int_val(v_l),
                Int_val(v_r), Int_val(v_t), Int_val(v_b));
        return Val_unit;
}

/* Extra Object Manipulation */

inline Evas_Object_Pointer_Mode Evas_Object_Pointer_Mode_val(value v)
{
        switch(v) {
                case Val_autograb: return EVAS_OBJECT_POINTER_MODE_AUTOGRAB;
                case Val_nograb: return EVAS_OBJECT_POINTER_MODE_NOGRAB;
                case Val_nograb_no_repeat_updown:
                        return EVAS_OBJECT_POINTER_MODE_NOGRAB_NO_REPEAT_UPDOWN;
        }
        caml_failwith("Evas_Object_Pointer_Mode_val");
        return EVAS_OBJECT_POINTER_MODE_AUTOGRAB;
}

inline value Val_Evas_Object_Pointer_Mode(Evas_Object_Pointer_Mode m)
{
        switch(m) {
                case EVAS_OBJECT_POINTER_MODE_AUTOGRAB: return Val_autograb;
                case EVAS_OBJECT_POINTER_MODE_NOGRAB: return Val_nograb;
                case EVAS_OBJECT_POINTER_MODE_NOGRAB_NO_REPEAT_UPDOWN:
                        return Val_nograb_no_repeat_updown;
        }
        caml_failwith("Val_Evas_Object_Pointer_Mode");
        return Val_autograb;
}

PREFIX value ml_evas_object_pointer_mode_set(value v_obj, value v_m)
{
        evas_object_pointer_mode_set((Evas_Object*) v_obj,
                Evas_Object_Pointer_Mode_val(v_m));
        return Val_unit;
}

PREFIX value ml_evas_object_pointer_mode_get(value v_obj)
{
        return Val_Evas_Object_Pointer_Mode(evas_object_pointer_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_evas_object_anti_alias_set(value v_obj, value v_flag)
{
        evas_object_anti_alias_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_evas_object_anti_alias_get(value v_obj)
{
        return Val_bool(evas_object_anti_alias_get((Evas_Object*) v_obj));
}

