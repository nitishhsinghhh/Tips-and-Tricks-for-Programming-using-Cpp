#include "testPassByValue.h"
#include "testPassByAddress.h"
#include "testPassByReference.h"
#include <iostream>

int main() {
    // pass by value
    testPassByValue tester;
    tester.run_tests();

    // pass by reference
    testPassByReference testerRef;
    testerRef.run_tests();

    // pass by address
    testPassByAddress testerAdd;
    testerAdd.run_tests();

}
