(** Mapbuf *)

val add : Evas.obj -> Evas.obj

val enabled_set : Evas.obj -> bool -> unit

val enabled_get : Evas.obj -> bool

val smooth_set : Evas.obj -> bool -> unit

val smooth_get : Evas.obj -> bool

val alpha_set : Evas.obj -> bool -> unit

val alpha_get : Evas.obj -> bool

val auto_set : Evas.obj -> bool -> unit

val auto_get : Evas.obj -> bool

val point_color_set : Evas.obj -> int -> int -> int -> int -> int -> unit

val point_color_get : Evas.obj -> int -> int * int * int * int

