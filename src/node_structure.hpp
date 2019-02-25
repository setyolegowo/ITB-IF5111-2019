/**
 * node_structre.hpp file.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#ifndef ANALGO_NODE_STRUCTURE_H_
#define ANALGO_NODE_STRUCTURE_H_

#include <string>
#include <stdint.h>

class House {
    protected:
        std::string nama_bapak;
        std::string nama_ibu;
        int32_t nomor_rumah;

    public:
        House(std::string, std::string, int32_t);
        static House createFromString(std::string);
};

#endif
