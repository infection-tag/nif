#include <iostream>
#include "nif-err.h"

using namespace std;

void NIFerr(int i) {
    switch(i) {
        case -1: // no chapters have been provided to the story
            cout << "INIT ERROR: NO CHAPTERS PROVIDED TO STORY\n" << "Chapter is missing or restricted.\n";
        case 1: // reserved ID (0, 100)
            cout << "ASSIGNMENT ERROR: RESERVED IDS\n" << "note: 0 and 100 are reserved operator IDs and cannot be used as chapter assignments";
        case 2: // conflicting IDS
            cout << "ASSIGNMENT ERROR: CONFLICTING IDS\n";
    }
}