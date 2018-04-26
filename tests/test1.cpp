#include "catch.hpp"
#include <Matrix.hpp>
#include <fstream>
#include <iostream>
TEST_CASE("Creating Matrix") {
    Matrix <int, 3, 2> m6{};

REQUIRE(m6.empty() == true);
}
TEST_CASE("Show Matrix1") {
    Matrix <int, 2, 1> m1{3,5};
    std::string text = "2 1\n3\n5";
    std::ofstream fout("Matrix.bin");
    fout << m1;
    fout.close();
    std::string result;
    std::ifstream fin("Matrix.bin");
    fin >> result;
    fin.close();
    
    REQUIRE(result == text);
}
TEST_CASE("Show size of Matrix") {
   Matrix <int, 2, 1> m1{3,5};
    
    REQUIRE((m1.rows() == 2) && (m1.columns() == 1));
}
TEST_CASE("Matrix comparison") {
    Matrix <int, 2, 1> m1{3,5};
    Matrix <int, 3, 2> m2{1, 2, 3, 4, 5, 6};
    Matrix <int, 3, 2> m3{m2};
    Matrix <int, 3, 2> m4;
    m4 = m3;
    m4[0][0] = 8;
    
    REQUIRE(((m2 == m3) == true) && ((m3 == m4) == false));
}
TEST_CASE("Show Matrix2") {
    Matrix <int, 3, 2> m2{1,2,3,4,5,6};
    std::string text = "3 2\n1 2\n3 4\n5 6";
    std::ofstream fout("Matrix.bin");
    fout << m2;
    fout.close();
    std::string result;
    std::ifstream fin("Matrix.bin");
    fin >> result;
    fin.close();
    
    REQUIRE(result == text);
}
TEST_CASE("Show Matrix3") {
    Matrix <int, 3, 2> m2{1, 2, 3, 4, 5, 6};
    Matrix <int, 3, 2> m3{m2};
    std::string text = "3 2\n1 2\n3 4\n5 6";
    std::ofstream fout("Matrix.bin");
    fout << m3;
    fout.close();
    std::string result;
    std::ifstream fin("Matrix.bin");
    fin >> result;
    fin.close();
    
    REQUIRE(result == text);
}
TEST_CASE("Sum Matrix") {
    Matrix <int, 3, 2> m2{1, 2, 3, 4, 5, 6};
    Matrix <int, 3, 2> m3{m2};
    Matrix <int, 3, 2> m5{0, 2, 4, 6, 8, 10};
    std::string text = "3 2\n1 4\n7 10\n13 16";
    std::ofstream fout("Matrix.bin");
    fout << m3 + m5;
    fout.close();
    std::string result;
    std::ifstream fin("Matrix.bin");
    fin >> result;
    fin.close();
    
    REQUIRE(result == text);
}
TEST_CASE("Diff Matrix") {
    Matrix <int, 3, 2> m2{1, 2, 3, 4, 5, 6};
    Matrix <int, 3, 2> m3{m2};
    Matrix <int, 3, 2> m5{0, 2, 4, 6, 8, 10};
    std::string text = "3 2\n1 2\n3 4\n5 6";
    std::ofstream fout("Matrix.bin");
    fout << m3 - m5;
    fout.close();
    std::string result;
    std::ifstream fin("Matrix.bin");
    fin >> result;
    fin.close();
    
    REQUIRE(result == text);
}
TEST_CASE("Swap Matrix") {
    Matrix <int, 3, 2> m2{1, 2, 3, 4, 5, 6};
    Matrix <int, 3, 2> m3{m2};
    Matrix <int, 3, 2> m6{m3};
    m6[0][0]=15;
    std::string text = "3 2\n15 2\n1 2\n3 4";
    std::ofstream fout("Matrix.bin");
    fout << m3.swap_(m6);
    fout.close();
    std::string result;
    std::ifstream fin("Matrix.bin");
    fin >> result;
    fin.close();
    
    REQUIRE(result == text);
}
