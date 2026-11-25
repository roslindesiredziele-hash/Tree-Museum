#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <Windows.h>

#include <vector>

double AverageRandomBST(int,int,int&);

double AverageBalancedBST(int,int,int&);

double AverageStdSet(int, int);

double MeasureMilliseconds(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq);

double BenchmarkRandomBST(int size,int& height);

double BenchmarkBalancedBST(int size, int& height);

double BenchmarkStdSet(int size);

double AverageRandomBST(int size, int runs, int& averageHeight);

double AverageBalancedBST(int size, int runs, int& averageHeight);

double AverageStdSet(int size, int runs);

void ShuffleKeys(std::vector<int>& keys);
//--------------------------------------------------------------------------------------------------

double AverageDeleteBST(int, int);

double AverageDeleteStdSet(int, int);

double BenchmarkDeleteBST(int size);

double BenchmarkDeleteStdSet(int size);
//--------------------------------------------------------------------------------------------------

double BenchmarkAVL(int, int&);

double AverageAVL(int, int, int&);

double BenchmarkDeleteAVL(int);

double AverageDeleteAVL(int, int);

double BenchmarkTernary(int, int&);

double AverageTernary(int, int, int&);

#endif