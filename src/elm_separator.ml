external add : Evas.obj -> Evas.obj = "ml_elm_separator_add"

let addx = Elm_object.create_addx add

external horizontal_set : Evas.obj -> bool -> unit =
  "ml_elm_separator_horizontal_set"

external horizontal_get : Evas.obj -> bool = "ml_elm_separator_horizontal_get"

