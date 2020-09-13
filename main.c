#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
int front=0,rear=0;
int queue[MAX_SIZE]; //using only 5 out of 6 (one left empty to distinguish full,empty queue)

int isfull(){
    if((rear+1)%MAX_SIZE==front) //when full
        return 1;
    return 0;
}
int isempty(){
    if(front==rear) //when empty
        return 1;
    return 0;
}

void push(){
    if(isfull()){ //when full
        puts("queue full");
        return -1;
    }
    int input;
    fputs("input->",stdout); scanf("%d%*c",&input);
    rear=(rear+1)%MAX_SIZE;
    queue[rear]=input;
}

int pop(){
    if(isempty()){ //when empty
        puts("queue empty");
        return -1;
    }
    front=(front+1)%MAX_SIZE;
    return queue[front];
}
int peak(){
    return queue[(front+1)%MAX_SIZE];
}

void printAll(){
    int i,size=0;
    if(front<rear)
        size=rear-front;
    else if(front>rear)
        size=(MAX_SIZE)-front+rear;
    fputs("queue ",stdout); printf("(front=%d, rear=%d)",front,rear);
    for(i=0;i<size;i++){
        printf("%d ",queue[(front+1+i)%MAX_SIZE]); //+1 because front always left empty to distinguish full,empty queue
    }puts("");
}

int main()
{
    int slct;
    puts("1.push");
    puts("2.pop");
    puts("3.print queue");
    puts("-1 to quit");
    while(slct!=-1){
        scanf("%d%*c",&slct);
        switch(slct){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printAll();
                break;
        }
    }
    return 0;
}
