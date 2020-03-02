#include<stdio.h>
#include<stdlib.h>
int it, count, res[10], arr[10], n;
void swap(int a, int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
}
void heapify(int a){
        it++;
        int largest = a;
        int left = 2*a+1;
        int right = 2*a+2;
        if(left<=count && arr[largest]<arr[left])
                largest = left;
        if(right<=count && arr[largest]<arr[right])
                largest = right;
        printf("\nlargest = %d",largest);
        if(largest != a){
                swap(a, largest);

                heapify(largest);
        }
}

void buildHeap(){
        int i;
        printf("\n\tBuilding Heap");
        for(i=n/2; i>=0; i--)
                heapify(i);
        printf("\n\tHeap Built\n");
}

int delete(){
        int res = arr[0];
        printf("\nThe last element is %d", arr[count]);
        arr[0] = arr[count--];
        return res;
}

void heapSort(){
        int i,j;
        for(i=n-1; i>=0; i--){
                res[i] = delete();
                heapify(0);
                printf("\n");
                for(j=0; j<=count; j++)
                        printf("%d ", arr[j]);
        }
}

int main(){
        int i;
        scanf("%d", &n);
        count = n-1;
        for(i=0; i<n; i++){
                scanf("%d", &arr[i]);
        }
        buildHeap();
        for(i=0; i<n; i++)
                printf("%d ", arr[i]);
        heapSort();
        printf("\n");
        for(i=0; i<n; i++)
                printf("%d ", res[i]);
        printf("\n");
        printf("iterations = %d", it);
        return 0;
}
