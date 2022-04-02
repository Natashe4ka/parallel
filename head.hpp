#ifndef head_hpp
#define head_hpp


#include <stdio.h>

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <omp.h>

#include <chrono>
#include <random>

#include "CIntN.hpp"
#include "CIntN0.hpp"
#include "CIntN1.hpp"

void MeasTime();

 CIntN0 operator-(const CIntN&, const CIntN&);
 CIntN0 operator+(const CIntN&, const CIntN&);


#endif 
