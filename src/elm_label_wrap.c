#include "include.h"

PREFIX value ml_elm_label_add(value v_parent)
{
        Evas_Object* lb = elm_label_add((Evas_Object*) v_parent);
        if(lb == NULL) caml_failwith("elm_label_add");
        return (value) lb;
}

