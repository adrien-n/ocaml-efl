open Common

let funs = [
  simple_unit "size_set" [evas_object; int; int];
  simple_unit "pack" [evas_object; evas_object; int; int; int; int];
  simple_unit "unpack" [evas_object; evas_object];
  simple_unit "clear" [evas_object; bool];
  simple_unit "pack_set" [evas_object; int; int; int; int];
]

