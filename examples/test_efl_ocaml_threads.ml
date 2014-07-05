open Efl
open Printf

let add_button window box text =
  let btn = Elm_button.add window in
  Elm_object.text_set btn (sprintf "Print %s" text);
  let thread_cb () =
    while true do
      print_endline text;
      Thread.delay 0.5;
    done in
  let clicked_cb obj =
    let (_ : Thread.t) = Thread.create thread_cb () in
    () in
  Elm_connect.Button.clicked btn clicked_cb;
  Elm_box.pack_end box btn;
  Evas_object.show btn

let () =
  Elm.init ();
  Elm.policy_quit_set `last_window_closed;
  let window = Elm_win.add "two buttons" `basic in
  Elm_win.autodel_set window true;

  let box = Elm_box.add window in
  Elm_box.horizontal_set box true;
  Elm_win.resize_object_add window box;
  Evas_object.show box;

  add_button window box "A";
  add_button window box "B";

  Evas_object.show window;
  Elm.run ();
  Elm.shutdown ()

