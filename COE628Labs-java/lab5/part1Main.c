#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
  int ch, prevpop;
  while ((ch = getchar()) != EOF){
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    else if(ch =='<'){
      ch  = getchar();
      if ((isalpha(ch))){
        exit(1);
        } 
	prevpop = pop();
	if(prevpop != ch){
	  printf("NOT Valid");
	  exit(1);
	  }

}
  if(isEmpty() == 1){
    printf("NOT Valid");
    exit(1);
    }
  else{
  printf("Valid\n");
  exit(0);
  }
    
  }
  exit(0);
}
