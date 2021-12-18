#ifndef INC_01_BLOCK_H
#define INC_01_BLOCK_H

#include <utility>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::string;

class Block {
public:
    explicit Block(vector<string> reqs) {
        this->reqs = std::move(reqs);
        this->numberOfReqs = this->reqs.size();

        this->initBlockMap();
    };

    size_t getNumberOfReqs() const {
        return this->numberOfReqs;
    }

    bool hasReq(const string &req) const {
        return this->blockMap.find(req)->second;
    };

    void setVal(const string &reqName, bool value);

private:
    vector<string> reqs;
    size_t numberOfReqs;
    map<string, bool> blockMap;

    void initBlockMap();
};


#endif