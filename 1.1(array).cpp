#include<stdio.h>
#include<stdlib.h>

struct List {
 int *B;
 int size;
 int length;
};

void Display(struct List list) {
 int i;
 printf("\nElements are\n");
 for (i = 0;i<list.length;i++)
  printf("%d ", list.B[i]);
}

void Insert(struct List* list, int index, int x) {
    if (index >= 0 && index <= list->length) {
       for (int i = list->length; i > index; i--) {
           list->B[i] = list->B[i - 1];
       }
       list->B[index] = x;
       list->length++;
    }
}

int Delete(struct List* list, int index) {
    int x = 0;
    if (index >= 0 && index < list->length) {
        x = list->B[index];
        for (int i = index; i < list->length - 1; i++)
            list->B[i] = list->B[i + 1];
            list->length--;
            return x;
        }
    }

void swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int LinearSearch(struct List list, int key) {
    for (int i = 0; i < list.length; i++) {
       if (key == list.B[i])
          return i;
    }
    return -1;
}
int Max(struct List list){
 int max = list.B[0];
  for(int i = 1;i < list.length; i++){
   if(list.B[i] > max)
   max = list.B[i];
  }
  return max;
}

int Min(struct List list){
 int min = list.B[0];
  for(int i = 1;i < list.length; i++){
   if(list.B[i] < min)
   min = list.B[i];
  }
  return min;
}

int Sum(struct List list){
    int sum = 0;
    for(int i = 0;i < list.length; i++)
    sum+=list.B[i];
    return sum;
}



void Reverse(struct List *list){
    int *C;
    int i,j;
 
    C=(int *)malloc(list->length*sizeof(int));
    for(i=list->length-1,j=0;i>=0;i--,j++)
        C[j]=list->B[i];
    for(i=0;i<list->length;i++)
        list->B[i]=C[i];
}


int main() {
 struct List list_1;
 int ch;
 int x, index;
 
 printf("Enter size of Array: ");
 scanf("%d", &list_1.size);
 list_1.B = (int*)malloc(list_1.size * sizeof(int));
 
 do{
  printf("\nMenu\n");
  printf("1. Insert\n");
  printf("2. Delete\n");
  printf("3. Search\n");
  printf("4. Sum\n");
  printf("5. Display\n");
  printf("6.Exit\n\n");
  
  printf("Enter your choice: ");
  scanf("%d", &ch);
  
  switch(ch){
   case 1: printf("Enter an element and index: ");
     scanf("%d%d", &x, &index);
     Insert(&list_1, index, x);
     break;
   case 2: printf("Enter index: ");
     scanf("%d", &index);
     Delete(&list_1, index);
     printf("Deleted element is %d\n", x);
     break;
   case 3: printf("Enter element to search: ");
     scanf("%d", &x);
     index = LinearSearch(list_1, x);
     printf("Element index is %d", index);
     break;
   case 4: printf("Sum is %d\n", Sum(list_1));
     break;
   case 5: Display(list_1);
  }
 }while (ch < 6);
 
 return 0;
}

