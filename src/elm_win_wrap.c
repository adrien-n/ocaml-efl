#include "include.h"

PREFIX value ml_elm_win_add(value v_parent, value v_name, value v_ty)
{
        Evas_Object* parent;
        if(v_parent == Val_int(0)) parent = NULL;
        else parent = (Evas_Object*) Field(v_parent, 0);
        Evas_Object* win = elm_win_add(parent, String_val(v_name),
                Elm_Win_Type_val(v_ty));
        if(win == NULL) caml_failwith("elm_win_add");
        return (value) win;
}

PREFIX value ml_elm_win_util_standard_add(value v_name, value v_title)
{
        Evas_Object* obj = elm_win_util_standard_add(String_val(v_name),
                String_val(v_title));
        if(obj == NULL) caml_failwith("elm_win_util_standard_add");
        return (value) obj;
}

PREFIX value ml_elm_win_resize_object_add(value v_obj, value v_subobj)
{
        elm_win_resize_object_add((Evas_Object*) v_obj,
                (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_win_resize_object_del(value v_obj, value v_subobj)
{
        elm_win_resize_object_del((Evas_Object*) v_obj,
                (Evas_Object*) v_subobj);
        return Val_unit;
}

PREFIX value ml_elm_win_title_set(value v_obj, value v_title)
{
        elm_win_title_set((Evas_Object*) v_obj, String_val(v_title));
        return Val_unit;
}

PREFIX value ml_elm_win_title_get(value v_obj)
{
        return copy_string(elm_win_title_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_icon_name_set(value v_obj, value v_name)
{
        elm_win_icon_name_set((Evas_Object*) v_obj, String_val(v_name));
        return Val_unit;
}

PREFIX value ml_elm_win_icon_name_get(value v_obj)
{
        return copy_string(elm_win_icon_name_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_role_set(value v_obj, value v_role)
{
        elm_win_role_set((Evas_Object*) v_obj, String_val(v_role));
        return Val_unit;
}

PREFIX value ml_elm_win_role_get(value v_obj)
{
        return copy_string(elm_win_role_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_icon_object_set(value v_obj, value v_icon)
{
        elm_win_icon_object_set((Evas_Object*) v_obj, (Evas_Object*) v_icon);
        return Val_unit;
}

PREFIX value ml_elm_win_icon_object_get(value v_obj)
{
        return (value) elm_win_icon_object_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_win_autodel_set(value v_win, value v_flag)
{
        elm_win_autodel_set((Evas_Object*) v_win, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_autodel_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_autodel_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_activate(value v_obj)
{
        elm_win_activate((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_lower(value v_obj)
{
        elm_win_lower((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_raise(value v_obj)
{
        elm_win_raise((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_center(value v_obj, value v_h, value v_v)
{
        elm_win_center((Evas_Object*) v_obj, Eina_Bool_val(v_h),
                Eina_Bool_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_win_borderless_set(value v_obj, value v_flag)
{
        elm_win_borderless_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_borderless_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_borderless_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_shaped_set(value v_obj, value v_flag)
{
        elm_win_shaped_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_shaped_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_shaped_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_alpha_set(value v_obj, value v_flag)
{
        elm_win_alpha_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_alpha_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_alpha_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_override_set(value v_obj, value v_flag)
{
        elm_win_override_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_override_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_override_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_fullscreen_set(value v_obj, value v_flag)
{
        elm_win_fullscreen_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_fullscreen_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_fullscreen_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_main_menu_get(value v_obj)
{
        return copy_Evas_Object_opt(elm_win_main_menu_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_maximized_set(value v_obj, value v_flag)
{
        elm_win_maximized_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_maximized_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_maximized_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_iconified_set(value v_obj, value v_flag)
{
        elm_win_iconified_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_iconified_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_iconified_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_withdrawn_set(value v_obj, value v_flag)
{
        elm_win_withdrawn_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_withdrawn_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_withdrawn_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_available_profiles_set(value v_obj, value v_profiles)
{
        int size = Wosize_val(v_profiles);
        char* profiles[size];
        int i;
        for(i = 0; i < size; i++) {
                profiles[i] = String_val(Field(v_profiles, i));
        }
        elm_win_available_profiles_set((Evas_Object*) v_obj,
                (const char**) profiles, size);
        return Val_unit;
}

PREFIX value ml_elm_win_available_profiles_get(value v_obj)
{
        CAMLparam1(v_obj);
        CAMLlocal1(v_profiles);
        unsigned int size;
        char** profiles;
        if(!elm_win_available_profiles_get((Evas_Object*) v_obj, &profiles,
                &size))
                size = 0;
        v_profiles = caml_alloc(size, 0);
        unsigned int i;
        for(i = 0; i < size; i++) {
                Store_field(v_profiles, i, copy_string(profiles[i]));
        }
        CAMLreturn(v_profiles);
}

PREFIX value ml_elm_win_profile_set(value v_obj, value v_profile)
{
        elm_win_profile_set((Evas_Object*) v_obj, String_val(v_profile));
        return Val_unit;
}

PREFIX value ml_elm_win_profile_get(value v_obj)
{
        const char* profile = elm_win_profile_get((Evas_Object*) v_obj);
        if(profile == NULL) profile = "";
        return copy_string(profile);
}

PREFIX value ml_elm_win_urgent_set(value v_obj, value v_flag)
{
        elm_win_urgent_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_urgent_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_urgent_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_demand_attention_set(value v_obj, value v_flag)
{
        elm_win_demand_attention_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_demand_attention_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_demand_attention_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_modal_set(value v_obj, value v_flag)
{
        elm_win_modal_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_modal_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_modal_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_aspect_set(value v_obj, value v_r)
{
        elm_win_aspect_set((Evas_Object*) v_obj, Double_val(v_r));
        return Val_unit;
}

PREFIX value ml_elm_win_aspect_get(value v_obj)
{
        return copy_double(elm_win_aspect_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_size_base_set(value v_obj, value v_w, value v_h)
{
        elm_win_size_base_set((Evas_Object*) v_obj, Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_win_size_base_get(value v_obj)
{
        int w, h;
        elm_win_size_base_get((Evas_Object*) v_obj, &w, &h);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(w));
        Store_field(v, 1, Val_int(h));
        return v;
}

PREFIX value ml_elm_win_size_step_set(value v_obj, value v_w, value v_h)
{
        elm_win_size_step_set((Evas_Object*) v_obj, Int_val(v_w), Int_val(v_h));
        return Val_unit;
}

PREFIX value ml_elm_win_size_step_get(value v_obj)
{
        int w, h;
        elm_win_size_step_get((Evas_Object*) v_obj, &w, &h);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(w));
        Store_field(v, 1, Val_int(h));
        return v;
}

PREFIX value ml_elm_win_layer_set(value v_obj, value v_n)
{
        elm_win_layer_set((Evas_Object*) v_obj, Int_val(v_n));
        return Val_unit;
}

PREFIX value ml_elm_win_layer_get(value v_obj)
{
        return Val_int(elm_win_layer_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_norender_push(value v_obj)
{
        elm_win_norender_push((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_norender_pop(value v_obj)
{
        elm_win_norender_pop((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_norender_get(value v_obj)
{
        return Val_int(elm_win_norender_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_render(value v_obj)
{
        elm_win_render((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_win_rotation_set(value v_obj, value v_rot)
{
        elm_win_rotation_set((Evas_Object*) v_obj, Int_val(v_rot));
        return Val_unit;
}

PREFIX value ml_elm_win_rotation_with_resize_set(value v_obj, value v_rot)
{
        elm_win_rotation_with_resize_set((Evas_Object*) v_obj, Int_val(v_rot));
        return Val_unit;
}

PREFIX value ml_elm_win_rotation_get(value v_obj)
{
        return Val_int(elm_win_rotation_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_sticky_set(value v_obj, value v_flag)
{
        elm_win_sticky_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_sticky_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_sticky_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_conformant_set(value v_obj, value v_flag)
{
        elm_win_conformant_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_conformant_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_conformant_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_quickpanel_set(value v_obj, value v_flag)
{
        elm_win_quickpanel_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_quickpanel_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_quickpanel_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_quickpanel_priority_major_set(value v_obj, value v_n)
{
        elm_win_quickpanel_priority_major_set((Evas_Object*) v_obj,
                Int_val(v_n));
        return Val_unit;
}

PREFIX value ml_elm_win_quickpanel_priority_major_get(value v_obj)
{
        return Val_int(elm_win_quickpanel_priority_major_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_quickpanel_priority_minor_set(value v_obj, value v_n)
{
        elm_win_quickpanel_priority_minor_set((Evas_Object*) v_obj,
                Int_val(v_n));
        return Val_unit;
}

PREFIX value ml_elm_win_quickpanel_priority_minor_get(value v_obj)
{
        return Val_int(elm_win_quickpanel_priority_minor_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_quickpanel_zone_set(value v_obj, value v_n)
{
        elm_win_quickpanel_zone_set((Evas_Object*) v_obj, Int_val(v_n));
        return Val_unit;
}

PREFIX value ml_elm_win_quickpanel_zone_get(value v_obj)
{
        return Val_int(elm_win_quickpanel_zone_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_prop_focus_skip_set(value v_obj, value v_flag)
{
        elm_win_prop_focus_skip_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_illume_command_send(value v_obj, value v_cmd)
{
        elm_win_illume_command_send((Evas_Object*) v_obj,
                Elm_Illume_Command_val(v_cmd), NULL);
        return Val_unit;
}

PREFIX value ml_elm_win_inlined_image_object_get(value v_obj)
{
        Evas_Object* obj = elm_win_inlined_image_object_get(
                (Evas_Object*) v_obj);
        if(obj == NULL) caml_failwith("elm_win_inlined_image_object_get");
        return (value) obj;
}

PREFIX value ml_elm_win_focus_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_focus_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_screen_constrain_set(value v_obj, value v_flag)
{
        elm_win_screen_constrain_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_screen_constrain_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_screen_constrain_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_screen_size_get(value v_obj)
{
        int x, y, w, h;
        elm_win_screen_size_get((Evas_Object*) v_obj, &x, &y, &w, &h);
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(w));
        Store_field(v, 3, Val_int(h));
        return v;
}

PREFIX value ml_elm_win_screen_dpi_get(value v_obj)
{
        int x, y;
        elm_win_screen_dpi_get((Evas_Object*) v_obj, &x, &y);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        return v;
}

PREFIX value ml_elm_win_focus_highlight_enabled_set(value v_obj, value v_flag)
{
        elm_win_focus_highlight_enabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_focus_highlight_enabled_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_focus_highlight_enabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_focus_highlight_style_set(value v_obj, value v_s)
{
        const char* style;
        if(v_s == Val_int(0)) style = NULL;
        else style = String_val(Field(v_s, 0));
        elm_win_focus_highlight_style_set((Evas_Object*) v_obj, style);
        return Val_unit;
}

PREFIX value ml_elm_win_focus_highlight_style_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* style = elm_win_focus_highlight_style_get(
                (Evas_Object*) v_obj);
        if(style == NULL) v = Val_int(0);
        else {
                v = caml_alloc(1, 0);
                Store_field(v, 0, copy_string(style));
        }
        CAMLreturn(v);
}

PREFIX value ml_elm_win_focus_highlight_animate_set(value v_obj, value v_flag)
{
        elm_win_focus_highlight_animate_set((Evas_Object*) v_obj,
                Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_focus_highlight_animate_get(value v_obj)
{
        return Val_bool(elm_win_focus_highlight_animate_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_keyboard_mode_set(value v_obj, value v_m)
{
        elm_win_keyboard_mode_set((Evas_Object*) v_obj,
                Elm_Win_Keyboard_Mode_val(v_m));
        return Val_unit;
}

PREFIX value ml_elm_win_keyboard_mode_get(value v_obj)
{
        return Val_Elm_Win_Keyboard_Mode(elm_win_keyboard_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_keyboard_win_set(value v_obj, value v_flag)
{
        elm_win_keyboard_win_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_keyboard_win_get(value v_obj)
{
        return Val_Eina_Bool(elm_win_keyboard_win_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_indicator_mode_set(value v_obj, value v_m)
{
        elm_win_indicator_mode_set((Evas_Object*) v_obj,
                Elm_Win_Indicator_Mode_val(v_m));
        return Val_unit;
}

PREFIX value ml_elm_win_indicator_mode_get(value v_obj)
{
        return Val_Elm_Win_Indicator_Mode(elm_win_indicator_mode_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_indicator_opacity_set(value v_obj, value v_m)
{
        elm_win_indicator_opacity_set((Evas_Object*) v_obj,
                Elm_Win_Indicator_Opacity_Mode_val(v_m));
        return Val_unit;
}

PREFIX value ml_elm_win_indicator_opacity_get(value v_obj)
{
        return Val_Elm_Win_Indicator_Opacity_Mode(elm_win_indicator_opacity_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_screen_position_get(value v_obj)
{
        int x, y;
        elm_win_screen_position_get((Evas_Object*) v_obj, &x, &y);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        return v;
}

PREFIX value ml_elm_win_socket_listen(
        value v_obj, value v_name, value v_num, value v_sys)
{
        return Val_Eina_Bool(elm_win_socket_listen((Evas_Object*) v_obj,
                String_val(v_name), Int_val(v_num), Eina_Bool_val(v_sys)));
}

PREFIX value ml_elm_win_xwindow_get(value v_obj)
{
        Ecore_X_Window win = elm_win_xwindow_get((Evas_Object*) v_obj);
        if(win == 0) raise_not_X();
        return Val_int(win);
}

PREFIX value ml_elm_win_wl_window_get(value v_obj)
{
        Ecore_Wl_Window* win = elm_win_wl_window_get((Evas_Object*) v_obj);
        if(win == NULL) raise_not_Wayland();
        return (value) win;
}

PREFIX value ml_elm_win_floating_mode_set(value v_obj, value v_flag)
{
        elm_win_floating_mode_set((Evas_Object*) v_obj, Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_win_floating_mode_get(value v_obj)
{
        return Val_bool(elm_win_floating_mode_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_win_window_id_get(value v_obj)
{
        return (value) elm_win_window_id_get((Evas_Object*) v_obj);
}

