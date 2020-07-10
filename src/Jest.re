// Jest requires a function of *no arguments* to be passed into `describe`,
// hence the uncurried function.
[@bs.val] external describeU: (string, (. unit) => unit) => unit = "describe";

let describe: (string, unit => unit) => unit =
  (name, f) => describeU(name, (.) => f());

// Tests have an optional timeout (third argument)
[@bs.val]
external testU: (string, (. unit) => unit, option(int)) => unit = "test";

let test: (~timeout: int=?, string, unit => unit) => unit =
  (~timeout=?, name, f) => testU(name, (.) => f(), timeout);
