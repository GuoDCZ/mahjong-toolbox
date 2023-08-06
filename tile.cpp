#include "tile.h"

bool can_start_shuntsu(Tile t) {
    return (
        t >= _1m && t <= _7m || 
        t >= _1p && t <= _7p || 
        t >= _1s && t <= _7s);
}

bool can_start_kantsu(Tile t) {
    return can_start_shuntsu(t);
}

bool can_start_datsu(Tile t) {
    return (
        t >= _1m && t <= _8m || 
        t >= _1p && t <= _8p || 
        t >= _1s && t <= _8s);
}

Tile get_dora_next(Tile t) {
    switch (t) {
        case _9m: return _1m;
        case _9p: return _1p;
        case _9s: return _1s;
        case _4z: return _1z;
        case _7z: return _5z;
        default:  return Tile(t+1);
    }
}