/* This rule will follow the stable 5/345 pattern known as Long Life
// The rules are as follows:
//    Living Cells survive if they have 5 neighbors
//        Otherwise, they die
//    Dead Cells come to life if they have 3, 4, or 5 neighbors
//        Otherwise, they stay dead
*/

#include<StableRule.h>

char StableRule::GetNextCellState(char currentCellState,
                                    int liveNeighborCount) const {
  char nextState = DEAD_CELL;

  // Stable rule for living cells staying alive
  if ( (currentCellState == LIVE_CELL) &&
       (liveNeighborCount == 5))
    nextState = LIVE_CELL;

  // Stable Rule for living cells dying
    if ( (currentCellState == LIVE_CELL) &&
         (liveNeighborCount < 5) || (liveNeighborCount > 5))
      nextState = DEAD_CELL;

  // Stable Rule for dead cell coming to life
  else if ( (currentCellState == DEAD_CELL) &&
            (liveNeighborCount == 3) || (liveNeighborCount == 4) || (liveNeighborCount == 5))
    nextState = LIVE_CELL;

  // Otherwise, the cell stays dead
  return nextState;
}
