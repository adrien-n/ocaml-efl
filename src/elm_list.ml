include Henums.Elm_list

external add : Evas.obj -> Evas.obj = "ml_elm_list_add"

let addx = Elm_object.create_addx add

external go : Evas.obj -> unit = "ml_elm_list_go"

external multi_select_set : Evas.obj -> bool -> unit =
  "ml_elm_list_multi_select_set"

external multi_select_get : Evas.obj -> bool = "ml_elm_list_multi_select_get"

external mode_set : Evas.obj -> mode -> unit = "ml_elm_list_mode_set"

external mode_get : Evas.obj -> mode = "ml_elm_list_mode_get"

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_list_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_list_horizontal_get"

external select_mode_set : Evas.obj -> Elm_object.select_mode -> unit =
  "ml_elm_list_select_mode_set"

external select_mode_get : Evas.obj -> Elm_object.select_mode =
  "ml_elm_list_select_mode_get"

external item_append :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?iend:Evas.obj ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_list_item_append_byte"
  "ml_elm_list_item_append_native"

external item_prepend :
  Evas.obj -> ?label:string -> ?icon:Evas.obj -> ?iend:Evas.obj ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_list_item_prepend_byte"
  "ml_elm_list_item_prepend_native"

external item_insert_before :
  Evas.obj -> Elm_object.item -> ?label:string -> ?icon:Evas.obj ->
    ?iend:Evas.obj -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_list_item_insert_before_byte"
  "ml_elm_list_item_insert_before_native"

external item_insert_after :
  Evas.obj -> Elm_object.item -> ?label:string -> ?icon:Evas.obj ->
    ?iend:Evas.obj -> ?func:Evas.smart_cb -> unit -> Elm_object.item =
  "ml_elm_list_item_insert_after_byte"
  "ml_elm_list_item_insert_after_native"

external clear : Evas.obj -> unit = "ml_elm_list_clear"

external items_get : Evas.obj -> Elm_object.item list = "ml_elm_list_items_get"

external selected_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_list_selected_item_get"

external selected_items_get : Evas.obj -> Elm_object.item list =
  "ml_elm_list_selected_items_get"

external item_selected_set : Elm_object.item -> bool -> unit =
  "ml_elm_list_item_selected_set"

external item_selected_get : Elm_object.item -> bool =
  "ml_elm_list_item_selected_get"

external item_separator_set : Elm_object.item -> bool -> unit =
  "ml_elm_list_item_separator_set"

external item_separator_get : Elm_object.item -> bool =
  "ml_elm_list_item_separator_get"

external item_show : Elm_object.item -> unit = "ml_elm_list_item_show"

external item_bring_in : Elm_object.item -> unit = "ml_elm_list_item_bring_in"

external item_object_get : Elm_object.item -> Evas.obj =
  "ml_elm_list_item_object_get"

external item_prev : Elm_object.item -> Elm_object.item option =
  "ml_elm_list_item_prev"

external item_next : Elm_object.item -> Elm_object.item option =
  "ml_elm_list_item_next"

external first_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_list_first_item_get"

external last_item_get : Evas.obj -> Elm_object.item option =
  "ml_elm_list_last_item_get"

