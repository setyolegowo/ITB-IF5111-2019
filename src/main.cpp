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
#include <cstring>

#include "algo/base_algo.hpp"
#include "algo/index_search.hpp"
#include "algo/binary_search_tree.hpp"
#include "algo/linear_search.hpp"
#include "algo/log_linear_search.hpp"
#include "algo/shortest_path.hpp"
#include "algo/square_delivery.hpp"
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

void readFile(char* filename, std::vector<House>* houseList, size_t max_data)
{
    std::ifstream csvfile(filename);
    std::string line = "";

    getline(csvfile, line);
    for (uint32_t count = 0; getline(csvfile, line) && count < max_data; count++)
    {
        houseList->push_back(House::createFromString(line));
    }

    csvfile.close();
}

BaseAlgorithm * chooseAlgorithm(char* choose, int argc, char** argv)
{
    if (strcmp(choose, "index") == 0) {
        std::cout << "Using index search" << std::endl;
        return IndexSearch::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "binary") == 0) {
        std::cout << "Using binary search" << std::endl;
        return BinarySearch::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "linear") == 0) {
        std::cout << "Using linear search" << std::endl;
        return LinearSearch::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "loglin") == 0) {
        std::cout << "Using log linear search" << std::endl;
        return LogLinearSearch::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "shortest") == 0) {
        std::cout << "Using shortest path" << std::endl;
        return ShortestPath::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "square") == 0) {
        std::cout << "Using square delivery" << std::endl;
        return SquareDelivery::createFromConsoleArgument(argc, argv);
    }
    return 0;
}

int main(int argc, char** argv)
{
    if (argc < 4) {
        std::cerr << "Lack of arguments: " << argv[0] << " <datafile> <n> <algorithm>" << std::endl;
        return -127;
    }

    BaseAlgorithm *algo;

    try {
        algo = chooseAlgorithm(argv[3], argc, argv);
        if (algo == 0) {
            std::cerr << "The algorithm is not found" << std::endl;
            return -127;
        }
    } catch (const char *msg) {
        std::cerr << msg << std::endl;
        return -127;
    }

    long start_time, finish_time;
    size_t max_data = std::stoi(argv[2]);
    std::vector<House> houseList;
    readFile(argv[1], &houseList, max_data);

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
