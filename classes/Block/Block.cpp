#include "Block.h"

#include <map>
#include <string>

using std::map;
using std::string;

void Block::initBlockMap() {
    map<string, bool> data;
    for (int i = 0; i < this->numberOfReqs; i++) {
        data.insert(std::pair<string, bool>{this->reqs.at(i), false});
    }
    this->blockMap = data;
}
