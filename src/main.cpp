#include "Benchmark.h"

#include <fstream>
#include <iostream>
#include <vector>

// Benchmark.cpp functions

double AverageRandomBST(
    int size,
    int runs,
    int& averageHeight
);

double AverageBalancedBST(
    int size,
    int runs,
    int& averageHeight
);

double AverageStdSet(
    int size,
    int runs
);

int main()
{
    std::vector<int> sizes =
    {
        127,
        255,
        511,
        1023,
        2047,
        4095,
        8191,
        16383
    };

    constexpr int runs = 20;

    std::ofstream file(
        "data/benchmark.csv"
    );

    if(!file)
    {
        std::cerr
            << "Failed to open benchmark.csv\n";

        return 1;
    }

    file
        << "Size,"
        << "BSTRandomMs,"
        << "BSTBalancedMs,"
        << "StdSetMs,"
        << "BSTRandomHeight,"
        << "BSTBalancedHeight\n";

    for(int size : sizes)
    {
        int randomHeight = 0;
        int balancedHeight = 0;

        double randomTime =
            AverageRandomBST(
                size,
                runs,
                randomHeight
            );

        double balancedTime =
            AverageBalancedBST(
                size,
                runs,
                balancedHeight
            );

        double setTime =
            AverageStdSet(
                size,
                runs
            );

        file
            << size << ","
            << randomTime << ","
            << balancedTime << ","
            << setTime << ","
            << randomHeight << ","
            << balancedHeight
            << '\n';

        std::cout
            << "Size: " << size
            << " | BST Random: "
            << randomTime
            << " ms"
            << " | BST Balanced: "
            << balancedTime
            << " ms"
            << " | std::set: "
            << setTime
            << " ms"
            << " | Random Height: "
            << randomHeight
            << " | Balanced Height: "
            << balancedHeight
            << '\n';
    }

    file.close();

    std::cout
        << "\nBenchmark complete.\n";

    return 0;
}