(** elm_object_* Elm_Object_* *)

(** {2 Cursors} *)

val cursor_set : Evas.obj -> string -> unit

val cursor_get : Evas.obj -> string

val cursor_unset : Evas.obj -> unit

val cursor_style_set : Evas.obj -> string -> unit

val cursor_style_get : Evas.obj -> string

val cursor_theme_search_enabled_set : Evas.obj -> bool -> unit

val cursor_theme_search_enabled_get : Evas.obj -> bool

(** {2 Debug} *)

val tree_dump : Evas.obj -> unit

val tree_dot_dump : Evas.obj -> string -> unit

(** {2 Focus} *)

val focus_get : Evas.obj -> bool

val focus_set : Evas.obj -> bool -> unit

val focus_allow_set : Evas.obj -> bool -> unit

val focus_allow_get : Evas.obj -> bool

val focus_custom_chain_set : Evas.obj -> Evas.obj list -> unit

val focus_custom_chain_unset : Evas.obj -> unit

val focus_custom_chain_get : Evas.obj -> Evas.obj list

val focus_custom_chain_append : Evas.obj -> Evas.obj -> Evas.obj option -> unit

val focus_custom_chain_prepend : Evas.obj -> Evas.obj -> Evas.obj option -> unit

val focus_next : Evas.obj -> Elm.focus_direction -> unit

val focus_next_object_get : Evas.obj -> Elm.focus_direction -> Evas.obj option

val focus_next_object_set :
  Evas.obj -> Evas.obj option -> Elm.focus_direction -> unit

val tree_focus_allow_get : Evas.obj -> bool

val tree_focus_allow_set : Evas.obj -> bool -> unit

(** {2 General} *)

type item

type select_mode = [`default | `always | `none | `display_only]

val domain_translatable_part_text_set :
  Evas.obj -> ?part:string -> ?domain:string -> ?text:string -> unit -> unit

val translatable_part_text_get : Evas.obj -> ?p:string -> unit -> string

val text_set : Evas.obj -> string -> unit

val part_text_set : Evas.obj -> ?p:string -> string -> unit

val text_get : Evas.obj -> string

val part_text_get : Evas.obj -> ?p:string -> unit -> string

val content_set : Evas.obj -> Evas.obj -> unit

val part_content_set : Evas.obj -> ?p:string -> Evas.obj -> unit 

val part_content_set_null : Evas.obj -> ?p:string -> unit -> unit

val part_content_get : Evas.obj -> ?p:string -> unit -> Evas.obj

val content_unset : Evas.obj -> Evas.obj

val part_content_unset : Evas.obj -> ?p:string -> unit -> Evas.obj

val access_info_set : Evas.obj -> string -> unit

val name_find : Evas.obj -> string -> int -> Evas.obj option

val signal_emit : Evas.obj -> string -> string -> unit

val signal_callback_add : Evas.obj -> string -> string -> Edje.signal_cb -> unit

val signal_callback_del : Evas.obj -> string -> string -> Edje.signal_cb -> unit

val item_widget_get : item -> Evas.obj

val item_content_set : item -> Evas.obj -> unit

val item_part_content_set : item -> ?p:string -> Evas.obj -> unit

val item_part_content_get : item -> ?p:string -> unit -> Evas.obj

val item_part_content_unset : item -> ?p:string -> unit -> Evas.obj

val item_part_text_set : item -> ?p:string -> string -> unit

val item_part_text_get : item -> ?p:string -> unit -> string

(** {2 Widget Tree Navigation} *)

val widget_check : Evas.obj -> bool

val parent_widget_get : Evas.obj -> Evas.obj option

val top_widget_get : Evas.obj -> Evas.obj option

val widget_type_get : Evas.obj -> string option

(** {2 Other} *)

val style_set : Evas.obj -> string -> bool

val disabled_set : Evas.obj -> bool -> unit

val disabled_get : Evas.obj -> bool

val item_of_ptr : Evas.ptr -> item

val item_del : item -> unit

val item_disabled_set : item -> bool -> unit

val item_text_get : item -> string

