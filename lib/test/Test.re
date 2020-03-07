let check = (Case.{expected, actual}) =>
  Alcotest.(check(Case.testable, "same string", expected, actual));

module Ok__FieldWithSyncValidator = {
  let id = "Ok: field with sync validator";
  let case = () => Case.ok("Ok__FieldWithSyncValidator") |> check;
};

module Ok__FieldWithSyncValidatorAndFieldWithNoValidator = {
  let id = "Ok: field with sync validator and field with no validator";
  let case = () =>
    Case.ok("Ok__FieldWithSyncValidatorAndFieldWithNoValidator") |> check;
};

module Ok__FieldWithSyncValidatorsAndCollectionWithNoCollectionValidatorAndFieldWithSyncValidator = {
  let id = "Ok: field with sync validators and collection with no collection validator and field with sync validator";
  let case = () =>
    Case.ok(
      "Ok__FieldWithSyncValidatorsAndCollectionWithNoCollectionValidatorAndFieldWithSyncValidator",
    )
    |> check;
};

module Error__InputNotFound = {
  let id = "Error: input not found";
  let case = () => Case.error("Error__InputNotFound") |> check;
};

module Error__InputNotRecord = {
  let id = "Error: input not record";
  let case = () => Case.error("Error__InputNotRecord") |> check;
};

let () =
  Alcotest.(
    run(
      "Ppx",
      [
        (
          "oks",
          [
            test_case(
              Ok__FieldWithSyncValidator.id,
              `Quick,
              Ok__FieldWithSyncValidator.case,
            ),
            test_case(
              Ok__FieldWithSyncValidatorAndFieldWithNoValidator.id,
              `Quick,
              Ok__FieldWithSyncValidatorAndFieldWithNoValidator.case,
            ),
            test_case(
              Ok__FieldWithSyncValidatorsAndCollectionWithNoCollectionValidatorAndFieldWithSyncValidator.id,
              `Quick,
              Ok__FieldWithSyncValidatorsAndCollectionWithNoCollectionValidatorAndFieldWithSyncValidator.case,
            ),
          ],
        ),
        (
          "errors",
          [
            test_case(
              Error__InputNotFound.id,
              `Quick,
              Error__InputNotFound.case,
            ),
            test_case(
              Error__InputNotRecord.id,
              `Quick,
              Error__InputNotRecord.case,
            ),
          ],
        ),
      ],
    )
  );
