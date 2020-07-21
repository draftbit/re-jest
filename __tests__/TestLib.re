include Jest;
include Expect;

exception OhNo;

module Promise = {
  let map = (prom, next) =>
    prom |> Js.Promise.(then_(x => resolve(next(x))));
};

let passingTest = (~name="generic passing test", ()) =>
  test(name, () =>
    expect(1)->toEqual(1)
  );
let failingTest = (~name="generic passing test", ()) =>
  test(name, () =>
    raise(OhNo)
  );
