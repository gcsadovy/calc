#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE]; //buffer for ungetch //the static declaration means that no other program can access the variables as they are used here
static int bufp = 0; //next free position in buf

int getch(void) //get a (possibly pushed back) character
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) //push character back on input
{
  if(bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

//internal static variables can provide private permenant storage within a single function


