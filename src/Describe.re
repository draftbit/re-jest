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
