#ifndef ELM_H
#define ELM_H

#include "include.h"

/* Focus */

PREFIX inline Elm_Focus_Direction Elm_Focus_Direction_val(value v);
PREFIX inline value Val_Elm_Focus_Direction(Elm_Focus_Direction d);

/* Other */

PREFIX inline Eina_Bool ml_Elm_Event_Cb(
        void* data, Evas_Object* obj, Evas_Object* src, Evas_Callback_Type type,
        void* event_info);

PREFIX inline Elm_Wrap_Type Elm_Wrap_Type_val(value v);
PREFIX inline value Val_Elm_Wrap_Type(Elm_Wrap_Type t);

PREFIX inline Elm_Icon_Type Elm_Icon_Type_val(value v);
PREFIX inline value Val_Elm_Icon_Type(Elm_Icon_Type t);

PREFIX inline Elm_Text_Format Elm_Text_Format_val(value v);
PREFIX inline value Val_Elm_Text_Format(Elm_Text_Format f);

PREFIX inline Elm_Input_Panel_Layout Input_Panel_Layout_val(value v);
PREFIX inline value Val_Elm_Input_Panel_Layout(Elm_Input_Panel_Layout l);

PREFIX inline Elm_Autocapital_Type Elm_Autocapital_Type_val(value v);
PREFIX inline value Val_Elm_Autocapital_Type(Elm_Autocapital_Type t);

PREFIX inline Elm_Input_Panel_Lang Elm_Input_Panel_Lang_val(value v);
PREFIX inline value Val_Elm_Input_Panel_Lang(Elm_Input_Panel_Lang l);

PREFIX inline Elm_Input_Panel_Return_Key_Type
        Elm_Input_Panel_Return_Key_Type_val(value v);
PREFIX inline value Val_Elm_Input_Panel_Return_Key_Type(
        Elm_Input_Panel_Return_Key_Type t);

PREFIX inline Elm_Cnp_Mode Elm_Cnp_Mode_val(value v);
PREFIX inline value Val_Elm_Cnp_Mode(Elm_Cnp_Mode m);

#endif
