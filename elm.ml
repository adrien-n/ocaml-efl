type policy = [`quit]

type policy_value = [`none | `last_window_closed]

type wrap_type = [`none | `char | `word | `mixed]

external init_with_counter : string array -> int = "ml_elm_init_with_counter"

let init a = ignore (init_with_counter a)

external run : unit -> unit = "ml_elm_run"

external shutdown : unit -> unit = "ml_elm_shutdown"

external exit : unit -> unit = "ml_elm_exit"

external policy_set_with_bool : policy -> policy_value -> bool =
  "ml_elm_policy_set_with_bool"

let policy_set p v = ignore (policy_set_with_bool p v)

