[@bs.val] external beforeAllU: ((. unit) => unit) => unit = "beforeAll";

let beforeAll: (unit => unit) => unit = f => beforeAllU((.) => f());

[@bs.val] external beforeEachU: ((. unit) => unit) => unit = "beforeEach";

let beforeEach: (unit => unit) => unit = f => beforeEachU((.) => f());

[@bs.val] external afterAllU: ((. unit) => unit) => unit = "afterAll";

let afterAll: (unit => unit) => unit = f => afterAllU((.) => f());

[@bs.val] external afterEachU: ((. unit) => unit) => unit = "afterEach";

let afterEach: (unit => unit) => unit = f => afterEachU((.) => f());

[@bs.val]
external beforeAllAsyncU: ((. unit) => Js.Promise.t(unit)) => unit =
  "beforeAll";
let beforeAllAsync: (unit => Js.Promise.t(unit)) => unit =
  f => beforeAllAsyncU((.) => f());

[@bs.val]
external beforeEachAsyncU: ((. unit) => Js.Promise.t(unit)) => unit =
  "beforeEach";
let beforeEachAsync: (unit => Js.Promise.t(unit)) => unit =
  f => beforeEachAsyncU((.) => f());

[@bs.val]
external afterAllAsyncU: ((. unit) => Js.Promise.t(unit)) => unit =
  "afterAll";
let afterAllAsync: (unit => Js.Promise.t(unit)) => unit =
  f => afterAllAsyncU((.) => f());

[@bs.val]
external afterEachAsyncU: ((. unit) => Js.Promise.t(unit)) => unit =
  "afterEach";
let afterEachAsync: (unit => Js.Promise.t(unit)) => unit =
  f => afterEachAsyncU((.) => f());
