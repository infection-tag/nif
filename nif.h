#ifndef NIF_H
#define NIF_H

using namespace std;

/*
* by Nishant Kompella, 2022.
* All code here is open source, and is free to be used.
*/

// #define MAXLEN 1000;

/*
    TODO:
    Add "end" chapter (or some use to end)
    Fix "unknown type name 'chapter'" error
    Fix "no matching constructor for initialization of 'newStory'" error
*/

// general use functions
void storyInit(); // initialize the story
void clear(); // clear the screen
void endStory(int); // end the game

/* Chapter class implementation begins here */
// Note: everything in the class is public because there should be no access limit to any of the items.
class chapter {
    public:
        string logline;             // the description of the option
        void printChap();           // prints out logline and (eventually) other stuff
        string expo;           // exposition for current chapter
        chapter();                  // default constructor
        int nextOptionID;           // the ID of the next chapter
        chapter(int, string);       // constructor to take in ID and logline
        int chapterID;              // the ID of the chapter
        void setID(int);            // sets new ID for the chapter
        chapter* nextOption[1000];  // next option in the game
        int nextOption_ptr;         // keeps track of next availible spot in nextOption[]
        void operator>>(chapter);   // defines flow of options and valid movements
        void operator<<(chapter);   // moves one chapter into another using pass-by-reference
};

/* Story class implementation begins here */
class newStory {
    public:
        void printOptions();        // prints next options of current chapter
        newStory();                 // default constructor
        newStory(chapter, string);  // parametrized constructor (takes in chapter and game-title)
        chapter nextOption[1000];   // map of all options
        chapter current;            // current chapter, will be left-shifted by next option
        string title;               // TODO: add title of the story to potential header
        int IDList[1000];           // list of IDs
        int IDList_ptr;             // current unused spot in IDList
};

#endif // NIF_H
