#include <iostream>
#include "trine/trine.h"

using namespace ds;

int main() {

    Trine trine;
    trine.addWord("francesco");
    trine.addWord("valentina");
    trine.addWord("carmelina");
    trine.addWord("franco");
    trine.addWord("francesca");
    cout << trine.getWordWithPrefix("fra").toString() << endl;
    cout << trine.getWordWithPrefix("vale").toString() << endl;
    cout << trine.getWordWithPrefix("carm").toString() << endl;
    return 0;
}