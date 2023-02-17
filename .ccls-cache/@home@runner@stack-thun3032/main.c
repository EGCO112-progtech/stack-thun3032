#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "stack.h"

void push(StackPtr s, int value);
int pop(StackPtr s);
void pop_all(StackPtr s);

int main(int argc, char **argv){
  
  int i,N,j;
  Stack s;
  s.top=NULL;
  s.size=0;
  NodePtr top=NULL;
  
  for(i=1;i<argc;i++){
    push(&s,atoi(argv[i]));
  }

  /*while(s.size>0){
    pop(&s);
  }*/
  pop_all(&s);

 /*
 Stack s;
 printf("Checking the parentheses in argv arguments\n");
  for(i=1;i<argc;i++){
   
     for(j=0;j<strlen(argv[i]);j++){
       // Use stack to help with the parentheses


     }


  }
*/



   return 0;
}

void push(StackPtr s, int value){
  NodePtr new_node=(NodePtr) malloc(sizeof(Node));
  if(new_node){
    new_node->data=value;
    new_node->nextPtr=s->top;
    s->top=new_node;
    s->size++;
  }
}

int pop(StackPtr s){
  int value;
  NodePtr t =s->top;
  if(s->size>0){
    int value=t->data;
    s->top=t->nextPtr;
    s->size--;
    //printf("\nremoving data: %d",value);
    free(t);
    return value;
  }
  else printf("\nNo more data available");
  return 0;
}

void pop_all(StackPtr s){
  int value;
  printf("Removing data: ");
  while(s->top!=NULL){
    NodePtr t =s->top;
    value=t->data;
    if(s->size>0){
    s->top=t->nextPtr;
    printf("%d ",value);
    s->size--;
    free(t);
    }
  }
}