#include "Benchmark.h"
#include "BST.h"
#include "AVL.h"
#include "TernaryTree.h"
#include "../Utils/Utils.h"

#include <Windows.h>

#include <algorithm>

#include <random>
#include <set>
#include <vector>

double MeasureMilliseconds(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq)
{
    return static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
}

void ShuffleKeys(std::vector<int>& keys)
{
    static std::random_device rd;

    static std::mt19937 gen(rd());

    std::shuffle(keys.begin(), keys.end(), gen);
}

double BenchmarkRandomBST(int size,int& height)
{
    std::vector<int> keys = GenerateKeys(size);

    ShuffleKeys(keys);

    BST tree;

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    for(int key : keys)
    {
        tree.insert(key);
    }

    QueryPerformanceCounter(&end);

    height = tree.height();

    return MeasureMilliseconds(start, end, freq);
}

double BenchmarkBalancedBST(int size, int& height)
{
    std::vector<int> keys = GenerateKeys(size);

    std::vector<int> balanced = GenerateBalancedOrder(keys);

    BST tree;

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    for(int key : balanced)
    {
        tree.insert(key);
    }

    QueryPerformanceCounter(&end);

    height = tree.height();

    return MeasureMilliseconds(start, end, freq);
}

double BenchmarkStdSet(int size)
{
    std::vector<int> keys = GenerateKeys(size);

    ShuffleKeys(keys);

    std::set<int> tree;

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    for(int key : keys)
    {
        tree.insert(key);
    }

    QueryPerformanceCounter(&end);

    return MeasureMilliseconds(start, end, freq);
}

double AverageRandomBST(int size, int runs, int& averageHeight)
{
    double totalTime = 0;

    long long totalHeight = 0;

    for(int i = 0; i < runs; i++)
    {
        int height = 0;

        totalTime += BenchmarkRandomBST(size, height);

        totalHeight += height;
    }

    averageHeight = static_cast<int>(totalHeight / runs);

    return totalTime / runs;
}

double AverageBalancedBST(int size, int runs, int& averageHeight)
{
    double totalTime = 0;

    long long totalHeight = 0;

    for(int i = 0; i < runs; i++)
    {
        int height = 0;

        totalTime += BenchmarkBalancedBST(size, height);

        totalHeight += height;
    }

    averageHeight = static_cast<int>(totalHeight / runs);

    return totalTime / runs;
}

double AverageStdSet(int size, int runs
)
{
    double totalTime = 0;

    for(int i = 0; i < runs; i++)
    {
        totalTime += BenchmarkStdSet(size);
    }

    return totalTime / runs;
}

//--------------------------------------------------------------------------------------

double BenchmarkDeleteBST(int size)
{
    std::vector<int> keys = GenerateKeys(size);

    ShuffleKeys(keys);

    BST tree;

    for(int key : keys)
    {
        tree.insert(key);
    }

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    for(int key : keys)
    {
        tree.remove(key);
    }

    QueryPerformanceCounter(&end);

    return MeasureMilliseconds(start, end, freq);
}

double BenchmarkDeleteStdSet(int size)
{
    std::vector<int> keys = GenerateKeys(size);

    ShuffleKeys(keys);

    std::set<int> tree;

    for(int key : keys)
    {
        tree.insert(key);
    }

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    for(int key : keys)
    {
        tree.erase(key);
    }

    QueryPerformanceCounter(&end);

    return MeasureMilliseconds(start, end, freq);
}

double AverageDeleteBST(int size, int runs)
{
    double total = 0;

    for(int i = 0; i < runs; i++)
    {
        total += BenchmarkDeleteBST(size);
    }

    return total / runs;
}

double AverageDeleteStdSet(int size, int runs)
{
    double total = 0;

    for(int i = 0; i < runs; i++)
    {
        total += BenchmarkDeleteStdSet(size);
    }

    return total / runs;
}

//-------------------------------------------------------------------------

double BenchmarkAVL(int size, int& height)
{
    std::vector<int> keys = GenerateKeys(size);

    ShuffleKeys(keys);

    AVL tree;

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    for(int key : keys)
    {
        tree.insert(key);
    }

    QueryPerformanceCounter(&end);

    height = tree.height();

    return MeasureMilliseconds(start, end, freq);
}

double AverageAVL(int size, int runs, int& avgHeight)
{
    double total = 0;

    avgHeight = 0;

    for(int i = 0;
        i < runs;
        i++)
    {
        int h = 0;

        total += BenchmarkAVL(size, h);

        avgHeight += h;
    }

    avgHeight /= runs;

    return total / runs;
}

double BenchmarkDeleteAVL(int size)
{
    std::vector<int> keys = GenerateKeys(size);

    ShuffleKeys(keys);

    AVL tree;

    for(int key : keys)
    {
        tree.insert(key);
    }

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    for(int key : keys)
    {
        tree.remove(key);
    }

    QueryPerformanceCounter(&end);

    return MeasureMilliseconds(start, end, freq);
}

double AverageDeleteAVL(int size, int runs)
{
    double total = 0;

    for(int i = 0;
        i < runs;
        i++)
    {
        total += BenchmarkDeleteAVL(size);
    }

    return total / runs;
}

double BenchmarkTernary(int size, int& height)
{
    std::vector<int> keys = GenerateKeys(size);

    ShuffleKeys(keys);

    TernaryTree tree;

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    for(int key : keys)
    {
        tree.insert(key);
    }

    QueryPerformanceCounter(&end);

    height = tree.height();

    return MeasureMilliseconds(start, end, freq);
}

double AverageTernary(int size, int runs, int& averageHeight)
{
    double totalTime = 0;

    long long totalHeight = 0;

    for(int i = 0; i < runs; i++)
    {
        int height = 0;

        totalTime += BenchmarkTernary(size, height);

        totalHeight += height;
    }

    averageHeight = static_cast<int>(totalHeight / runs);

    return totalTime / runs;
}

double BenchmarkBalancedTernary(int size, int& height)
{
    std::vector<int> keys = GenerateKeys(size);

    std::vector<int> balanced = GenerateBalancedTernaryOrder(keys);

    TernaryTree tree;

    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    QueryPerformanceCounter(&start);

    for(int key : balanced)
    {
        tree.insert(key);
    }

    QueryPerformanceCounter(&end);

    height =
        tree.height();

    return MeasureMilliseconds(start, end, freq);
}