external add : Evas.obj -> Evas.obj = "ml_elm_actionslider_add"

let addx = Elm_object.create_addx add

external selected_label_get : Evas.obj -> string option =
  "ml_elm_actionslider_selected_label_get"

external indicator_pos_set : Evas.obj -> bool -> bool -> bool -> unit =
  "ml_elm_actionslider_indicator_pos_set"

external indicator_pos_get : Evas.obj -> bool * bool * bool =
  "ml_elm_actionslider_indicator_pos_get"

external magnet_pos_set : Evas.obj -> bool -> bool -> bool -> unit =
  "ml_elm_actionslider_magnet_pos_set"

external magnet_pos_get : Evas.obj -> bool * bool * bool =
  "ml_elm_actionslider_magnet_pos_get"

external enabled_pos_set : Evas.obj -> bool -> bool -> bool -> unit =
  "ml_elm_actionslider_enabled_pos_set"

external enabled_pos_get : Evas.obj -> bool * bool * bool =
  "ml_elm_actionslider_enabled_pos_get"

