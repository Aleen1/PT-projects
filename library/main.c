#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int v[100];

int main()
{
    Nod *head=malloc(sizeof(struct Nod));
    head->next=NULL;
    push_first(head,1);

    print_list(head);

    /*int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixsort(arr, n);
    printArray(arr, n);
    int arr1[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int arr2[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int arr3[] = {170, 45, 75, 90, 802, 24, 2, 66};
    quickSort(arr1,0,n-1);
    printArray(arr1, n);
    mergeSort(arr2,0,n-1);
    printArray(arr2, n);
    heapSort(arr3,n);
    printArray(arr3, n);*/

    /*readMat(adj_mat,5);
    bfs_mat(1,5);
    int i=1;
    for(;i<=5;++i)
        v[i]=0;
    dfs_mat(1,5);*/

    /*int as[]={1,2,3};
    printf("%d",count_coin(as,3,5));*/

    /*printf("%d",knapsack(6,10));*/


    return 0;
}
