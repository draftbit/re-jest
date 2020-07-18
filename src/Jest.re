// Jest requires a function of *no arguments* to be passed into `describe`,
// hence the uncurried function.
[@bs.val] external describeU: (string, (. unit) => unit) => unit = "describe";

let describe: (string, unit => unit) => unit =
  (name, f) => describeU(name, (.) => f());

[@bs.val] [@bs.scope "describe"]
external describeOnlyU: (string, (. unit) => unit) => unit = "only";

let describeOnly: (string, unit => unit) => unit =
  (name, f) => describeOnlyU(name, (.) => f());

[@bs.val] [@bs.scope "describe"]
external describeSkipU: (string, (. unit) => unit) => unit = "skip";

let describeSkip: (string, unit => unit) => unit =
  (name, f) => describeSkipU(name, (.) => f());

// Tests have an optional timeout (third argument)
[@bs.val]
external testU: (string, (. unit) => unit, option(int)) => unit = "test";

let test: (~timeout: int=?, string, unit => unit) => unit =
  (~timeout=?, name, f) => testU(name, (.) => f(), timeout);

[@bs.val] [@bs.scope "test"]
external testOnlyU: (string, (. unit) => unit, option(int)) => unit = "only";

let testOnly: (~timeout: int=?, string, unit => unit) => unit =
  (~timeout=?, name, f) => testOnlyU(name, (.) => f(), timeout);

[@bs.val] [@bs.scope "test"]
external testSkipU: (string, (. unit) => unit, option(int)) => unit = "skip";

let testSkip: (~timeout: int=?, string, unit => unit) => unit =
  (~timeout=?, name, f) => testSkipU(name, (.) => f(), timeout);
