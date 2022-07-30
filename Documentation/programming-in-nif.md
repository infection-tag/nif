# Programming in NIF

This is a little guide on creating your first interactive-fiction story with NIF.

## Everything is classes

Every object in NIF is a class. If you don't know what a class is, I would suggest reading about it online. 

Creating a new chapter is as easy as typing this line:

```
chapter chapterName(chapterID, logline); // int, string
```

To know more about `chapterID` and `logline`, read getting-started.md.

Creating a new story is as simple as:

```
newStory storyName(firstChapter, title); // chapter, string
```

## User I/O

User input/output is meant to be as smooth as possible. If when creating a chapter, you should always be sure to include exposition where necessary. This is how you set exposition:

```
chapter hammer(1, "Hit Uncle Otto with a hammer.");
newChapter.expo = "You knock some sense back into Uncle Otto, and he stops insisting that he is Napoleon Bonaparte.";
```

Exposition, however, is not necessary; it is just recommended.

```
chapter removeYourHand(2, "Uncle Otto, remove your hand from your shirt!");
```

The basis of interactive fiction is as such: the user selects an option and the computer spits out a response that may or may not progress the story. For instance, if the user is given the option:

```
What do you do next?

1. Examine the fleecy cloud
2. Ask Uncle Otto about Moscow and Waterloo
3. Call the Funny Farm

Enter option here:
```

choosing `3` would prompt this response:

```
Enter option here: 3

Men in white coats arrive and hustle Uncle Otto into the wagon.
```

This entire exchange is handled by a function built-in to NIF, called `printOptions()`. To print options and recieve input for a chapter titled `myChapter`, simply use

```
myChapter.printOptions();
```

Not only will this print all possible next options' loglines, it will take in user input and move to that chapter *for* you! Pretty neat, huh?
