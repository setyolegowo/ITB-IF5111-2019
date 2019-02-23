/**
 * main.cpp file.
 * Main.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#include <iostream>
#include <fstream>

#include "algo/binary_search_tree.hpp"
#include "node_structure.hpp"

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

int main(int argc, char** argv)
{
    if (argc == 1) {
        std::cerr << "Lack of arguments: " << argv[0] << " <datafile>" << std::endl;
        return 0;
    }

    std::vector<House> houseList;
    readFile(argv[1], &houseList);

    std::cout << "Using binary search" << std::endl;
    BinarySearch search;
    if (search.find(&houseList)) {
        std::cout << "FOUND" << std::endl;
    } else {
        std::cout << "NOT FOUND" << std::endl;
    }

    return 0;
}
