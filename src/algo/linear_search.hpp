/**
 * linear_search.hpp file.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#ifndef ALGO_LINEAR_SEARCH_TREE_H_
#define ALGO_LINEAR_SEARCH_TREE_H_

#include <string>

#include "base_algo.hpp"

class LinearSearch: public BaseAlgorithm
{
    private:
        std::string nama_ibu;
        LinearSearch(char*);

    public:
        bool find(std::vector<House> *);

        static LinearSearch* createFromConsoleArgument(int, char **);
};

#endif
