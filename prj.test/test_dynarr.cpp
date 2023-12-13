#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "dynarr/dynarr.hpp"

TEST_CASE("dynarr ctor") {
    DynArr arr_def;
    CHECK_EQ(arr_def.Size(), 0);

    const int size = 5;
    DynArr arr_s(size);
    CHECK_EQ(arr_s.Size(), size);
}

TEST_CASE("dynarr op[]") {
    const int size = 5;
    DynArr arr(size);
    CHECK_EQ(arr[0], 0);
    CHECK_EQ(arr[arr.Size() - 1], 0);
}

TEST_CASE("dynarr op=") {
    const int size = 3;
    DynArr arr_eq(size);
    DynArr arr_new = arr_eq;
    CHECK_EQ(arr_new, arr_eq);
}

TEST_CASE("dynarr resize+") {
    DynArr arr_bef(3);
    int res_size = 5;
    arr_bef.Resize(res_size);
    CHECK_EQ(arr_bef.Size(), 5);
}

TEST_CASE("dynarr resize-") {
    DynArr arr_bef(5);
    int res_size = 3;
    arr_bef.Resize(res_size);
    CHECK_EQ(arr_bef.Size(), 3);
}

TEST_CASE("dynarr empty&not") {
    DynArr emp_arr;
    CHECK_NOTHROW(emp_arr[0]);
    CHECK_EQ(emp_arr.Size(), 0);
    DynArr not_emp_arr(2);
    CHECK_NOTHROW(not_emp_arr[0]);
}
