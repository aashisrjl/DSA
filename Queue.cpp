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

// check empty
int Isempty(qt *q) {
    return (q->rear < q->front);
}

// check full 
int Isfull(qt *q) {
    return (q->rear == N-1);
}

// made empty thw queue function 
void madeEmpty(qt *q){
	q->front = 0;
	q->rear = -1;
}

//enqueue function
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

//dequeue function
void Dequeue(qt *q) {
    int data;
    if (Isempty(q)) {
        printf("\nThere is no data to Dequeue\n");
    } else {
        data=q->items[q->front];
        q->front++;
        printf("\nDequeued item is: %d\n", data);
    }
}

// display function
void show(qt *q){
	if(!Isempty(q)){
		for(int i=q->front;i<=q->rear;i++){
			printf("| %d | \n",q->items[i]);
		}
	}else{
		printf("\n Sorry  you have no data to show! \n");
	}
}

//display front function
void front(qt *q){
	if(!Isempty(q)){
		printf("\n The value at front is %d", q->items[q->front]);
	}else{
		printf("\nSorry you have no data\n");
	}
}

// main program goes here
int main() {
    qt q;
    int n;
    int data;
    int choice;
    char name[10];
    printf("\n ||Enter your name to start action:|| \n");
    scanf("%s",&name);
    //initialllize the top and front
    madeEmpty(&q);
    do{
    	 system("CLS");
    	 printf(" \n \t\t ****** Dear %s you are welcome **********\n",name);
    	 printf("\n------------------------------------------------\n");
    printf("1. \t Dear %s Enter 1 for Enqueue the data:\n",name);
    printf("2. \t Dear %s Enter 2 for Dequeue the data: \n",name);
    printf("3. \t Dear %s Enter 3 to see the Queue data: \n",name);
    printf("4. \t Dear %s Enter 4 to see front data: \n",name);
    printf("5. \t Dear %s Enter 5 to clear the queue: \n",name);
    printf("6. \t Dear %s Enter 6 to exit: \n",name);
    scanf("%d", &n);
    system("CLS");

    switch (n) {
        case 1:
        	 system("CLS");
        	 printf(" \n \t\t ****** Dear %s you can perform Push Operation **********\n",name);
            printf("\n======= Pushing the data onto the Queue =======\n");
            Enqueue(&q);
            break;
            
        case 2:
        	 system("CLS");
        	printf(" \n \t\t ****** Dear %s you can perform Pop Operation **********\n",name);
            printf("\n======= Dequque the data from the Queue =======\n");
            Dequeue(&q);
            break;
            
        case 3:
        	 system("CLS");
        	 printf(" \n \t\t ****** %s your Queue data are as follow **********\n",name);
        	printf("===Displaying queue data:=====\n");
        	show(&q);
        	break;
        	
        case 4:
        	system("CLS");
        	printf(" \n \t\t ****** Dear %s your Queue front data are as follow **********\n",name);
        	front(&q);
       	    break;
       	   
       	   case 5:
       	    	system("ClS");
       	   	 	madeEmpty(&q);
       	   		printf(" \n \t\t ****** %s you clear the QUEUE **********\n",name);
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

