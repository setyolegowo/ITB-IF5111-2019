/**
 * square_delivery.cpp file.
 * Implementation.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.28
 */

#include <cstring>
#include <cstdlib>

#include "square_delivery.hpp"

SquareDelivery::SquareDelivery(int type) {
    this->type = type;
}

SquareDelivery *SquareDelivery::createFromConsoleArgument(int argc, char **argv)
{
    if (argc < 5) {
        throw "Lack of argument for square delivery: <type>";
    }
    int type; // random
    if (strcmp(argv[4], "worstcase") == 0) {
        type = 1;
    } else if (strcmp(argv[4], "bestcase") == 0) {
        type = 2;
    } else if (strcmp(argv[4], "average") == 0) {
        type = 0;
    } else {
        throw "Unrecognized type: worstcase|bestcase|average";
    }

    return new SquareDelivery(type);
}

bool SquareDelivery::find(std::vector<House> *houseList)
{
    size_t houseListSize  = houseList->size();
    uint32_t i_bapak, i, i_ibu;
    std::string *nama_ibu;

    for (i_bapak = 0; i_bapak < houseListSize; i_bapak++) {
        nama_ibu = this->getDeliverTo(i_bapak, houseList);

        for (i = 1; i <= houseListSize; i++) {
            i_ibu = (i + i_bapak) % houseListSize;

            if (houseList->at(i_ibu).nama_ibu.compare(*nama_ibu)) {
                break;
            }
        }
    }
    return true;
}

std::string *SquareDelivery::getDeliverTo(uint32_t currentIndex, std::vector<House> *houseList)
{
    size_t selectedIndex;
    size_t houseListSize = houseList->size();

    switch (this->type) {
        case 0:
            selectedIndex = rand() % (houseListSize - 1);
            break;

        case 1:
            if (currentIndex == 0) {
                selectedIndex = houseListSize - 1;
            } else {
                selectedIndex = currentIndex - 1;
            }
            break;

        case 2:
            if (currentIndex == houseListSize - 1) {
                selectedIndex = 0;
            } else {
                selectedIndex = currentIndex + 1;
            }
    }

    return &houseList->at(selectedIndex).nama_ibu;
}