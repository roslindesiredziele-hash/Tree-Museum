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

double AverageDeleteBST(int, int);

double AverageDeleteStdSet(int, int);

#endif