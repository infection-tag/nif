#include "nif.h"
#include "nif-err.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int IDList[1000];
int IDList_ptr = 0;

void clear() { // clear the screen
    system("clear");
}

void endStory(int i = 0) { // end the game (NIF assumes without fault)
    cout << "End of Story" << endl;
    if(i != 0) {
        NIFerr(i);
    }
    exit(i);
}

void storyInit() { // initialize a new story (including end class)
    chapter EOS(100, "The end"); // the end of the story; a special chapter created with the story.
    
}

newStory::newStory() { // default constructor
    __NIFERR_MISSING_CHAPTER; // no chapters have been provided
    exit(-1);
}

newStory::newStory(chapter w, string t) {
    /*
    * for our purposes, w is the chapter we "write" to -- we will use << and >> to override operators
    * >> operator will define flow of the chapters, and will provide possible next-options
    * << operator will ACTUALLY move the selected chapter to w
    */
    // set ID list to 0
    IDList[1000] = {0}; // list of all taken IDs
    IDList_ptr = 0; // current unused spot in IDList
    title = t;
    current = w;

}

chapter::chapter() {} // default constructor so the compiler doesn't bitch at me

chapter::chapter(int ID, string l) { 
    // resets nextOption buffer
    nextOption[1000] = {0};
    logline = l;
    
    // checks if ID is availible
    int i;
    for(i = 0;; i++) {
        if(IDList[i] == ID) {
            __NIFERR_CONFLICTING_ID;
        }
        chapterID = ID;
        IDList_ptr++;
        return;
    }
    // commenting the following lines out for debugging
/*    try {
        // chapter ID has conflict with another chapter
        if(IDList[i] == ID) {
            throw ID;
        }
    }
    catch(int ID) {
        __NIFERR_CONFLICTING_ID;
        exit(2);
    } */
}

void chapter::operator>>(chapter c) { // add chapters as potential options
    this->nextOption[nextOption_ptr] = &c;
    this->nextOption_ptr++;
}

void chapter::operator<<(chapter c) { // points new chapter to old chapter
    this->expo = c.expo; // set exposition
    this->logline = c.logline; // set logline
    for(int i = 0; i < c.nextOption_ptr; i++) // set next options
        this->nextOption[i] = c.nextOption[i];
} 

void chapter::printChap() {
    cout << logline << endl;
    cout << expo << endl;
}

void newStory::printOptions() { // takes all possible options and prints them out
    for(int i = 0; i < current.nextOption_ptr; i++) {
        cout << i + 1 << ": " << nextOption[i].logline << endl;
    }
    cout << "Press the number to select your option." << endl;
    int i;
    cin >> i;
    current << nextOption[i - 1]; // shift selected chapter into "current" chapter
}

void chapter::setID(int newID) {
    chapterID = newID;
}
