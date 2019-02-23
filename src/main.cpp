/**
 * main.cpp file.
 * Main.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "algo/binary_search_tree.hpp"
#include "node_structure.hpp"

int main(int argc, char** argv)
{
    if (argc == 1) {
        std::cerr << "Lack of arguments: " << argv[0] << " <datafile>" << std::endl;
        return 0;
    }

    std::vector<House> houseList;

    std::ifstream csvfile(argv[1]);
    std::string line = "";
    getline(csvfile, line);
    while (getline(csvfile, line))
    {
        houseList.push_back(House::createFromString(line));
    }
    return 0;
}
