// code of single linked list operations
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*ptr;
}; 
struct node*start=NULL,*temp,*new1,*prev,*next;

void create(){
     int d;
     int t;
     printf("Enter your element which are you insert in node:-");
     scanf("%d",&d);
     start = (struct node *)(malloc(sizeof(struct node)));
     start->data=d;
     start->ptr=NULL;
     temp=start;
     printf("you want to add new node:-");
     printf("then press 1 else press 0");
     scanf("%d",&t);
     while(t==1){
        printf("Enter your element which are you insert in node:-");
        scanf("%d",&d);
        new1=(struct node*)(malloc(sizeof(struct node)));
        new1->data=d;
        new1->ptr=NULL;
        temp->ptr=new1;
        temp=temp->ptr;
        printf("want to continue");
        scanf("%d",&t);
     }

     
}

void insert_first(){
      if(start==NULL){
        printf("list not founed");
      }
      else{
        int n;
        printf("Enter new element for insert:-");
        scanf("%d",&n);
        new1=(struct node*)(malloc(sizeof(struct node)));
        new1->data=n;
        new1->ptr=NULL;
        new1->ptr=start;
        start=new1;
      };
};

void insert_last(){
       if(start==NULL){
        printf("list not founded");
       }
       else{
           int n;
           printf("emter new element for insert:-");
           scanf("%d",&n);
           new1=(struct node*)(malloc(sizeof(struct node)));
           new1->data=n;
           new1->ptr=NULL;
           temp=start;
           while(temp->ptr!=NULL){
                temp=temp->ptr;
           }
           temp->ptr=new1;
       };
};

void insert_mid(){
    if(start==NULL){
        printf("list are not founded");
    }
    else{
        int n,p,i=1,post;
        printf("Enter new element:-");
        scanf("%d",&n);
        new1=(struct node*)(malloc(sizeof(struct node)));
        new1->data=n;
        new1->ptr=NULL;
        printf("Enert your position:-");
        scanf("%d",&p);
        next=start;
        while(i<p){
            prev=next;
            next=next->ptr;
            i++;
        }
        prev->ptr = new1;
        new1->ptr=next;
    };
};

void delete_first(){
    if(start==NULL){
        printf("list not founded");
    }
    else{
        temp=start;
        start=start->ptr;
        free(temp);
    }
}

void delete_last(){
    if(start==NULL){
        printf("list id not founded");
    }
    else{
        temp=start;
        while(temp->ptr!=NULL){
            prev=temp;
            temp=temp->ptr;
        }
        prev->ptr=NULL;
        free(temp);
    }
}

void delete_mid(){
    if(start==NULL){
        printf("list is not founded");
    }
    else{
        int p,i;
        printf("Enter position:-");
        scanf("%d",&p);
        next=start;
        while(i<p){
            prev=next;
            next=next->ptr;
            i++;
        }
        temp=next->ptr;
        prev->ptr=next;
        free(next);

    }
}

void display(){
    if(start==NULL){
        printf("list not founded");
    }
    else{
        temp=start;
        while(temp->ptr!=NULL){
            printf("%d ->",temp->data);
             temp=temp->ptr;
        }
        printf("%d ->",temp->data);
        printf("null");
    }
}
int main(){
    int a;
    do
    {
        printf("....which are operation you want do....\n");
        printf("create a node then press key 1\n");
        printf("Insert on first then press key 2\n");
        printf("Insert on last then press key 3\n");
        printf("Insert on middle then press key 4\n");
        printf("Delete on first then press key 5\n");
        printf("Delete on last then press key 6\n");
        printf("Delete on middle then press key 7\n");
        printf("display ilnked list then press key 8\n");
    
    scanf("%d",&a);
    switch (a)
    {
    case 1:
        create();
        break;
    case 2:
        insert_first();
        break;    
    case 3:
        insert_last();
        break;
    case 4:
        insert_mid();
        break;
    case 5:
        delete_first();
        break;
    case 6:
        delete_last();
        break;
    case 7:
        delete_mid();
        break;  
    case 8:
        display();
        break;  
    default:
        printf("......Exists......\n");
        break;
    }
    } while (0<a && 9>a);
}