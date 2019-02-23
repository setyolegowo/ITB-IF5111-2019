/**
 * base_algo.hpp file.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.23
 */

#ifndef BASE_ALGO_H_
#define BASE_ALGO_H_

#include <vector>
#include "../node_structure.hpp"

class BaseAlgorithm
{
    public:
        /**
         * Use algorithm.
         */
        virtual bool find(std::vector<House>*) = 0;
};

#endif