/**
 * log_linear_search.hpp file.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#ifndef ALGO_LOG_LINEAR_SEARCH_TREE_H_
#define ALGO_LOG_LINEAR_SEARCH_TREE_H_

#include <string>

#include "base_algo.hpp"

class LogLinearSearch: public BaseAlgorithm
{
    private:
        char huruf_depan_nama_ibu;
        std::vector<House> result_ibu;
        LogLinearSearch(char*);

    public:
        bool find(std::vector<House> *);
        bool findFather(std::vector<House> *, std::string);
        static LogLinearSearch* createFromConsoleArgument(int, char **);
};

#endif
