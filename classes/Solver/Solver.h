#ifndef INC_01_SOLVER_H
#define INC_01_SOLVER_H


#include <iostream>
#include "../Block/Block.h"

class Solver {
public:
    static Block getBestMatchFromCollection(const vector<string> &reqs, const vector<Block> &blocks) {
        map<size_t, Block> res;

        size_t blockSize = blocks.size();
        auto weight =
                [&blockSize, &blocks]
                        (const string &req, const Block &neighbor, size_t order, int distance, bool leftSide) {
                    if (neighbor.hasReq(req)) {
                        return ++distance;
                    } else {
                        if (!leftSide) {
                            if (order == blockSize - 1) {
                                return -1;
                            }
                            return weight(req, blocks[order + 1], order + 1, distance + 1, leftSide);
                        }
                        if (leftSide) {
                            if (order == 0) {
                                return -1;
                            }
                            return weight(req, blocks[order - 1], order - 1, distance + 1, leftSide);
                        }

                    }
                };

        for (size_t i = 0; i < blockSize; i++) {
            vector<string> searchingReqs;
            size_t actualDistance = 0;

            for (const auto &req: reqs) {
                if (!blocks[i].hasReq(req)) {
                    searchingReqs.push_back(req);
                } else {
                    actualDistance++;
                }
            }
            for (const auto &search: searchingReqs) {
                int left = -1, right = -1;
                if (i == 0) {
                    left = weight(search, blocks[i - 1], i, 1, true);
                }
                if (i == blockSize - 1) {
                    right = weight(search, blocks[i + 1], i, 1, false);
                }
                int lower = ((left < right) && (left > -1)) ? left : right;
                if (lower == -1) {
                    std::cout << "Cannot match by this defined map";
                } else {
                    actualDistance += lower;
                }
            }
            res.insert(std::pair<int, Block>{actualDistance, blocks[i]});
        }
    };
};


#endif