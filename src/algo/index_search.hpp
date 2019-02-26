/**
 * index_search.hpp file.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.26
 */

#ifndef INDEX_SEARCH_H_
#define INDEX_SEARCH_H_

#include "base_algo.hpp"

class IndexSearch: public BaseAlgorithm
{
    private:
        int32_t index;
        IndexSearch(int);

    public:
        bool find(std::vector<House> *);

        static IndexSearch* createFromConsoleArgument(int, char **);
};

#endif
