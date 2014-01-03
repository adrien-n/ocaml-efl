type item_class = Elm_gen.item_class = {
  item_style : string;
  func_text_get : Evas.obj -> string -> string;
  func_content_get : Evas.obj -> string -> Evas.obj option;
  func_state_get : Evas.obj -> string -> bool;
  func_del : Evas.obj -> unit;
}

type item_scrollto_type = [`none | `_in | `top | `middle]

val add : Evas.obj -> Evas.obj

val clear : Evas.obj -> unit

val multi_select_set : Evas.obj -> bool -> unit

val multi_select_get : Evas.obj -> bool

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val item_append : Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item

val item_prepend : Evas.obj -> item_class -> Evas.smart_cb -> Elm_object.item

val item_insert_before :
  Evas.obj -> item_class -> Elm_object.item -> Evas.smart_cb -> Elm_object.item

val item_insert_after :
  Evas.obj -> item_class -> Elm_object.item -> Evas.smart_cb -> Elm_object.item

val selected_item_get : Evas.obj -> Elm_object.item option

val selected_items_get : Evas.obj -> Elm_object.item list

val realized_items_get : Evas.obj -> Elm_object.item list

val first_item_get : Evas.obj -> Elm_object.item option

val last_item_get : Evas.obj -> Elm_object.item option

val item_next_get : Elm_object.item -> Elm_object.item option

val item_prev_get : Elm_object.item -> Elm_object.item option

val item_selected_set : Elm_object.item -> bool -> unit

val item_selected_get : Elm_object.item -> bool

val item_show : Elm_object.item -> item_scrollto_type -> unit

val item_bring_in : Elm_object.item -> item_scrollto_type -> unit

val item_update : Elm_object.item -> unit

val item_index_get : Elm_object.item -> int

val items_count : Evas.obj -> int

val item_tooltip_text_set : Elm_object.item -> string -> unit

val item_tooltip_content_cb_set :
  Elm_object.item -> Elm_object.item Elm_tooltip.item_content_cb ->
    (Evas.obj -> unit) -> unit

val item_tooltip_unset : Elm_object.item -> unit

val item_tooltip_style_set : Elm_object.item -> string -> unit

val item_tooltip_style_get : Elm_object.item -> string

val item_tooltip_window_mode_set : Elm_object.item -> bool -> unit

val item_tooltip_window_mode_get : Elm_object.item -> bool

val item_cursor_set : Elm_object.item -> string -> unit

val item_cursor_get : Elm_object.item -> string option

val item_cursor_unset : Elm_object.item -> unit

val item_cursor_style_set : Elm_object.item -> string -> unit

val item_cursor_style_get : Elm_object.item -> string option

val item_cursor_engine_only_set : Elm_object.item -> bool -> unit

val item_cursor_engine_only_get : Elm_object.item -> bool

val item_size_set : Evas.obj -> int -> int -> unit

val item_size_get : Evas.obj -> int * int

val group_item_size_set : Evas.obj -> int -> int -> unit

val group_item_size_get : Evas.obj -> int * int

