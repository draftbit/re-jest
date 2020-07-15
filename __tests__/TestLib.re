include Jest;
include Expect;

exception OhNo;

let passingTest = (~name="generic passing test", ()) =>
  test(name, () =>
    expect(1)->toEqual(1)
  );
let failingTest = (~name="generic passing test", ()) =>
  test(name, () =>
    raise(OhNo)
  );
