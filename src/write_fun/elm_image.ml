open Common

let orient = simple_ty "Elm_Image" "Orient"

let funs = [
  prop "smooth" bool;
  prop "no_scale" bool;
  simple_unit "resizable_set" [evas_object; bool; bool];
  prop "fill_outside" bool;
  simple_unit "preload_disabled_set" [evas_object; bool];
  prop "prescale" int;
  prop "orient" orient;
  prop "editable" bool;
  prop "aspect_fixed" bool;
  simple "animated_available_get" [evas_object] bool;
  prop "animated" bool;
  prop "animated_play" bool;
]

