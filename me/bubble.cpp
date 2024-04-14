#include<stdio.h>
int main(){
int i, j, n, temp,p;
int a[10];
printf("\n enter number n:");
scanf("%d", &n);
for(i=0; i<n; i++)
scanf("%d", &a[i]);
p=1;
for(i = 0; i <n; i++){
for(j = 0; j <n-1; j++){
if (a[j] > a[j+1]){
temp=a[j];
a[j]=a[j+1];

a[j+1]=temp;
}
}
}
printf("\n sorted items are:\n");
for(i=0; i<n; i++){
printf("%d\t", a[i]);
}

}
