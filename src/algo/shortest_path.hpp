/**
 * shortest_path.hpp file.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#ifndef ALGO_SHORTEST_PATH_H_
#define ALGO_SHORTEST_PATH_H_

#include <string>

#include "base_algo.hpp"

class ShortestPath: public BaseAlgorithm
{
    private:
        uint32_t start_index, shortest_path;
        ShortestPath(uint32_t);

    public:
        bool find(std::vector<House> *);
        void visit(uint32_t, uint32_t, std::vector<House> *, std::vector<bool> *);
        uint32_t findUnvisitedLeft(uint32_t, std::vector<bool> *);
        uint32_t findUnvisitedRight(uint32_t, std::vector<bool> *);

        static ShortestPath* createFromConsoleArgument(int, char **);
};

#endif
