open TestLib;

module OnlyTests = {
  describe("only", () => {
    describeOnly("something that passes", () => passingTest());
    describe("something that fails -- but we have only so it's ok", () =>
      failingTest()
    );
  });
};
