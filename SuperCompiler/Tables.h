#pragma once
#include "TokenExtend.h"
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>

/* 10 - целочисленные, 20 - вещественные, 11 - 2д цел, 21 - 2д цел */
int TableMode = 0;
std::map<std::string, int> INTS;
std::map<std::string, float> FLOATS;
std::map<std::string, int*> INTS2D;
std::map<std::string, float*> FLOATS2D;
