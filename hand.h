#include <vector>
#include "tile.h"

enum Frag {
    _shuntsu,
    _,
    _
}

struct HandFrag {
    int tiles[34];
    int frags[4];
    Tile curr_tile;
    int curr_search;
};

class BaseSearch {
 public:
    virtual bool exist(const HandFrag &hf) = 0;
    virtual void remove(HandFrag &hf) = 0;
};

class SearchSequence: public BaseSearch {
    bool exist(const HandFrag &hf) override;
    void remove(HandFrag &hf) override;
};

class Hand {
    int tiles[34];
    int n_frags_target[4];
    BaseSearch *bs[4];
    Hand();
};

bool ifWin(const Hand* hand, int* score, int normal) {
    return (hand->nMentsu == 4 && hand->nZyanTou == 1);
}

void removePair(Hand* hand, int i) {
    hand->nZyanTou++;
    hand->tiles[i] -= 2;
}

void removeTriplet(Hand* hand, int i) {
    hand->nMentsu++;
    hand->tiles[i] -= 3;
}

void removeSequence(Hand* hand, int i) {
    hand->nMentsu++;
    for (int j = i; j < i + 3; ++j) hand->tiles[j] -= 1;
}

void search_Sequence(const Hand* hand, int* score, int start) {
    for (int i = start; i < 28; ++i) {
        if (hand->tiles[i] >= 1 && hand->tiles[i+1] >= 1 && hand->tiles[i+2] >= 1) {
            Hand hand_ = *hand;
            removeSequence(&hand_, i);
            if (ifWin(&hand_, score, 1)) return;
            else search_Sequence(&hand_, score, i);
        }
    }
}

void search_Triplet(const Hand* hand, int* score, int start) {
    for (int i = start; i < 30; ++i) {
        if (hand->tiles[i] >= 3) {
            Hand hand_ = *hand;
            removeTriplet(&hand_, i);
            if (ifWin(&hand_, score, 1)) return;
            else search_Triplet(&hand_, score, i);
        }
    }
    search_Sequence(hand, score, 1);
}

void search_Pair(const Hand* hand, int* score) {
    for (int i = 1; i < 30; ++i) {
        if (hand->tiles[i] >= 2) {
            Hand hand_ = *hand;
            removePair(&hand_, i);
            search_Triplet(&hand_, score, 1);
        }
    }
}

int suit2num(const char* p) {
    if (*p == 'c') return 0;
    if (*p == 'b') return 10;
    if (*p == 'd') return 20;
    return 0;
}

int main() {
    char code[14];
    while (1) {
        scanf("%s", code);
        if (strcmp(code, "exit") == 0) break;
        Hand hand = getHand(code);
        quadNum(&hand);
        int score = 0;
        search_Pair(&hand, &score);
        if (score > 0) printf("Win (%i)\n", score);
        else printf("Cont\n");
    }
    return 0;
}