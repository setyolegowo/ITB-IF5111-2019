/**
 * node_structre.cpp file.
 * Implementation.
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
#include "test_program.hpp"

uint32_t Test::getRandom(uint32_t max){
    return ((double) rand() / (RAND_MAX)) * max;
}

long Test::getMicrotime()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

void Test::readFile(char* filename, std::vector<House>* houseList, size_t max_data)
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

BaseAlgorithm * Test::chooseAlgorithm(char* choose, int argc, char** argv)
{
    if (strcmp(choose, "index") == 0) {
        return IndexSearch::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "binary") == 0) {
        return BinarySearch::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "linear") == 0) {
        return LinearSearch::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "loglin") == 0) {
        return LogLinearSearch::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "shortest") == 0) {
        return ShortestPath::createFromConsoleArgument(argc, argv);
    } else if (strcmp(choose, "square") == 0) {
        return SquareDelivery::createFromConsoleArgument(argc, argv);
    }
    return 0;
}

House * Test::getRandomFromVector(std::vector<House> * houseList) {
    uint32_t index = std::rand() % houseList->size();
    return &(houseList->at(index));
}

char * Test::str2Char(std::string str) {
    char * cstr = new char[str.size() + 1];
    strcpy(cstr, str.c_str());
    return cstr;
}

int Test::modifyArgument(char* choose, char** argv, std::vector<House> * tempHouseList)
{
    if (strcmp(choose, "index") == 0) {
        // std::cout << getRandom(tempHouseList->size()) << std::endl;
        // argv[4] = str2Char("10");
    } else if (strcmp(choose, "binary") == 0) {
        
    } else if (strcmp(choose, "linear") == 0) {
        // std::string target = getRandomFromVector(tempHouseList)->nama_ibu;
        // argv[4] = str2Char(target);
    } else if (strcmp(choose, "loglin") == 0) {
        
    } else if (strcmp(choose, "shortest") == 0) {
        
    } else if (strcmp(choose, "square") == 0) {
        
    }
    return 0;
}

int Test::runTesting(int argc, char** argv)
{
    
    if (argc < 4) {
        std::cerr << "Lack of arguments: " << argv[0] << " <datafile> <max_n> <algorithm>" << std::endl;
        return -127;
    }

    size_t max_data = std::stoi(argv[2]);
    std::vector<House> houseList;
    readFile(argv[1], &houseList, max_data);

    std::ofstream myfile;
    myfile.open ("result/" + std::string(argv[3]) + ".csv");
    myfile << "N,time,\n";

    // Run testing for some N
    for(size_t i=10; i<max_data; i+=10) {

        long sum_time = 0;
        int test_n = 10;

        // Run 10 times per sample
        for(int j=0; j<test_n; j++) {

            long start_time, finish_time;
            start_time = getMicrotime();

            // std::vector<House> tempList(houseList.begin(), houseList.begin() + 10);
            // // modifyArgument(argv[3], argv, &temp);

            BaseAlgorithm *algo = chooseAlgorithm(argv[3], 5, argv);
            algo->find(&houseList);

            finish_time = getMicrotime();
            sum_time += finish_time - start_time;
        }

        long avg_time = sum_time / test_n;

        std::cout << i << " " << avg_time << std::endl;
        myfile << i << "," << avg_time << ",\n";
    }
    
    myfile.close();

    return 0;
}
