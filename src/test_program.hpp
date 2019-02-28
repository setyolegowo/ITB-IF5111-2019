/**
 * node_structre.hpp file.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#ifndef ANALGO_TEST_PROGRAM_H_
#define ANALGO_TEST_PROGRAM_H_

#include <string>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <sys/time.h>

#include "algo/base_algo.hpp"
#include "algo/index_search.hpp"
#include "algo/binary_search_tree.hpp"
#include "algo/linear_search.hpp"
#include "algo/log_linear_search.hpp"
#include "algo/shortest_path.hpp"
#include "algo/square_delivery.hpp"

#include "node_structure.hpp"

class Test {
    public:
        static uint32_t getRandomIndex(uint32_t);
        static long getMicrotime();
        static void readFile(char*, std::vector<House>*, size_t);
        static BaseAlgorithm * chooseAlgorithm(char*, int, char**);
        static House * getRandomFromVector(std::vector<House> *);
        static char * str2Char(std::string);
        static int modifyArgument(char**, std::vector<House> *);
        static int runTesting(int, char**);
};

#endif
