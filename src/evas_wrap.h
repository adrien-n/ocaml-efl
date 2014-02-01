#ifndef EVAS_H
#define EVAS_H

#include "include.h"

PREFIX void ml_Evas_Smart_Cb(void* data, Evas_Object* obj, void* event_info);

PREFIX void ml_Evas_Smart_Cb_1(void* data, Evas_Object* obj, void* event_info);

PREFIX void ml_Evas_Object_Box_Layout_0(
        Evas_Object* obj, Evas_Object_Box_Data* priv, void* user_data);

PREFIX inline value copy_Evas_Event_Info(
        Evas_Callback_Type type, void* event_info);

PREFIX inline Evas_Load_Error Evas_Load_Error_val(value v);
PREFIX inline value Val_Evas_Load_Error(Evas_Load_Error e);

#endif

