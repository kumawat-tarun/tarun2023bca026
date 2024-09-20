#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* ptr;
} s;
struct node*start=NULL,*temp;

void push(){
    int n;
    printf("Enter element for insert:-");
    scanf("%d",&n);
    temp = (struct node*)(malloc(sizeof(struct node)));
    temp->data=n;
    temp->ptr=NULL;
    temp->ptr=start;
    start=temp; 
}

void pop(){
  if(start==NULL){
    printf("list not founded\n");
  }
  else{
    temp=start;
    start=temp->ptr;
    free(temp);
  }
}

void display(){
  temp=start;
  while(temp->ptr!=NULL){
    printf("%d ->",temp->data);
    temp=temp->ptr;
  }
  printf("%d ->",temp->data);
  printf("null");
}

int main(){
     int a;
     do
     {
        printf("....Enter your operation...\n");
        printf("insert an element then press 1\n");
        printf("delete an element then press 2\n");
        printf("display an element then press 3\n");
        scanf("%d",&a);
        switch(a){
            case(1):
              push();
              break;
            case(2):
              pop();
              break;
            case(3):
              display();
              break; 
            default:
              printf(".....Exists....");
              break;       
        }

     } while (0<a && 4>a);
     
};