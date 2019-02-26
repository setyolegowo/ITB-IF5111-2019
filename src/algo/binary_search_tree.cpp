/**
 * binary_search_tree.cpp file.
 * Implementation.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#include <cstring>

#include "binary_search_tree.hpp"

BinarySearch::BinarySearch(char* _nama_bapak) {
    this->nama_bapak = std::string(_nama_bapak);
}

BinarySearch* BinarySearch::createFromConsoleArgument(int argc, char** argv) {
    if (argc < 5) {
        throw "Lack of argument for binary search: <nama_bapak>";
    }

    return new BinarySearch(argv[4]);
}

bool BinarySearch::find(std::vector<House> * houseList)
{
    uint32_t higher_bound = houseList->size() - 1;
    uint32_t lower_bound = 0;
    uint32_t selected_index;
    bool isFound = false;
    int compareResult;

    while (lower_bound < higher_bound && !isFound) {
        selected_index = (higher_bound + lower_bound)/2;
        compareResult = houseList->at(selected_index).nama_bapak.compare(this->nama_bapak);

        if (compareResult == 0) {
            isFound = true;
        } else if (compareResult < 0) {
            lower_bound = selected_index + 1;
        } else { // > 0
            higher_bound = selected_index;
        }
    }
    if (lower_bound == higher_bound && !isFound) {
        isFound = houseList->at(selected_index).nama_bapak.compare(this->nama_bapak) == 0;
    }

    return isFound;
}
