/**
 * square_delivery.hpp file.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.28
 */

#ifndef SQUARE_DELIVERY_H_
#define SQUARE_DELIVERY_H_

#include <string>
#include <vector>

#include "base_algo.hpp"
#include "../node_structure.hpp"

class SquareDelivery: public BaseAlgorithm
{
    private:
        int type;
        SquareDelivery(int);
        std::string *getDeliverTo(uint32_t, std::vector<House> *);

      public:
        bool find(std::vector<House> *);

        static SquareDelivery* createFromConsoleArgument(int, char **);
};

#endif
