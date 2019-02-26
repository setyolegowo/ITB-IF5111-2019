/**
 * log_linear_search.cpp file.
 * Implementation.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#include "log_linear_search.hpp"

LogLinearSearch::LogLinearSearch(char* _huruf_depan_nama_ibu) {
    this->huruf_depan_nama_ibu = _huruf_depan_nama_ibu[0];
}

LogLinearSearch* LogLinearSearch::createFromConsoleArgument(int argc, char** argv) {
    if (argc < 5) {
        throw "Lack of argument for log linear search: <huruf_depan_nama_ibu>";
    }

    return new LogLinearSearch(argv[4]);
}

bool LogLinearSearch::find(std::vector<House> * houseList)
{
    uint32_t array_size = houseList->size() - 1;
    uint32_t current_index = 0;
    int compareResult;
    bool isFound = true;

    while (current_index <= array_size) {
        compareResult = houseList->at(current_index).nama_ibu[0] == this->huruf_depan_nama_ibu;

        if (compareResult == true) {
            bool isFatherFound = this->findFather(houseList, houseList->at(current_index).nama_bapak);
            isFound = isFound && isFatherFound;
        }
        
        current_index += 1;
    }

    return isFound;
}

bool LogLinearSearch::findFather(std::vector<House> * houseList, std::string nama_bapak)
{
    uint32_t higher_bound = houseList->size() - 1;
    uint32_t lower_bound = 0;
    uint32_t selected_index;
    bool isFound = false;
    int compareResult;

    while (lower_bound < higher_bound && !isFound) {
        selected_index = (higher_bound + lower_bound)/2;
        compareResult = houseList->at(selected_index).nama_bapak.compare(nama_bapak);

        if (compareResult == 0) {
            isFound = true;
        } else if (compareResult < 0) {
            lower_bound = selected_index + 1;
        } else { // > 0
            higher_bound = selected_index;
        }
    }
    if (lower_bound == higher_bound && !isFound) {
        isFound = houseList->at(selected_index).nama_bapak.compare(nama_bapak) == 0;
    }

    return isFound;
}
