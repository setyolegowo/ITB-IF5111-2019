/**
 * node_structre.cpp file.
 * Implementation.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#include "node_structure.hpp"

std::string delimiter = ",";

House::House(std::string _nama_bapak, std::string _nama_ibu, int32_t _nomor_rumah, int32_t _posisi_rumah)
{
    nama_bapak = _nama_bapak;
    nama_ibu = _nama_ibu;
    nomor_rumah = _nomor_rumah;
    posisi_rumah = _posisi_rumah;
}

House House::createFromString(std::string row)
{
    size_t pos;
    std::string nama_bapak, nama_ibu;
    int32_t nomor_rumah, posisi_rumah;

    pos = row.find(delimiter);
    nama_bapak = row.substr(0, pos);
    row.erase(0, pos + delimiter.length());

    pos = row.find(delimiter);
    nama_ibu = row.substr(0, pos);
    row.erase(0, pos + delimiter.length());

    pos = row.find(delimiter);
    nomor_rumah = std::stoi(row);
    row.erase(0, pos + delimiter.length());

    posisi_rumah = std::stoi(row);

    House house(nama_bapak, nama_ibu, nomor_rumah, posisi_rumah);

    return house;
}
