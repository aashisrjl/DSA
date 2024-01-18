#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <math.h>
#define N 10

struct queue {
    int items[N];
    int front;
    int rear;
};
typedef struct queue qt;

int Isempty(qt *q) {
    return (q->rear < q->front);
}

int Isfull(qt *q) {
    return (q->rear == N-1);
}

void Enqueue(qt *q) {
    int data; 
    if (Isfull(q)) {
        printf("\nThere is overflow\n");
    } else {
        printf("\nEnter data to Enqueue: ");
        scanf("%d", &data); 
        q->rear++;
        q->items[q->rear] = data;
        printf("\n%d data is Enqueued to the queue\n", data);
    }
}


void Dequeue(qt *q) {
    int data;
    if (Isempty(q)) {
        printf("\nThere is no data to Dequeue\n");
    } else {
        data = q->items[q->front++];
        printf("\nDequeued item is: %d\n", data);
    }
}


int main() {
    qt queue;
    queue.front = 0;
	queue.rear= -1; //  top to -1

    int n;
    int data;
    int choice;
    char name[10];
    printf("\n ||Enter your name to start action:|| \n");
    scanf("%s",&name);
    do{
    	 system("CLS");
    	 printf(" \n \t\t ****** Dear %s you are welcome **********\n",name);
    	 printf("\n------------------------------------------------\n");
    printf("1. \t Dear %s Enter 1 for Enqueue the data:\n",name);
    printf("2. \t Dear %s Enter 2 for Dequeue the data: \n",name);
    printf("3. \t Dear %s Enter 3 to see the Queue data: \n",name);
    scanf("%d", &n);
    system("CLS");

    switch (n) {
        case 1:
        	 system("CLS");
        	 printf(" \n \t\t ****** Dear %s you can perform Push Operation **********\n",name);
            printf("\n======= Pushing the data onto the Queue =======\n");
            Enqueue(&queue);
            break;
            
        case 2:
        	 system("CLS");
        	printf(" \n \t\t ****** Dear %s you can perform Pop Operation **********\n",name);
            printf("\n======= Dequque the data from the Queue =======\n");
            Dequeue(&queue);
            break;
            
        case 3:
        	 system("CLS");
        	 printf(" \n \t\t ****** Dear %s your Queue data are as follow **********\n",name);
        	printf("===Displaying queue data:=====\n");
        	for(int i=0;i<=queue.front;i++){
        		printf("%d. %d \n",i,queue.items[i]);
			}
        	break;
        	
        default:
        	system("CLS");
        	printf(" \n \t\t ****** Dear %s  **********\n",name);
            printf("Please enter a valid instruction:\n");
            break;
    }
        printf(" \n \t\t ****** Mr/Mrs %s Thank You ! **********\n",name);
	printf("\n \n ===== press 0(zero) for main menu:=====\n");
	printf(" ===== press 1(zero) for exit:=====\n");
	scanf("%d",&choice);
//	if(choice == 1){
//		exit(1);
//	}
}while(choice == 0);

    return 0;
}

