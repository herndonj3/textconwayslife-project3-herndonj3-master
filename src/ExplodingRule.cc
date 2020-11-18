/* Exploding Rule:
//    If a cell has 3 or 4 live neighbors, it either continues
//        living or comes to life.
//    Otherwise, it dies or stays dead
*/


#include<ExplodingRule.h>

char ExplodingRule::GetNextCellState(char currentCellState,
                                    int liveNeighborCount) const {
  char nextState = DEAD_CELL;

  // Exploding Rule for any cell staying alive or coming to life
  if ( (currentCellState == LIVE_CELL) &&
       (liveNeighborCount == 3) || (liveNeighborCount == 4) )
    nextState = LIVE_CELL;

  // Exploding Rule for any cell dying or staying dead
  else if ( (currentCellState == DEAD_CELL) &&
            (liveNeighborCount < 3) || (liveNeighborCount > 4))
    nextState = DEAD_CELL;

  return nextState;
}
