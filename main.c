#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "stack.h"

void push(StackPtr s, char value);
char pop(StackPtr s);
void pop_all(StackPtr s);

int main(int argc, char **argv){
  
  int i,N,j;
  int error,count;
  Stack s;
  s.top=NULL;
  s.size=0;
  NodePtr top=NULL;
  
  for(i=1;i<argc;i++){
    error=0;
    count=0;
    for(j=0;j<strlen(argv[i]);j++){
      switch(argv[i][j]){
        case '{':
        case '[':
          push(&s,argv[i][j]);
          count++;
          //printf("%d ",count);
          break;
        case '}':{
          count--;
          if(pop(&s)!='{') error=1;
          else error=0;
          //printf("%d ",count);
          break;
        }
        case ']':{
          count--;
          if(pop(&s)!='[') error=1;
          else error=0;
          //printf("%d ",count);
          break;
        }
      }
      if(error==1) break;
    }
    if(count>0){
      printf("argv %d incorrect: too many opened parenthesis.\n",i);
    }
    else if(count<0){
      printf("argv %d incorrect: too many closed parenthesis.\n",i);
    }
    else{
      if(error==0){
        printf("argv %d correct!\n",i);
      }
      else if(error==1){
        printf("argv %d incorrect: mismatch.\n",i);
      }
    }
  }
  pop_all(&s);
   return 0;
}

void push(StackPtr s, char value){
  NodePtr new_node=(NodePtr) malloc(sizeof(Node));
  if(new_node){
    new_node->data=value;
    new_node->nextPtr=s->top;
    s->top=new_node;
    s->size++;
  }
}

char pop(StackPtr s){
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
}

void pop_all(StackPtr s){
  int value;
  //printf("Removing data: ");
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