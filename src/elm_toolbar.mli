(** elm_toolbar_* Elm_Toolbar_* *)

type item_state

type shrink_mode = [
  | `none
  | `hide
  | `scroll
  | `menu
  | `expand
  | `last]

type item_scrollto_type = [
  | `none
  | `_in
  | `first
  | `middle
  | `last
]

val add : Evas.obj -> Evas.obj

val icon_size_set : Evas.obj -> int -> unit

val icon_size_get : Evas.obj -> int

val icon_order_lookup_set : Evas.obj -> Elm_icon.lookup_order -> unit

val icon_order_lookup_get : Evas.obj -> Elm_icon.lookup_order

val item_append :
  Evas.obj -> ?icon:string -> ?label:string -> ?func:Evas.smart_cb -> unit ->
    Elm_object.item

val item_prepend :
  Evas.obj -> ?icon:string -> ?label:string -> ?func:Evas.smart_cb ->
    unit -> Elm_object.item

val item_insert_before :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item

val item_insert_after :
  Evas.obj -> Elm_object.item -> ?icon:string -> ?label:string ->
    ?func:Evas.smart_cb -> unit -> Elm_object.item

val first_item_get : Evas.obj -> Elm_object.item option

val last_item_get : Evas.obj -> Elm_object.item option

val item_next_get : Elm_object.item -> Elm_object.item option

val item_prev_get : Elm_object.item -> Elm_object.item option

val item_priority_set : Elm_object.item -> int -> unit

val item_priority_get : Elm_object.item -> int

val item_find_by_label : Evas.obj -> string -> Elm_object.item option

val item_selected_set : Elm_object.item -> bool -> unit

val selected_item_get : Evas.obj -> Elm_object.item option

val more_item_get : Evas.obj -> Elm_object.item option

val item_icon_set : Elm_object.item -> string -> unit

val item_icon_get : Elm_object.item -> string

val item_object_get : Elm_object.item -> Evas.obj

val item_icon_object_get : Elm_object.item -> Evas.obj

val item_icon_file_set :
  Elm_object.item -> string -> ?key:string -> unit -> bool

val item_separator_set : Elm_object.item -> bool -> unit

val item_separator_get : Elm_object.item -> bool

val shrink_mode_set : Evas.obj -> shrink_mode -> unit

val shrink_mode_get : Evas.obj -> shrink_mode

val transverse_expanded_set : Evas.obj -> bool -> unit

val transverse_expanded_get : Evas.obj -> bool

val homogeneous_set : Evas.obj -> bool -> unit

val homogeneous_get : Evas.obj -> bool

val menu_parent_set : Evas.obj -> Evas.obj -> unit

val menu_parent_get : Evas.obj -> Evas.obj

val align_set : Evas.obj -> float -> unit

val align_get : Evas.obj -> float

val item_menu_set : Elm_object.item -> bool -> unit

val item_menu_get : Elm_object.item -> Evas.obj option

val item_state_add :
  Elm_object.item -> ?icon:string -> ?label:string -> ?func:Evas.smart_cb ->
    unit -> item_state

val item_state_del : Elm_object.item -> item_state -> bool

val item_state_set : Elm_object.item -> item_state -> bool

val item_state_set_null : Elm_object.item -> bool

val item_state_get : Elm_object.item -> item_state option

val item_state_next : Elm_object.item -> item_state option

val item_state_prev : Elm_object.item -> item_state option

val item_show : Elm_object.item -> item_scrollto_type list -> unit

val item_bring_in : Elm_object.item -> item_scrollto_type list -> unit

val horizontal_set : Evas.obj -> bool -> unit

val horizontal_get : Evas.obj -> bool

val items_count : Evas.obj -> int

val standard_priority_set : Evas.obj -> int -> unit

val standard_priority_get : Evas.obj -> int

val select_mode_set : Evas.obj -> Elm_object.select_mode -> unit

val select_mode_get : Evas.obj -> Elm_object.select_mode

val reorder_mode_set : Evas.obj -> bool -> unit

val reorder_mode_get : Evas.obj -> bool

