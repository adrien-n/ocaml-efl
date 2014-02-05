open Printf

external get_hash_value : string -> string = "ml_get_hash_value"

let f x y = printf "#define %s %s\n" x (get_hash_value y)

let g x = f (sprintf "Val_%s" x) x

let () =
  g "abort";
  g "accelerate";
  g "all";
  g "allcharacter";
  g "alpha";
  g "alphabet";
  g "always";
  g "ampm";
  g "annually";
  g "auto";
  g "auto_fill";
  g "auto_fit";
  g "auto_fit_in";
  g "automatic";
  g "basic";
  g "bicycle";
  g "block_horizontal";
  g "block_vertical";
  g "block_vertical_horizontal";
  g "both";
  g "bottom";
  g "bottom_left";
  g "bottom_right";
  g "bubble";
  g "center";
  g "char";
  g "circle";
  f "Val_class" "_class";
  g "close";
  g "combo";
  g "components";
  g "compress";
  g "config";
  g "content";
  g "corrupt_file";
  g "crop";
  g "cube";
  g "cube_down";
  g "cube_left";
  g "cube_right";
  g "cube_up";
  g "daily";
  g "date";
  g "datetime";
  g "day";
  g "decelerate";
  g "default";
  g "desktop";
  g "dialog_basic";
  g "display_only";
  g "dnd";
  g "dock";
  g "does_not_exist";
  f "Val_done" "_done";
  g "down";
  g "dropdown_menu";
  g "eet";
  g "email";
  f "Val_end" "_end";
  g "expand";
  g "fastest";
  g "fdo";
  g "fdo_theme";
  g "file";
  g "first";
  g "flip_horizontal";
  g "flip_transpose";
  g "flip_transverse";
  g "flip_vertical";
  g "focus_back";
  g "focus_forward";
  g "focus_home";
  g "foot";
  g "fri";
  g "friday";
  g "fullscreen";
  g "generic";
  g "go";
  g "grid";
  g "group";
  g "hard";
  g "hex";
  g "hidden_always";
  g "hide";
  g "horizontal";
  g "host";
  g "hour";
  g "hour_decimal";
  g "hour_unit";
  g "ignore_aspect";
  f "Val_in" "_in";
  g "inlined_image";
  g "invalid";
  g "ip";
  g "j2me";
  g "join";
  g "jpeg";
  g "keep_aspect";
  g "key_down";
  g "keypad";
  g "large";
  g "last";
  g "last_day_of_month";
  g "last_window_closed";
  g "left";
  g "limit";
  g "line";
  g "linear";
  g "list";
  g "locationbar";
  g "login";
  g "loop";
  g "manual";
  g "markup";
  g "markup_utf8";
  g "max";
  g "menu";
  g "menubar";
  g "middle";
  g "min_decimal";
  g "min_unit";
  g "minute";
  g "mixed";
  g "momentum";
  g "mon";
  g "monday";
  g "month";
  g "monthly";
  g "motocar";
  g "mouse_down";
  g "mouse_up";
  g "move";
  g "n_double_taps";
  g "n_flicks";
  g "n_lines";
  g "n_long_taps";
  g "n_taps";
  g "n_triple_taps";
  g "name";
  g "neither";
  g "never";
  g "next";
  g "no_block";
  g "no_image";
  g "none";
  g "normal";
  g "notification";
  g "number";
  g "numberonly";
  g "numeric";
  g "off";
  g "on";
  g "ondemand";
  g "opacity_unknown";
  g "opaque";
  g "option";
  g "orient_none";
  g "orient_original";
  g "other";
  g "page";
  g "page_down";
  g "page_left";
  g "page_right";
  g "page_up";
  g "palette";
  g "password";
  g "permission_denied";
  g "phone_number";
  g "phonenumber";
  g "picker";
  g "pin";
  g "plain_utf8";
  g "plaintext";
  g "polygon";
  g "popup_menu";
  g "previous";
  g "resource_allocation_failed";
  g "right";
  g "rotate";
  g "rotate_180";
  g "rotate_270";
  g "rotate_90";
  g "rotate_90_ccw";
  g "rotate_90_cw";
  g "rotate_xz_center_axis";
  g "rotate_x_center_axis";
  g "rotate_yz_center_axis";
  g "rotate_y_center_axis";
  g "route";
  g "sat";
  g "saturday";
  g "sec_decimal";
  g "sec_unit";
  g "scale";
  g "scroll";
  g "scrollbars";
  g "search";
  g "send";
  g "sentence";
  g "separator";
  g "shortest";
  g "show";
  g "signin";
  g "sinusoidal";
  g "socket_image";
  g "soft";
  g "splash";
  g "standard";
  g "start";
  g "state";
  g "statusbar";
  g "stop";
  g "stretch";
  g "sun";
  g "sunday";
  g "terminal";
  g "text";
  g "theme";
  g "theme_fdo";
  g "thu";
  g "thursday";
  g "tile";
  g "toolbar";
  g "tooltip";
  g "top";
  g "top_left";
  g "top_right";
  g "translucent";
  g "transparent";
  g "tree";
  g "tue";
  g "tuesday";
  g "undefined";
  g "unique";
  g "unknown";
  g "unknown_format";
  g "up";
  g "url";
  g "utility";
  g "vertical";
  g "weekly";
  g "wed";
  g "wednesday";
  g "windows_del";
  g "word";
  g "x";
  g "y";
  g "year";
  g "zoom";
  flush stdout
