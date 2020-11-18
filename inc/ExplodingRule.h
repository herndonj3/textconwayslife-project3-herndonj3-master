// Class for exploding rule

#ifndef EXPLODINGRULE_H_
#define EXPLODINGRULE_H_

#include<string>

#include<Rule.h>

using namespace std;

class ExplodingRule : public Rule {

public:
  // Chain the constructor ...
  ExplodingRule() : Rule("Exploding") {}

  char GetNextCellState(char currentCellState,
                        int liveNeighborCount) const;
};

#endif
