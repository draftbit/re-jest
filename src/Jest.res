// Jest requires a function of *no arguments* to be passed into `describe`,
// hence the uncurried function.
@val external describeU: (string, (. unit) => unit) => unit = "describe"

let describe: (string, unit => unit) => unit = (name, f) => describeU(name, (. ()) => f())

// Tests have an optional timeout (third argument)
@val
external testU: (string, (. unit) => unit, option<int>) => unit = "test"

let test: (~timeout: int=?, string, unit => unit) => unit = (~timeout=?, name, f) =>
  testU(name, (. ()) => f(), timeout)

@val
external testAsyncU: (string, (. unit) => Js.Promise.t<unit>, option<int>) => unit = "test"

let testAsync: (~timeout: int=?, string, unit => Js.Promise.t<unit>) => unit = (
  ~timeout=?,
  name,
  f,
) => testAsyncU(name, (. ()) => f(), timeout)

module Only = {
  @val @scope("describe")
  external describeU: (string, (. unit) => unit) => unit = "only"

  let describe: (string, unit => unit) => unit = (name, f) => describeU(name, (. ()) => f())

  @val @scope("test")
  external testU: (string, (. unit) => unit, option<int>) => unit = "only"

  let test: (~timeout: int=?, string, unit => unit) => unit = (~timeout=?, name, f) =>
    testU(name, (. ()) => f(), timeout)

  @val @scope("test")
  external testAsyncU: (string, (. unit) => Js.Promise.t<unit>, option<int>) => unit = "only"

  let testAsync: (~timeout: int=?, string, unit => Js.Promise.t<unit>) => unit = (
    ~timeout=?,
    name,
    f,
  ) => testAsyncU(name, (. ()) => f(), timeout)
}

module Skip = {
  @val @scope("describe")
  external describeU: (string, (. unit) => unit) => unit = "skip"

  let describe: (string, unit => unit) => unit = (name, f) => describeU(name, (. ()) => f())

  @val @scope("test")
  external testU: (string, (. unit) => unit, option<int>) => unit = "skip"

  let test: (~timeout: int=?, string, unit => unit) => unit = (~timeout=?, name, f) =>
    testU(name, (. ()) => f(), timeout)

  @val @scope("test")
  external testAsyncU: (string, (. unit) => Js.Promise.t<unit>, option<int>) => unit = "skip"

  let testAsync: (~timeout: int=?, string, unit => Js.Promise.t<unit>) => unit = (
    ~timeout=?,
    name,
    f,
  ) => testAsyncU(name, (. ()) => f(), timeout)
}

@val external beforeAllU: ((. unit) => unit) => unit = "beforeAll"

let beforeAll: (unit => unit) => unit = f => beforeAllU((. ()) => f())

@val external beforeEachU: ((. unit) => unit) => unit = "beforeEach"

let beforeEach: (unit => unit) => unit = f => beforeEachU((. ()) => f())

@val external afterAllU: ((. unit) => unit) => unit = "afterAll"

let afterAll: (unit => unit) => unit = f => afterAllU((. ()) => f())

@val external afterEachU: ((. unit) => unit) => unit = "afterEach"

let afterEach: (unit => unit) => unit = f => afterEachU((. ()) => f())

@val
external beforeAllAsyncU: ((. unit) => Js.Promise.t<unit>) => unit = "beforeAll"
let beforeAllAsync: (unit => Js.Promise.t<unit>) => unit = f => beforeAllAsyncU((. ()) => f())

@val
external beforeEachAsyncU: ((. unit) => Js.Promise.t<unit>) => unit = "beforeEach"
let beforeEachAsync: (unit => Js.Promise.t<unit>) => unit = f => beforeEachAsyncU((. ()) => f())

@val
external afterAllAsyncU: ((. unit) => Js.Promise.t<unit>) => unit = "afterAll"
let afterAllAsync: (unit => Js.Promise.t<unit>) => unit = f => afterAllAsyncU((. ()) => f())

@val
external afterEachAsyncU: ((. unit) => Js.Promise.t<unit>) => unit = "afterEach"
let afterEachAsync: (unit => Js.Promise.t<unit>) => unit = f => afterEachAsyncU((. ()) => f())
