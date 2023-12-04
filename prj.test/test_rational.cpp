#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "rational/rational.hpp"



TEST_CASE("rational ctor") {
    Rational r_def;
    CHECK(0 == r_def.num_);
    CHECK(1 == r_def.den_);

    Rational r_int(3);
    CHECK(3 == r_int.num_);
    CHECK(1 == r_int.den_);

    CHECK_THROWS(Rational(1, 0));
}
