(** Timer *)

type t = Ecore.timer

val add : float -> Ecore.task_cb -> Ecore.timer

val delay : t -> float -> unit

