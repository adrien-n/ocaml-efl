#include "include.h"

PREFIX value ml_elm_app_info_set(value v_name, value v_checkfile, value v_unit)
{
        const char* checkfile;
        if(v_checkfile == Val_int(0)) checkfile = NULL;
        else checkfile = String_val(Field(v_checkfile, 0));
        elm_app_info_set(NULL, String_val(v_name), checkfile);
        return Val_unit;
}

PREFIX value ml_elm_app_name_set(value v_name)
{
        elm_app_name_set(String_val(v_name));
        return Val_unit;
}

PREFIX value ml_elm_app_desktop_entry_set(value v_desktop_entry)
{
        elm_app_desktop_entry_set(String_val(v_desktop_entry));
        return Val_unit;
}

PREFIX value ml_elm_app_compile_bin_dir_set(value v_compile_bin_dir)
{
        elm_app_compile_bin_dir_set(String_val(v_compile_bin_dir));
        return Val_unit;
}

PREFIX value ml_elm_app_compile_lib_dir_set(value v_compile_lib_dir)
{
        elm_app_compile_lib_dir_set(String_val(v_compile_lib_dir));
        return Val_unit;
}

PREFIX value ml_elm_app_compile_data_dir_set(value v_compile_data_dir)
{
        elm_app_compile_data_dir_set(String_val(v_compile_data_dir));
        return Val_unit;
}

PREFIX value ml_elm_app_compile_locale_set(value v_compile_locale_dir)
{
        elm_app_compile_locale_set(String_val(v_compile_locale_dir));
        return Val_unit;
}

PREFIX value ml_elm_app_data_dir_get(value v_unit)
{
        return copy_string(elm_app_data_dir_get());
}

