external add : Evas.obj -> Evas.obj = "ml_elm_multibuttonentry_add"

external entry_get : Evas.obj -> Evas.obj option =
  "ml_elm_multibuttonentry_entry_get"

external expanded_get : Evas.obj -> bool =
  "ml_elm_multibuttonentry_expanded_get"

external expanded_set : Evas.obj -> bool -> unit =
  "ml_elm_multibuttonentry_expanded_set"

external item_prepend :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
    "ml_elm_multibuttonentry_item_prepend"

external item_append :
  Evas.obj -> ?label:string -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
    "ml_elm_multibuttonentry_item_append"

external item_insert_before :
  Evas.obj -> Elm_object.item -> ?label:string -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item =
      "ml_elm_multibuttonentry_item_insert_before"

external item_insert_after :
  Evas.obj -> Elm_object.item -> ?label:string -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item =
      "ml_elm_multibuttonentry_item_insert_after"

external items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_multibuttonentry_items_get"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_multibuttonentry_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_multibuttonentry_last_item_get"

