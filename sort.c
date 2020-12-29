#include <stdio.h>
#include "isort.h"
int main() {
    for(int i=0;i<50;i++){
        printf("please enter number No.%d: ",i+1);
        scanf("%d ",(arr+i));
    }
    size_t len=sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,len);
    printf("\n");
    for(int k=0;k<49;k++){
        printf("%d," ,*(arr+k));
    }
    printf("%d",*(arr+49));
    return 0;
}
