/**
 * linear_search.cpp file.
 * Implementation.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#include "linear_search.hpp"

LinearSearch::LinearSearch(char* _nama_ibu) {
    this->nama_ibu = std::string(_nama_ibu);
}

LinearSearch* LinearSearch::createFromConsoleArgument(int argc, char** argv) {
    if (argc < 5) {
        throw "Lack of argument for linear search: <nama_ibu>";
    }

    return new LinearSearch(argv[4]);
}

bool LinearSearch::find(std::vector<House> * houseList)
{
    uint32_t higher_bound = houseList->size();
    uint32_t selected_index = 0;
    bool isFound = false;
    int compareResult;

    while (selected_index < higher_bound && !isFound) {
        compareResult = houseList->at(selected_index).nama_ibu.compare(this->nama_ibu);

        if (compareResult == 0) {
            isFound = true;
        } else {
            selected_index += 1;
        }
    }

    return isFound;
}
