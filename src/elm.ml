module HE = Henums.Elm

(* Cache *)

external cache_all_flush : unit -> unit = "ml_elm_cache_all_flush"

(* Fingers *)

external coords_finger_size_adjust : int -> int -> int * int =
  "ml_elm_coords_finger_size_adjust"

(* Focus *)

type focus_direction = HE.focus_direction

(* General *)

type policy_quit = HE.policy_quit

type policy_exit = HE.policy_exit

type policy_throttle = HE.policy_throttle

type event_cb = Evas.obj -> Evas.obj -> Evas_event.t -> bool

external init_with_counter : string array -> int = "ml_elm_init_with_counter"

let init () = let (_ : int) = init_with_counter Sys.argv in ()

external shutdown : unit -> unit = "ml_elm_shutdown"

external run : unit -> unit = "ml_elm_run"

external exit : unit -> unit = "ml_elm_exit"

external policy_quit_set_bool : policy_quit -> bool = "ml_elm_policy_quit_set"

let policy_quit_set x = ignore (policy_quit_set_bool x : bool)

external policy_exit_set_bool : policy_exit -> bool = "ml_elm_policy_exit_set"

let policy_exit_set x = ignore (policy_exit_set_bool x : bool)

external policy_throttle_set_bool : policy_throttle -> bool =
  "ml_elm_policy_throttle_set"

let policy_throttle_set x = ignore (policy_throttle_set_bool x : bool)

external policy_quit_get : unit -> policy_quit = "ml_elm_policy_quit_set"

external policy_exit_get : unit -> policy_exit = "ml_elm_policy_exit_set"

external policy_throttle_get : unit -> policy_throttle =
  "ml_elm_policy_throttle_set"

external language_set : string -> unit = "ml_elm_language_set"

let connect = Evas_object_smart.create_sig_with_cb

(* Gesture Layer *)

type gesture_type = HE.gesture_type

type gesture_state = HE.gesture_state

type gesture_event_cb = Evas.ptr -> unit

module Gesture_taps_info = struct
  type t = {
    y : int;
    n : int;
    timestamp : int;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Taps_Info_of_ptr"
end

module Gesture_momentum_info = struct
  type t = {
    x1 : int;
    y1 : int;
    x2 : int;
    y2 : int;
    tx : int;
    ty : int;
    mx : int;
    my : int;
    n : int;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Momentum_Info_of_ptr"
end

module Gesture_line_info = struct
  type t = {
    momentum : Gesture_momentum_info.t;
    angle : float;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Line_Info_of_ptr"
end

module Gesture_zoom_info = struct
  type t = {
    y : int;
    radius : int;
    zoom : float;
    momentum : float;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Zoom_Info_of_ptr"
end

module Gesture_rotate_info = struct
  type t = {
    y : int;
    radius : int;
    base_angle : float;
    angle : float;
    momentum : float;
  }
  external of_ptr : Evas.ptr -> t = "ml_Elm_Gesture_Rotate_Info_of_ptr"
end

(* Theme *)

type theme

(* Need *)

external need_efreet : unit -> bool = "ml_elm_need_efreet"

external need_systray : unit -> bool = "ml_elm_need_systray"

external need_sys_notify : unit -> bool = "ml_elm_need_sys_notify"

external need_eldbus : unit -> bool = "ml_elm_need_eldbus"

external need_elocation : unit -> bool = "ml_elm_need_elocation"

external need_ethumb : unit -> bool = "ml_elm_need_ethumb"

external need_web : unit -> bool = "ml_elm_need_web"

(* Entry *)

type text_format = HE.text_format

type wrap_type = HE.wrap_type

type input_panel_layout = HE.input_panel_layout

type input_panel_lang = HE.input_panel_lang

type autocapital_type = HE.autocapital_type

type input_panel_return_key_type = HE.input_panel_return_key_type

type cnp_mode = HE.cnp_mode

(* Window *)

type illume_command = HE.illume_command

(* Transit *)

type transit

(* Tooltips *)

type tooltip_content_cb = Evas.obj -> Evas.obj -> Evas.obj option

type 'a tooltip_item_content_cb = Evas.obj -> Evas.obj -> 'a -> Evas.obj option

(* Video *)

external player_add : Evas.obj -> Evas.obj = "ml_elm_player_add"

