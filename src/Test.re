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

module Only = {
  [@bs.val] [@bs.scope "test"]
  external testU: (string, (. unit) => unit, option(int)) => unit = "only";

  let test: (~timeout: int=?, string, unit => unit) => unit =
    (~timeout=?, name, f) => testU(name, (.) => f(), timeout);

  [@bs.val] [@bs.scope "test"]
  external testAsyncU:
    (string, (. unit) => Js.Promise.t(unit), option(int)) => unit =
    "only";

  let testAsync: (~timeout: int=?, string, unit => Js.Promise.t(unit)) => unit =
    (~timeout=?, name, f) => testAsyncU(name, (.) => f(), timeout);
};

module Skip = {
  [@bs.val] [@bs.scope "test"]
  external testU: (string, (. unit) => unit, option(int)) => unit = "skip";

  let test: (~timeout: int=?, string, unit => unit) => unit =
    (~timeout=?, name, f) => testU(name, (.) => f(), timeout);

  [@bs.val] [@bs.scope "test"]
  external testAsyncU:
    (string, (. unit) => Js.Promise.t(unit), option(int)) => unit =
    "skip";

  let testAsync: (~timeout: int=?, string, unit => Js.Promise.t(unit)) => unit =
    (~timeout=?, name, f) => testAsyncU(name, (.) => f(), timeout);
};
