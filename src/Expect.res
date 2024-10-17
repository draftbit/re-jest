type t<'a>

@val external expect: 'a => t<'a> = "expect"

@bs.send external toEqual: (t<'a>, 'a) => unit = "toEqual"
@bs.send external toBe: (t<'a>, 'a) => unit = "toBe"
@get external not_: t<'a> => t<'a> = "not"
@bs.send
external toMatchSnapshot: (t<'a>, unit) => unit = "toMatchSnapshot"

@bs.send external toThrowSomething: t<'a => 'b> => unit = "toThrow"

@bs.send external toBeGreaterThan: (t<'a>, 'a) => unit = "toBeGreaterThan"
@bs.send external toBeLessThan: (t<'a>, 'a) => unit = "toBeLessThan"
@bs.send
external toBeGreaterThanOrEqual: (t<'a>, 'a) => unit = "toBeGreaterThanOrEqual"
@bs.send
external toBeLessThanOrEqual: (t<'a>, 'a) => unit = "toBeLessThanOrEqual"

@get
external rejects: t<Js.Promise.t<'a>> => t<unit => 'a> = "rejects"

@bs.send external toContain: (t<array<'a>>, 'a) => unit = "toContain"

// This isn't a real string, but it can be used to construct a predicate on a string
// expect("hello world")->toEqual(stringContaining("hello"));
@val @scope("expect")
external stringContaining: string => string = "stringContaining"

// This isn't a real array, but it can be used to construct a predicate on an array
// expect([|"x", "y", "z"|])->toEqual(arrayContaining([|"x", "z"|]))
@val @scope("expect")
external arrayContaining: array<'a> => array<'a> = "arrayContaining"
