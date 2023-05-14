#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int isEmpty();

int main(int argc, char * argv[])
{
int ch, prevpop, i;
int count[26] = {0};
  while ((ch = getchar()) != EOF) {
    if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))
      continue;
    else if(ch =='<'){
      ch  = getchar();
      i = 0;
      if ((isalpha(ch))){
	push(ch);
	count[ch - 97]++;
	}
	else if(ch == '/'){
	  ch  = getchar();
	  prevpop = pop();

	  if(prevpop != ch){
	    printf("NOT Valid");
	    exit(1);
	    }
	}
    }
    if(isEmpty() == '1'){
      printf("NOT Valid");
      exit(1);
      }
    else{
      printf("Valid\n");
      for(i = 0;i<26; i++){
        if(count[i]>0)
          printf("\n %c \t %d \n",i+97, count[i] );
      }

}
}
  exit(0);
}
