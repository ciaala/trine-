#include <iostream>
#include "ds/trine.h"

using namespace ds;

int main() {

    Trine trine;
    trine.addWord("francesco");
    trine.addWord("valentina");
    trine.addWord("carmelina");

    cout << trine.getWordWithPrefix("fra").toString();
    cout << trine.getWordWithPrefix("vale").toString();
    cout << trine.getWordWithPrefix("carm").toString();
    return 0;
}