#ifndef __flags_h__
#define __flags_h__

int timeOut = 0; // flag to track when the interrupt is activated
int first = 1; // flag to indicate start of game

///// NON-FLAGS, global variables /////
// 1 = Strum, 2 = Fret, 3 = Whammy
int currTask = 0; // value to track current task
int score = 0; // value to track user score
int originalCount = 1000; // starting time for user reactions
int count = originalCount; // time to recieve user input
  
#endif // __flags_h__
