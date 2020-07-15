open Jest;
open Expect;

exception OhNo;

let passingTest = (~name="generic passing test", ()) =>
  test(name, () =>
    expect(1)->toEqual(1)
  );
let failingTest = (~name="generic passing test", ()) =>
  test(name, () =>
    raise(OhNo)
  );

module OnlyTests = {
  describe("only", () => {
    describeOnly("something that passes", () => passingTest());
    describe("something that fails -- but we have only so it's ok", () =>
      failingTest()
    );
  });
};
