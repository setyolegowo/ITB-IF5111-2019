/**
 * main.cpp file.
 * Main.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#include <iostream>
#include <fstream>
#include <sys/time.h>

#include "algo/base_algo.hpp"
#include "algo/binary_search_tree.hpp"
#include "node_structure.hpp"

/**
 * Returns the current time in microseconds.
 */
long getMicrotime()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void readFile(char* filename, std::vector<House>* houseList)
{
    std::ifstream csvfile(filename);
    std::string line = "";
    getline(csvfile, line);
    while (getline(csvfile, line))
    {
        houseList->push_back(House::createFromString(line));
    }
    csvfile.close();
}

BaseAlgorithm * chooseAlgorithm(char* choose, int argc, char** argv)
{
    if (strcmp(choose, "binary") == 0) {
        std::cout << "Using binary search" << std::endl;
        return new BinarySearch();
    }
    return 0;
}

int main(int argc, char** argv)
{
    if (argc < 3) {
        std::cerr << "Lack of arguments: " << argv[0] << " <datafile> <algorithm>" << std::endl;
        return -127;
    }

    BaseAlgorithm * algo = chooseAlgorithm(argv[2], argc, argv);
    if (algo == 0) {
        std::cerr << "The algorithm is not found" << std::endl;
        return -127;
    }

    long start_time, finish_time;
    std::vector<House> houseList;
    readFile(argv[1], &houseList);

    start_time = getMicrotime();
    if (algo->find(&houseList)) {
        std::cout << "FOUND" << std::endl;
    } else {
        std::cout << "NOT FOUND" << std::endl;
    }
    finish_time = getMicrotime();

    std::cout << (finish_time - start_time) << " microseconds" << std::endl;

    return 0;
}
