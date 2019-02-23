/**
 * binary_search_tree.hpp file.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#ifndef ALGO_BINARY_SEARCH_TREE_H_
#define ALGO_BINARY_SEARCH_TREE_H_

#include "base_algo.hpp"

class BinarySearch: public BaseAlgorithm
{
    public:
        BinarySearch();
        bool find(std::vector<House> *);
};

#endif
