external add : Evas.obj -> Evas.obj = "ml_elm_image_add"

external file_set : Evas.obj -> string -> ?g:string -> unit -> bool =
  "ml_elm_image_file_set"

external file_get : Evas.obj -> string * string option = "ml_elm_image_file_get"

external smooth_set : Evas.obj -> bool -> unit = "ml_elm_image_smooth_set"

external smooth_get : Evas.obj -> bool = "ml_elm_image_smooth_get"

external object_size_get : Evas.obj -> int * int =
  "ml_elm_image_object_size_get"

external no_scale_set : Evas.obj -> bool -> unit = "ml_elm_image_no_scale_set"

external no_scale_get : Evas.obj -> bool = "ml_elm_image_no_scale_get"

external resizable_set : Evas.obj -> bool -> bool -> unit =
  "ml_elm_image_resizable_set"

external resizable_get : Evas.obj -> bool * bool = "ml_elm_image_resizable_get"

external fill_outside_set : Evas.obj -> bool -> unit =
  "ml_elm_image_fill_outside_set"

