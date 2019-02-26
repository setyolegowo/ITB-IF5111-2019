/**
 * index_search.cpp file.
 * Implementation.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.26
 */

#include <string>

#include "index_search.hpp"

IndexSearch::IndexSearch(int _index)
{
    this->index = _index;
}

IndexSearch *IndexSearch::createFromConsoleArgument(int argc, char **argv)
{
    if (argc < 5) {
        throw "Lack of argument for index search: <index_number>";
    }
    int index;

    try {
        index = std::stoi(argv[4]);
    } catch (const std::invalid_argument& ia) {
        throw "Invalid argument for <index_number>";
    }

    return new IndexSearch(index);
}

bool IndexSearch::find(std::vector<House> *houseList)
{
    if (houseList->size() > this->index) {
        return true;
    }
    return false;
}