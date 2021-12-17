#include <iostream>

#include <vector>
#include <map>
#include <string>

#include "classes/Block/Block.h"

using std::vector;
using std::map;
using std::string;

int main() {
    const vector<string> reqs = {"gym", "school", "store"};

    auto b = new Block(reqs);

    return 0;
}
