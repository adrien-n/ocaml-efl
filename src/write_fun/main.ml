open Format
open Common

let list = [
  ("Elm_bg", Elm_bg.funs);
  ("Elm_box", Elm_box.funs);
  ("Elm_bubble", Elm_bubble.funs);
  ("Elm_button", Elm_button.funs);
  ("Elm_calendar", Elm_calendar.funs);
  ("Elm_check", Elm_check.funs);
  ("Elm_clock", Elm_clock.funs);
  ("Elm_colorselector", Elm_colorselector.funs);
  ("Elm_datetime", Elm_datetime.funs);
  ("Elm_dayselector", Elm_dayselector.funs);
  ("Elm_diskselector", Elm_diskselector.funs);
  ("Elm_entry", Elm_entry.funs);
  ("Elm_flip", Elm_flip.funs);
  ("Elm_flipselector", Elm_flipselector.funs);
  ("Elm_frame", Elm_frame.funs);
  ("Elm_gengrid", Elm_gengrid.funs);
  ("Elm_genlist", Elm_genlist.funs);
  ("Elm_gesture_layer", Elm_gesture_layer.funs);
  ("Elm_glview", Elm_glview.funs);
  ("Elm_grid", Elm_grid.funs);
]

let write filename print secs =
  let ch = open_out filename in
  let fmt = formatter_of_out_channel ch in
  print fmt secs;
  fprintf fmt "%!";
  close_out ch

let ( / ) = Filename.concat

let () =
  let secs = Sections.create list in
  write ("src" / "autofun.ml") Sections.print_ml secs;
  write ("src" / "autofun_wrap.c") Sections.print_c secs;
  exit 0

