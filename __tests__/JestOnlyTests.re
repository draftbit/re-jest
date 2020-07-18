// These have to go in their own module because otherwise the `only`
// will cause all other tests to be skipped.

open TestLib;

module OnlyTests = {
  describe("only", () => {
    describeOnly("something that passes", () => passingTest());
    describe("something that fails -- but we have only so it's ok", () =>
      failingTest()
    );
  });
};
