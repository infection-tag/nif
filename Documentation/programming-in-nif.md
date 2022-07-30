# Programming in NIF

This is a little guide on creating your first interactive-fiction story with NIF.

## Everything is classes

Every object in NIF is a class. If you don't know what a class is, I would suggest reading about it online. 

Creating a new chapter is as easy as typing this line:

```
chapter chapterName(int chapterID, int logline);
```

To know more about `chapterID` and `logline`, read getting-started.md.

Creating a new story is as simple as:

```
newStory storyName(chapter firstChapter,)
```

## User I/O

User input/output is meant to be as smooth as possible. If creating a 