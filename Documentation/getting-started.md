# Getting started with NIF

Here is how to get started with normal NIF, and the logic of how it works.

## What is NIF?

NIF, which stands for NSSK-Interactive-Fiction, is a programming framework meant to revolutionize the text-based interactive fiction business.  

All you need is a basic C++ knowlege. If you don't have that, a basic knowlege of C should work as well.

## Chapters and New Stories

The basis of NIF programming depends on two basic objects: **chapters** and **stories**. Here is a basic overview of the sections and definitions:

* Properties: An *attribute*, or a characteristic of any object in the story.
* Stories: A story is a sequence of events, comprised of chapters. Stories have very few basic properties in them; most properties are given with chapters.
* Chapters: Individual options, or parts of the story. The chapters have all the properties, including possible next chapters, names, and descriptions.

Let's put this to work with a basic example. Say we created a story in which you could choose to pick an option on a coin flip:

```
"Which side would you like to wager on?", says the man in front of you.

1. Heads.
2. Tails.

Enter option here: 1

You choose heads. He flips the coin, and it lands on heads. "Congratulations!", the man says.

The End
```

In this case, there are two chapters; one of which is the `heads` option, the other is the `tails` one. 

>Note: Chapters aren't necessarily chunks of a story! Don't let the terminology confuse you. Chapters are options which can be followed.

Here is a diagram of what this coin-flip example would look like:

![a diagram of the story](https://i.ibb.co/F50t6V1/Screen-Shot-2022-07-28-at-10-52-12-AM.png)

## New Stories

There isn't really much to know here. The syntax for starting a new story is:

```
newStory storyName(chapter firstChapter, string title);
```

For example, in the coin-flip example, we would have: 

```
newStory coinFlip(start, "The Coin Flip"); // passes in starting chapter and title
```

## Properties of chapters

Chapters, in essence, are classes, with properties inside them. The general form to create a new chapter is thus:

```
chapter newChapter(int ID, string logline); // creates a new chapter called (surprise, surprise!) newChapter
```

One of the most essential things to learn when working with a chapter is the properties. Here's a basic overview of each of them:

### ID

The ID of a chapter is a **unique** number (between 0 and 1000) associated with that chapter specifically. You can make the ID basically any number you would like (excepting '0' and '100', which are reserved by NIF).

We use IDs because we want to be able to re-use chapters, and reuse of chapters roots on the ID. We pass in IDs when insantiating a chapter.

The ID 100 is used for the "end" chapter, a special type of chapter which is used to end the story at any moment.

### Loglines

A logline is the summary of the option you see. In the coin-flip example, the logline of the "heads" option would be, simply, "Heads."

>Note: Starting chapters don't need loglines; they will automatically skip to the exposition.

### Exposition

The exposition is something you would see when you *select* that option. In the coin-flip example, the exposition of "heads" would be, "You choose heads. He flips the coins, and it lands on heads. "Congratulations!", the man says."

Make sure you add exposition when you want to, because NIF will not check for exposition.

>Note: logline and exposition are *not* the same thing!

### Next chapters

When working with chapters, we want to know if a leap from one chapter to another is valid. This is where the idea of next chapters comes from. Because C++, by default, has no way of knowing which chapter you want to go to next, you can let it know by using `>>`.

Confusing? Let's look back at our example from earlier: the coin flip.

```
newStory coinFlip(start, "The Coin Flip"); // passes in starting chapter and title

chapter start(1, " "); // notice there is no logline passed to this -- just a blank string
chapter heads(2, "Heads.");
chapter tails(3, "Tails.");
start >> heads; // adds heads as a possible next option
start >> tails; // adds tails as a possible next option

coinFlip.printOptions(); // print options and have the user select which one he/she wants
```
## NIF isn't that hard!

NIF isn't that hard to learn; just get to know how two or three functions work, and you should have an interactive fiction game running in no time!

Here is what the source code for the coin-flip would look like:

```
#include <nif.h>

int main() {
	newStory coinFlip(start, "The Coin Flip"); // passes in starting chapter and title
	
	chapter start(1, " ");
	chapter heads(2, "Heads.");
	chapter tails(3, "Tails.);
	start.expo = "'Which side would you like to wager on?', says the man in front of you.";
	heads.expo = "You choose heads. He flips the coins, and it lands on heads. "Congratulations!", the man says.";
	tails.expo = "You choose tails. He flips the coins, and it lands on heads. You lose!";

	start >> heads;
	start >> tails;
	
	coinFlip.printOptions();
}
```

>Note: only use `<nif.h>` if you have added nif.h, nif-err.h and their source files to `/usr/local/include`. If you have *not*, make sure you replace `#include <nif.h>` with `#include "nif.h"`.
