#include <catch.hpp>
#include "Matrix.hpp"
#include <sstream>
TEST_CASE("Creating Matrix") {
    Matrix <int, 3, 2> m6{};

REQUIRE(m6.empty() == true);
}
TEST_CASE("Show size of Matrix") {
   Matrix <int, 2, 1> m1{3,5};
    
    REQUIRE(m1.rows() == 2);
    REQUIRE(m1.columns() == 1);
}
TEST_CASE("Matrix comparison") {
    Matrix <int, 2, 1> m1{3,5};
    Matrix <int, 3, 2> m2{1, 2, 3, 4, 5, 6};
    Matrix <int, 3, 2> m3{m2};
    Matrix <int, 3, 2> m4;
    int flag1, flag2; 
    m4 = m3;
    m4[0][0] = 8;
    if (m2 == m3) 
        flag1 = 1;
    else
        flag1 = 0;
    if (m3 == m4) 
        flag2 = 1;
    else
        flag2 = 0;
    REQUIRE(flag1 == 1);
    REQUIRE(flag2 == 0);
}

