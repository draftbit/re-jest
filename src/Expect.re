type t('a);

[@bs.val] external expect: 'a => t('a) = "expect";

[@bs.send] external toEqual: (t('a), 'a) => unit = "toEqual";
[@bs.get] external not: t('a) => t('a) = "not";
[@bs.send]
external toMatchSnapshot: (t('a), unit) => unit = "toMatchSnapshot";
[@bs.send] external toThrowSomething: t('a => 'b) => unit = "toThrow";

[@bs.send] external toBeGreaterThan: (t('a), 'a) => unit = "toBeGreaterThan";
[@bs.send] external toBeLessThan: (t('a), 'a) => unit = "toBeLessThan";
[@bs.send]
external toBeGreaterThanOrEqual: (t('a), 'a) => unit =
  "toBeGreaterThanOrEqual";
[@bs.send]
external toBeLessThanOrEqual: (t('a), 'a) => unit = "toBeLessThanOrEqual";

[@bs.get]
external resolves: t(Js.Promise.t('a)) => Js.Promise.t(t('a)) = "resolves";

//let expectAsync: t(Js.Promise.t('a)) => (t('a) => unit) => unit = (expect, withExpect) => Js.Promise.then_

[@bs.get]
external rejects: t(Js.Promise.t('a)) => t(unit => 'a) = "rejects";

[@bs.send] external toContain: (t(array('a)), 'a) => unit = "toContain";
