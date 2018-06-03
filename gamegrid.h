#ifndef GAMEGRID_H
#define GAMEGRID_H

#include <crtp.h>

/**
 * A game grid is a collection of values organized in a 2D array.
 */
template <typename T>
class GameGrid : public crtp<T>
{
public:
    GameGrid();
};

#endif // GAMEGRID_H
