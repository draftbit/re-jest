open TestLib;

module Tests = {
  describe("something", () => {
    test("toEqual", () =>
      expect(123)->toEqual(123)
    );

    test("not.toEqual", () =>
      expect(123)->not->toEqual(12345)
    );

    test("toMatchSnapshot", () =>
      expect(123)->toMatchSnapshot()
    );

    test("toThrowSomething", () =>
      expect(() =>
        raise(OhNo)
      )->toThrowSomething
    );

    test("not.toThrowSomething", () =>
      expect(() =>
        123
      )->not->toThrowSomething
    );
  });

  test("stringContaining", () => {
    expect("hello world")->toEqual(stringContaining("hello"))
  });

  test("arrayContaining", () => {
    expect([|"x", "y", "z"|])->toEqual(arrayContaining([|"x", "z"|]))
  });

  test("numbers", () => {
    let myNumber = 123;
    expect(myNumber)->toBeGreaterThan(100);
    expect(myNumber)->toBeLessThan(200);
    expect(myNumber)->toBeGreaterThanOrEqual(123);
    expect(myNumber)->toBeLessThanOrEqual(123);
    expect(myNumber)->not->toBeLessThanOrEqual(1);

    // It also works for floats...
    expect(myNumber->float_of_int)->toBeLessThan(124.0);
  });

  testAsync("async", () =>
    Js.Promise.(
      resolve(123)
      |> then_(n => {
           expect(n)->toEqual(123);
           resolve();
         })
    )
  );

  testAsync("async", () =>
    Js.Promise.(
      resolve(123)
      |> then_(n => {
           expect(n)->toEqual(123);
           expect(n)->not->toEqual(124);
           resolve();
         })
    )
  );

  // todo test asyncs that fail

  describe("skip", () => {
    Skip.test("this test should get skipped", () =>
      raise(OhNo)
    )
  });

  describeSkip("none of these should be run", () => {
    failingTest(~name="this test will fail if it gets run!", ())
  });

  test("arrays", () => {
    let myArray = [|1, 2, 3, 4, 5|];
    expect(myArray)->toContain(4);
  });

  describe("setup", () => {
    describe("sync", () => {
      let count = ref(None);
      beforeAll(() => {count := Some(0)});
      beforeEach(() => count := Some((count^)->Belt.Option.getExn + 1));
      afterEach(() => count := Some((count^)->Belt.Option.getExn + 1));

      passingTest();
      passingTest();
      passingTest();
      test("got the right count", () =>
        expect(count^)->toEqual(Some(7))
      );
    });

    describe("async", () => {
      let count = ref(None);
      beforeAllAsync(() => Js.Promise.resolve(count := Some(0)));
      beforeEachAsync(() =>
        Js.Promise.resolve(count := Some((count^)->Belt.Option.getExn + 1))
      );
      afterEachAsync(() =>
        Js.Promise.resolve(count := Some((count^)->Belt.Option.getExn + 1))
      );

      passingTest();
      passingTest();
      passingTest();
      test("got the right count", () =>
        expect(count^)->toEqual(Some(7))
      );
    });
  });
};
