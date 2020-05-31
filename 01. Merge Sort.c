#include<stdio.h>
#include<stdlib.h>
int c[10], count = 0;
void merge(int a[], int low, int mid, int high){
        int i = low, j = mid+1, k = low;
        while(i<=mid && j<=high){
                if(a[i] < a[j]){
                        c[k++] = a[i++];
                        count++;
//                      printf("inside1\n");
                }
                else{
                        c[k++] = a[j++];
                        count++;
//                      printf("inside2\n");
                }
        }
        while(i<=mid){
                count++;
                c[k++] = a[i++];
        }
        while(j<=high){
                c[k++] = a[j++];
                count++;
        }
        for(i = low; i<k; i++)
                a[i] = c[i];
}

void mergeSort(int a[], int low, int high){
        int mid = 0;

        if(low<high){
                count++;
                mid = (low + high)/2;
//              printf("mid = %d\n", mid);
                mergeSort(a, low, mid);
                 mergeSort(a, mid+1, high);
                merge(a, low, mid, high);
        }
        return;
}

int main(){
        int i,j, a[8] = {9,3,7,5,6,4,8,2}, A[600], B[600], C[600];
        printf("Array::\n");
        for(i = 0; i<8; i++)
                printf("%d ", a[i]);
        printf("\n");
        mergeSort(a, 0, 7);
        printf("\nArray::\n");
        for(i = 0; i<8; i++)
                printf("%d ",a[i]);
        printf("\nCount = %d\n", count);
        for(i = 15; i<520; i+=500){
                for(j = 0; j <= i; j++){
                        A[j] = j;
                        B[j] = i-j;
                        C[j] = rand()%i;
                }
                count = 0;
                mergeSort(A, 0, i-1);
                printf("\nCount for ASC = %d\n", count);
                count = 0;
                mergeSort(B, 0, i-1);
                printf("\nCount for DESC = %d\n", count);
                count = 0;
                mergeSort(C, 0, i-1);
                printf("\nCount for RAND = %d\n", count);
                printf("\n\n");
        }
        return 0;
}
