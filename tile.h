enum Tile {
    _1m, _2m, _3m, _4m, _5m, _6m, _7m, _8m, _9m,
    _1p, _2p, _3p, _4p, _5p, _6p, _7p, _8p, _9p,
    _1s, _2s, _3s, _4s, _5s, _6s, _7s, _8s, _9s,
    _1z, _2z, _3z, _4z,	_5z, _6z, _7z
};

inline bool can_start_shuntsu(Tile t);    // 顺子
inline bool can_start_kantsu(Tile t);     // 坎子
inline bool can_start_datsu(Tile t);      // 搭子
inline Tile get_dora_next(Tile t);


