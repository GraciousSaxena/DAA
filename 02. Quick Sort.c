#include<stdio.h>
#include<stdlib.h>
int count = 0;
void print(int a[], int size){
        int i;
        printf("\nArray::\n");
        for(i=0; i<size; i++)
                printf("%d  ", a[i]);
        printf("\n\n");
}

void swap(int a[], int i, int j){
/*      
        a[i] = a[i] + a[j];
        a[j] = a[i] - a[j];
        a[i] = a[i] - a[j];
*/
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
//      count++;
//      print(a, 5);    
}

int partition(int a[], int low, int high){
    int pivot = a[low];
    int i = low, j = high;
//      printf("pivot = %d\n", pivot);

    while(i<j){
        while(a[i] <= pivot && i<high){
            count++;
            i++;
        }
        while(a[j] > pivot){
            j--;
            count++;
        }
        if(i<j){
//          printf("pivot = %d\n", pivot);
            count++;
            swap(a, i, j);
//          print(a, 5);
        }
    }
    count++;
    swap(a, low, j);
    return j;
}

void quickSort(int a[], int low, int high){
    int j;
    if(low<high){
//      printf("divide\n");
        count++;
        j = partition(a, low, high);
//      printf("quik\n");
        quickSort(a, low, j-1);
        quickSort(a, j+1, high);
    }
    return;
}
                
int main(){
    int a[] = {1,3,5,4,2}, A[600], B[600], C[600];
    int i,j;
    print(a,5);
    quickSort(a, 0, 4);
    print(a,5);
    printf("\nCount = %d\n", count);
    for(i=16; i<520; i*=2){
        for(j=0; j<i; j++){
                A[j] = j;
                B[j] = i-j;
                C[j] = rand() % i;
        }
//              for(j=0;j<16;j++)
//              {
//                      A[i]=j+1;
//                      B[i]=32-j;
//                      C[i]=rand()%25;
//              }
            printf("\ni = %d\n", i);
            count = 0;
            quickSort(A, 0, j-1);
            printf("Count for ASC = %d\n", count);
            count = 0;
            quickSort(B, 0, j-1);
            printf("Count for DESC = %d\n", count);
            count = 0;
            quickSort(C, 0, j-1);
            printf("Count for RAND = %d\n", count);
            printf("\n\n");
    }
    return 0;
}
