//
//  main.cpp
//  MatrixRK
//
//  Created by Алексей Мирный on 26.04.2018.
//  Copyright © 2018 alexey. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Matrix.hpp"

int main()
{
    
    Matrix <int, 2, 1> m1{3,5};
    Matrix <int, 3, 2> m2{1, 2, 3, 4, 5, 6};
    Matrix <int, 3, 2> m3{m2};
    
    std::cout << m1 << std::endl;
    std::cout << m2 << std::endl;
    std::cout << m3 << std::endl;
    
    Matrix <int, 3, 2> m4;
    m4 = m3;
    std::cout << m4 << std::endl;
    
    m4[0][0] = 8;
    std::cout << m4 << std::endl;
    
    std::cout << std::boolalpha  << (m2 == m3) << " " << (m3 == m4) << std::endl;
    
    std::cout << m1.rows() << " " << m1.columns() << std::endl;
    std::cout << std::endl;
    
    Matrix <int, 3, 2> m5{0, 2, 4, 6, 8, 10};
    std::cout << m5 << std::endl;
    std::cout << std::endl;
    
    std::cout << m3 + m5 << std::endl;
    std::cout << m3 - m5 << std::endl;
    
    Matrix <int, 3, 2> m6{};
    std::cout << m6.empty() << std::endl;
    
    std::ofstream fout("Matrix.bin");
    fout << m3;
    fout.close();
    std::ifstream fin("Matrix.bin");
    fin >> m6;
    fin.close();
    
    m6[0][0] = 15;
    m3.swap_(m6);
    
    std::cout << m3 << std::endl;
}
