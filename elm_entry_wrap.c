#include "include.h"

Evas_Object* ml_Elm_Entry_Item_Provider_Cb(
        void* data, Evas_Object* entry, const char* item)
{
        value* v_fun = (value*) data;
        value v_r = caml_callback2(*v_fun, (value) entry, copy_string(item));
        if(v_r == Val_int(0)) return NULL;
        else return (Evas_Object*) Field(v_r, 0);
}

void ml_Elm_Entry_Filter_Cb(void* data, Evas_Object* entry, char** text)
{
        value* v_fun = (value*) data;
        value v_r = caml_callback2(*v_fun, (value) entry, copy_string(*text));
        free(*text);
        if(v_r == Val_int(0)) *text = NULL;
        else {
                char* text1 = String_val(Field(v_r, 0));
                *text = caml_stat_alloc(strlen(text1) + 1);
                strcpy(*text, text1);
        }
}

PREFIX value ml_elm_entry_add(value v_parent)
{
        Evas_Object* entry = elm_entry_add((Evas_Object*) v_parent);
        if(entry == NULL) caml_failwith("ml_elm_entry_add");
        return (value) entry;
}

PREFIX value ml_elm_entry_text_style_user_push(value v_obj, value v_style)
{
        elm_entry_text_style_user_push((Evas_Object*) v_obj,
                (const char*) String_val(v_style));
        return Val_unit;
}

PREFIX value ml_elm_entry_text_style_user_pop(value v_obj)
{
        elm_entry_text_style_user_pop((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_text_style_user_peek(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        char* text = (char*) elm_entry_text_style_user_peek(
                (Evas_Object*) v_obj);
        if(text == NULL) return Val_int(0);
        v = caml_alloc(1, 0);
        Store_field(v, 0, copy_string(text));
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_single_line_set(value v_obj, value v_flag)
{
        elm_entry_single_line_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_single_line_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_single_line_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_password_set(value v_obj, value v_flag) {
        elm_entry_password_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_password_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_password_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_entry_set(value v_obj, value v_entry)
{
        elm_entry_entry_set((Evas_Object*) v_obj, String_val(v_entry));
        return Val_unit;
}

PREFIX value ml_elm_entry_entry_get(value v_obj)
{
        return copy_string(elm_entry_entry_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_entry_append(value v_obj, value v_entry)
{
        elm_entry_entry_append((Evas_Object*) v_obj, String_val(v_entry));
        return Val_unit;
}

PREFIX value ml_elm_entry_is_empty(value v_obj)
{
        return Val_Eina_Bool(elm_entry_is_empty((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_selection_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* text = elm_entry_selection_get((Evas_Object*) v_obj);
        v = caml_alloc(1, 0);
        Store_field(v, 0, copy_string(text));
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_textblock_get(value v_obj)
{
        return (value) elm_entry_textblock_get((Evas_Object*) v_obj);
}

PREFIX value ml_elm_entry_calc_force(value v_obj)
{
        elm_entry_calc_force((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_entry_insert(value v_obj, value v_entry)
{
        elm_entry_entry_insert((Evas_Object*) v_obj, String_val(v_entry));
        return Val_unit;
}

PREFIX value ml_elm_entry_line_wrap_set(value v_obj, value v_wrap)
{
        elm_entry_line_wrap_set((Evas_Object*) v_obj,
                Elm_Wrap_Type_val(v_wrap));
        return Val_unit;
}

PREFIX value ml_elm_entry_line_wrap_get(value v_obj)
{
        return Val_Elm_Wrap_Type(elm_entry_line_wrap_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_editable_set(value v_obj, value v_flag)
{
        elm_entry_editable_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_editable_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_editable_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_select_none(value v_obj)
{
        elm_entry_select_none((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_select_all(value v_obj)
{
        elm_entry_select_all((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_next(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_next((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_prev(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_next((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_up(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_up((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_down(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_down((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_begin_set(value v_obj)
{
        elm_entry_cursor_begin_set((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_end_set(value v_obj)
{
        elm_entry_cursor_end_set((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_line_begin_set(value v_obj)
{
        elm_entry_cursor_line_begin_set((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_line_end_set(value v_obj)
{
        elm_entry_cursor_line_end_set((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_selection_begin(value v_obj)
{
        elm_entry_cursor_selection_begin((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_selection_end(value v_obj)
{
        elm_entry_cursor_selection_end((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_is_format_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_is_format_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_is_visible_format_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_cursor_is_visible_format_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_cursor_content_get(value v_obj)
{
        char* text = elm_entry_cursor_content_get((Evas_Object*) v_obj);
        value v = copy_string(text);
        free(text);
        return v;
}

PREFIX value ml_elm_entry_cursor_geometry_get(value v_obj)
{
        Evas_Coord x, y, z, w, h;
        if(!elm_entry_cursor_geometry_get((Evas_Object*) v_obj, &x, &y, &w, &h))
                caml_failwith("elm_entry_cursor_geometry_get");
        value v = caml_alloc(4, 0);
        Store_field(v, 0, Val_int(x));
        Store_field(v, 1, Val_int(y));
        Store_field(v, 2, Val_int(w));
        Store_field(v, 3, Val_int(h));
        return v;
}

PREFIX value ml_elm_entry_cursor_pos_set(value v_obj, value v_pos)
{
        elm_entry_cursor_pos_set((Evas_Object*) v_obj, Int_val(v_pos));
        return Val_unit;
}

PREFIX value ml_elm_entry_cursor_pos_get(value v_obj)
{
        return Val_int(elm_entry_cursor_pos_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_selection_cut(value v_obj)
{
        elm_entry_selection_cut((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_selection_copy(value v_obj)
{
        elm_entry_selection_copy((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_selection_paste(value v_obj)
{
        elm_entry_selection_paste((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_context_menu_clear(value v_obj)
{
        elm_entry_context_menu_clear((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_context_menu_item_add(
        value v_obj, value v_label, value v_icon_file, value v_icon_type,
        value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_entry_context_menu_item_add((Evas_Object*) v_obj,
                String_val(v_label), String_val(v_icon_file),
                Elm_Icon_Type_val(v_icon_type), ml_Evas_Smart_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_entry_context_menu_disabled_set(value v_obj, value v_flag)
{
        elm_entry_context_menu_disabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_context_menu_disabled_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_context_menu_disabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_item_provider_append(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_entry_item_provider_append((Evas_Object*) v_obj,
                ml_Elm_Entry_Item_Provider_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_entry_item_provider_prepend(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;;
        caml_register_global_root(data);
        elm_entry_item_provider_prepend((Evas_Object*) v_obj,
                ml_Elm_Entry_Item_Provider_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_entry_markup_filter_append(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_entry_markup_filter_append((Evas_Object*) v_obj,
                ml_Elm_Entry_Filter_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_entry_markup_filter_prepend(value v_obj, value v_fun)
{
        value* data = caml_stat_alloc(sizeof(value));
        *data = v_fun;
        caml_register_global_root(data);
        elm_entry_markup_filter_prepend((Evas_Object*) v_obj,
                ml_Elm_Entry_Filter_Cb, data);
        return Val_unit;
}

PREFIX value ml_elm_entry_markup_to_utf8(value v_s)
{
        char* s1 = elm_entry_markup_to_utf8(String_val(v_s));
        value v_s1 = copy_string(s1);
        free(s1);
        return v_s1;
}

PREFIX value ml_elm_entry_utf8_to_markup(value v_s)
{
        char* s1 = elm_entry_utf8_to_markup(String_val(v_s));
        value v_s1 = copy_string(s1);
        free(s1);
        return v_s1;
}

PREFIX value ml_elm_entry_file_set(value v_obj, value v_file, value v_format)
{
        if(!elm_entry_file_set((Evas_Object*) v_obj, String_val(v_file),
                Elm_Text_Format_val(v_format)))
        {
               caml_failwith("elm_entry_file_set");
        }
        return Val_unit;
}

PREFIX value ml_elm_entry_file_get(value v_obj)
{
        CAMLparam0();
        CAMLlocal1(v);
        const char* file;
        Elm_Text_Format format;
        elm_entry_file_get((Evas_Object*) v_obj, &file, &format);
        v = caml_alloc(2, 0);
        Store_field(v, 0, copy_string(file));
        Store_field(v, 1, Val_Elm_Text_Format(format));
        CAMLreturn(v);
}

PREFIX value ml_elm_entry_file_save(value v_obj)
{
        elm_entry_file_save((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_autosave_set(value v_obj, value v_flag)
{
        elm_entry_autosave_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_autosave_get(value v_obj, value v_flag)
{
        return Val_Eina_Bool(elm_entry_autosave_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_scrollable_set(value v_obj, value v_flag)
{
        elm_entry_scrollable_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_scrollable_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_scrollable_get((Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_icon_visible_set(value v_obj, value v_flag)
{
        elm_entry_icon_visible_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_end_visible_set(value v_obj, value v_flag)
{
        elm_entry_end_visible_set((Evas_Object*) v_obj, Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_scrollbar_policy_set(value v_obj, value v_h, value v_v)
{
        elm_entry_scrollbar_policy_set((Evas_Object*) v_obj,
                Elm_Scroller_Policy_val(v_h), Elm_Scroller_Policy_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_entry_bounce_set(value v_obj, value v_h, value v_v)
{
        elm_entry_bounce_set((Evas_Object*) v_obj, Eina_Bool_val(v_h),
                Eina_Bool_val(v_v));
        return Val_unit;
}

PREFIX value ml_elm_entry_bounce_get(value v_obj)
{
        Eina_Bool h_bounce, v_bounce;
        elm_entry_bounce_get((Evas_Object*) v_obj, &h_bounce, &v_bounce);
        value v = caml_alloc(2, 0);
        Store_field(v, 0, Val_Eina_Bool(h_bounce));
        Store_field(v, 1, Val_Eina_Bool(v_bounce));
        return v;
}

PREFIX value ml_elm_entry_input_panel_layout_set(value v_obj, value v_layout)
{
        elm_entry_input_panel_layout_set((Evas_Object*) v_obj,
                Elm_Input_Panel_Layout_val(v_layout));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_layout_get(value v_obj)
{
        return Val_Elm_Input_Panel_Layout(elm_entry_input_panel_layout_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_autocapital_type_set(value v_obj, value v_type)
{
        elm_entry_autocapital_type_set((Evas_Object*) v_obj,
                Elm_Autocapital_Type_val(v_type));
        return Val_unit;
}

PREFIX value ml_elm_entry_autocapital_type_get(value v_obj)
{
        return Val_Elm_Autocapital_Type(elm_entry_autocapital_type_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_input_panel_enabled_set(value v_obj, value v_flag)
{
        elm_entry_input_panel_enabled_set((Evas_Object*) v_obj,
                Eina_Bool_val(v_flag));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_enabled_get(value v_obj)
{
        return Val_Eina_Bool(elm_entry_input_panel_enabled_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_input_panel_show(value v_obj)
{
        elm_entry_input_panel_show((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_hide(value v_obj)
{
        elm_entry_input_panel_hide((Evas_Object*) v_obj);
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_language_set(value v_obj, value v_l)
{
        elm_entry_input_panel_language_set((Evas_Object*) v_obj,
                Elm_Input_Panel_Lang_val(v_l));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_language_get(value v_obj)
{
        return Val_Elm_Input_Panel_Lang(elm_entry_input_panel_language_get(
                (Evas_Object*) v_obj));
}

PREFIX value ml_elm_entry_input_panel_return_key_type_set(
        value v_obj, value v_t)
{
        elm_entry_input_panel_return_key_type_set((Evas_Object*) v_obj,
                Elm_Input_Panel_Return_Key_Type_val(v_t));
        return Val_unit;
}

PREFIX value ml_elm_entry_input_panel_return_key_type_get(value v_obj)
{
        return Val_Elm_Input_Panel_Return_Key_Type(
                elm_entry_input_panel_return_key_type_get(
                (Evas_Object*) v_obj));
}

