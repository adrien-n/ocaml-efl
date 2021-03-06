open Common

let animation_setting = simple_ty "Elm_Thumb" "Animation_Setting"

let funs = [
  simple_unit "reload" [evas_object];
  simple_unit "file_set" [evas_object; safe_string; safe_string];
  prop "aspect" ethumb_thumb_aspect;
  prop "fdo_size" ethumb_thumb_fdo_size;
  prop "format" ethumb_thumb_format;
  prop "orientation" ethumb_thumb_orientation;
  simple_unit "size_set" [evas_object; int; int];
  simple_unit "crop_align_set" [evas_object; double; double];
  simple_unit "compress_set" [evas_object; int];
  simple_unit "quality_set" [evas_object; int];
  prop "animate" animation_setting;
  simple "ethumb_client_connected_get" [] bool;
  prop "editable" bool;
]

