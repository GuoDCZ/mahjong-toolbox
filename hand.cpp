#include "hand.h"
#include <cassert>

bool SearchSequence::exist(const HandFrag &hf) {
    auto it = hf.tiles.begin();
    assert(it->second);
    Tile t = it->first;
    if (!can_start_shuntsu(t))
        return false;
    if (hf.tiles[Tile(t+1)]>0)
        return false;
    assert(it->second);
    if ((++it)->first != Tile(t+2))
        return false;
    assert(it->second);
    return ture;
}