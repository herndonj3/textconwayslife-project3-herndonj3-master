//Class for Stable Rule

#ifndef STABLERULE_H_
#define STABLERULE_H_

#include<string>

#include<Rule.h>

using namespace std;

class StableRule : public Rule {

  public:

    StableRule() : Rule("Stable") {}

    char GetNextCellState(char currentCellState,
                          int liveNeighborCount) const;
};

#endif
