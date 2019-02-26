/**
 * shortest_path.cpp file.
 * Implementation.
 *
 * @author Setyo Legowo <gw.tio145@gmail.com>
 * @since 2019.02.18
 */

#include <iostream>
#include <string>
#include <stdexcept>

#include "shortest_path.hpp"

ShortestPath::ShortestPath(uint32_t _index) {
    this->start_index = _index;
}

ShortestPath* ShortestPath::createFromConsoleArgument(int argc, char** argv) {
    if (argc < 5) {
        throw "Lack of argument for log linear search: <start_index>";
    }
    uint32_t index;

    try {
        index = std::stoi(argv[4]);
    } catch (const std::invalid_argument& ia) {
        throw "Invalid argument for <start_index>";
    }

    return new ShortestPath(index);
}

bool ShortestPath::find(std::vector<House> * houseList)
{

    std::vector<bool> isVisited;
    for(uint32_t i=0; i<houseList->size(); i++) {
        isVisited.push_back(false);
    }

    this->shortest_path = 0;
    this->visit(this->start_index, 0, houseList, &isVisited);

    return true;
}

void ShortestPath::visit(uint32_t current_index, uint32_t current_path, std::vector<House> * houseList, std::vector<bool> * isVisited) {

    isVisited->at(current_index) = true;

    // Visit every house recursively

    // Go to right
    uint32_t next_index = this->findUnvisitedRight(current_index, isVisited);
    if(next_index != UINT32_MAX) {
        uint32_t new_path = current_path +
            houseList->at(next_index).posisi_rumah -
            houseList->at(current_index).posisi_rumah;

        if(new_path < this->shortest_path)
            this->shortest_path = new_path;

        this->visit(next_index, new_path, houseList, isVisited);
    }

    // Go to left
    next_index = this->findUnvisitedLeft(current_index, isVisited);
    if(next_index != UINT32_MAX) {
        uint32_t new_path = current_path +
            houseList->at(current_index).posisi_rumah -
            houseList->at(next_index).posisi_rumah;

        if(new_path > this->shortest_path)
            this->shortest_path = new_path;

        this->visit(next_index, new_path, houseList, isVisited);
    }

    isVisited->at(current_index) = false;
    return;
}

uint32_t ShortestPath::findUnvisitedLeft(uint32_t current_index, std::vector<bool> * isVisited) {
    current_index--;
    while(current_index + 1 > 0) {
        if(!isVisited->at(current_index)) return current_index;
        current_index--;
    }
    return UINT32_MAX;
}

uint32_t ShortestPath::findUnvisitedRight(uint32_t current_index, std::vector<bool> * isVisited) {
    current_index++;
    uint32_t array_size = isVisited->size();
    while(current_index < array_size) {
        if(!isVisited->at(current_index)) return current_index;
        current_index++;
    }
    return UINT32_MAX;
}
