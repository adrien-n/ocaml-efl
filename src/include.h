#ifndef INCLUDE_H
#define INCLUDE_H

/* Common headers */

#include <stdio.h>

/* OCaml headers */

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/threads.h>

/* EFL headers */

#define EFL_BETA_API_SUPPORT 1
#define EFL_EO_API_SUPPORT 1
#include <Elementary.h>

/* Prefix used on all functions */

#define PREFIX CAMLprim EAPI

/* General functions */

 struct tm Tm_val(value v);
 value copy_tm(struct tm t);

 value* ml_register_value(value v);
 void ml_remove_value(value* data);

 value safe_copy_string(const char* s);
 value safe_copy_string_free(char* s);

/* Local headers */

#include "variants.h"
#include "eina_wrap.h"
#include "evas_wrap.h"
#include "evas_event_wrap.h"
#include "evas_object_wrap.h"
#include "ethumb_wrap.h"
#include "ecore_wrap.h"
#include "edje_wrap.h"
#include "elm_wrap.h"
#include "elm_object_wrap.h"
#include "elm_gen_wrap.h"
#include "elm_calendar_wrap.h"
#include "elm_clock_wrap.h"
#include "elm_scroller_wrap.h"
#include "elm_list_wrap.h"
#include "elm_entry_wrap.h"
#include "elm_icon_wrap.h"
#include "elm_web_wrap.h"
#include "elm_dayselector_wrap.h"
#include "enums_variants_wrap.h"
#include "enums_wrap.h"
#include "structs_wrap.h"
#include "other_wrap.h"

#endif

