external add : Evas.obj -> Evas.obj = "ml_elm_panes_add"

let addx = Elm_object.create_addx add

external fixed_set : Evas.obj -> bool -> unit = "ml_elm_panes_fixed_set"

external fixed_get : Evas.obj -> bool = "ml_elm_panes_fixed_get"

external content_left_size_get : Evas.obj -> float =
  "ml_elm_panes_content_left_size_get"

external content_left_size_set : Evas.obj -> float -> unit =
  "ml_elm_panes_content_left_size_set"

external content_right_size_get : Evas.obj -> float =
  "ml_elm_panes_content_right_size_get"

external content_right_size_set : Evas.obj -> float -> unit =
  "ml_elm_panes_content_right_size_set"

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_panes_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_panes_horizontal_get"

