#ifndef __flags_h__
#define __flags_h__

int timeOut = 0; // flag to track when the interrupt is activated
int first = 1; // flag to indicate start of game
int second = 0;

///// NON-FLAGS /////
// 1 = Strum, 2 = Fret, 3 = Whammy
int currTask = 0; // value to track current task
int recievedTask = 0; // value to check user input
int score = 0;
int originalCount = 1000;
int count = originalCount; // intial time to recieve user input (ms)
  
#endif // __flags_h__
