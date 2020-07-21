// Tests have an optional timeout (third argument)
[@bs.val]
external testU: (string, (. unit) => unit, option(int)) => unit = "test";

let test: (~timeout: int=?, string, unit => unit) => unit =
  (~timeout=?, name, f) => testU(name, (.) => f(), timeout);

[@bs.val]
external testAsyncU:
  (string, (. unit) => Js.Promise.t(unit), option(int)) => unit =
  "test";

let testAsync: (~timeout: int=?, string, unit => Js.Promise.t(unit)) => unit =
  (~timeout=?, name, f) => testAsyncU(name, (.) => f(), timeout);

[@bs.val] [@bs.scope "test"]
external testOnlyU: (string, (. unit) => unit, option(int)) => unit = "only";

let testOnly: (~timeout: int=?, string, unit => unit) => unit =
  (~timeout=?, name, f) => testOnlyU(name, (.) => f(), timeout);

[@bs.val] [@bs.scope "test"]
external testSkipU: (string, (. unit) => unit, option(int)) => unit = "skip";

let testSkip: (~timeout: int=?, string, unit => unit) => unit =
  (~timeout=?, name, f) => testSkipU(name, (.) => f(), timeout);
