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

Hand::Hand():
    tiles({3,1,1,1,2,1,1,1,3,}),
    n_frags_target({4,1,0,0}) {
        
    }
