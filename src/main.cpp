#include "Benchmark.h"

#include <fstream>
#include <iostream>
#include <vector>

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

    std::ofstream file("data/benchmark.csv");

    if(!file)
    {
        std::cerr << "Failed to open benchmark.csv\n";

        return 1;
    }

    file
        << "Size,"
        << "BSTRandomMs,"
        << "BSTBalancedMs,"
        << "StdSetMs,"
        << "BSTRandomHeight,"
        << "BSTBalancedHeight"
        <<"BSTRemove,"
        <<"SETRemove\n";

    std::ofstream rmfile("data/data.csv");

    if(!rmfile)
    {
        std::cerr << "Failed to open benchmark.csv\n";

        return 1;
    }

    

    for(int size : sizes)
    {
        int randomHeight = 0;
        int balancedHeight = 0;

        double randomTime = AverageRandomBST(size, runs, randomHeight);

        double balancedTime = AverageBalancedBST(size, runs, balancedHeight);

        double setTime = AverageStdSet(size, runs);

        double deleteBST = AverageDeleteBST(size, runs);
        
        double deleteSet = AverageDeleteStdSet(size, runs);

        file
            << size << ","
            << randomTime << ","
            << balancedTime << ","
            << setTime << ","
            << randomHeight << ","
            << balancedHeight << ","
            << deleteBST << ","
            << deleteSet
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
            <<'\n\n'
            << " | delete BST: "
            << deleteBST
            << " ms"
            << " | delete Set: "
            << deleteSet
            << " ms"
            << '\n\n';
    }

    file.close();

    std::cout << "\nBenchmark complete.\n";
    //--------------------------------------------------------------------

    return 0;
}