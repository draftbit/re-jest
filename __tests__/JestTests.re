open Jest;
open Expect;

exception OhNo;

module Tests = {
  describe("something", () => {
    test("toMatchSnapshot", () =>
      expect(123)->toMatchSnapshot()
    );
    test("toEqual", () =>
      expect(123)->toEqual(123)
    );
    test("not.toEqual", () =>
      expect(123)->not->toEqual(12345)
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

  test("promises", () => {
    expect(Js.Promise.resolve(123))->resolves->toEqual(123);
    expect(Js.Promise.reject(OhNo))->rejects->toThrowSomething;
  });

  test("arrays", () => {
    let myArray = [|1, 2, 3, 4, 5|];
    expect(myArray)->toContain(4);
  });
};
