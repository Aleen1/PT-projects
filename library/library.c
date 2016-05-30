#include "Library.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(Nod *head) {
	if(head->next != NULL){
		Nod *current = head -> next;
		while(current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
		}
		printf("\n");
	}
	else printf("Lista este goala\n");
}

void push_first(Nod *head, int value) {
	Nod *new_nod;
	new_nod = (Nod*)malloc(sizeof(Nod));
	new_nod->data = value;
	new_nod->next = head->next;
	head->next = new_nod;
}

void push_last(Nod *head, int value){
	Nod *current, *new_nod;
	current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	new_nod = (Nod*)malloc(sizeof(Nod));
	current->next = new_nod;
	new_nod->data = value;
	new_nod->next = NULL;
}

void push_poz(Nod *head, int poz, int value) {
	int iterator;
	Nod *current;
	Nod *added_node;
	iterator = 0;
	current = head;

	while (iterator<poz) {
		current = current->next;
		iterator++;
	}
	added_node = (Nod*)malloc(sizeof(Nod));
	added_node->next = current->next;
	current->next = added_node;
	added_node->data = value;
}

int pop_first(Nod * head) {
	int value;
	Nod *primul_element;
	primul_element = head->next;
	value = primul_element->data;
	head->next = primul_element->next;
	free(primul_element);
	return value;
}

int pop_last(Nod * head) {
	Nod *current, *deleted_node;
	int value;
	current = head->next;
	while (current->next->next != NULL) {
		current = current->next;
	}
	deleted_node = current->next;
	value = deleted_node->data;
	free(deleted_node);
	current->next = NULL;
	return value;
}

int pop_poz(Nod *head, int poz) {
	int it=0;
	int value;
	Nod *current = head;;
	Nod *del_node;
	while(it < poz) {
		current = current->next;
		++it;
	}
	del_node = current->next;
	value = del_node->data;
	current->next = del_node->next;
	free(del_node);
	return value;
}

void readArray(int arr[], int n){
	int i = 0;
	for (;i < n;i++)
	{
		printf("Element[%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

void printArray(int arr[], int n){
    int i = 0;
    for (; i<n; ++i)
        printf("%d ",arr[i]);
    printf("%c",'\n');
}

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int i;
    for(i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for(i=n-1; i>=0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void mergeArray(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i=0;
    j=0;
    k=l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r){
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        mergeArray(arr, l, m, r);
    }
}

void swapp(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partitionn(int arr[], int l, int h){
    int p = arr[h];
    int i = (l - 1);
    int j = l;
    for (; j <= h- 1; j++)
    {
        if (arr[j] <= p)
        {
            ++i;
            swapp(&arr[i], &arr[j]);
        }
    }
    swapp(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void quickSort(int arr[], int l, int h){
    if (l < h)
    {
        int pi = partitionn(arr, l, h);

        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, h);
    }
}

int getMax(int arr[], int n){
    int mx = arr[0],i;
    for (i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp){
    int output[n];
    int i, count[10] = {0};

    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n){
    int m = getMax(arr, n), exp;
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

void readMat(int a[100][100], int n){
    int i,j;
    printf("Enter the adjacency matrix:\n");
	for(i=1;i<=n;i++)
	  for(j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
    printf("%c",'\n');
}

void dfs_mat(int root, int n){
	int i;
	static int visited[100];
	visited[root]=1;
	for(i=1;i<=n;i++)
	  if(adj_mat[root][i] && !visited[i]) {
		printf("\n%d->%d",root,i);
		dfs_mat(i,n);
	}
}

void bfs_mat(int root, int n){
    int i,head = 0,tail = 0;
    int q[200];
    static int visited[100];
    printf("%d ",root);
    visited[root]=1;
    q[tail]=root;

    while(head<=tail)
    {
        root=q[head++];
        for(i=1;i<=n;i++)
        {
            if( adj_mat[root][i]==1 && !visited[i])
            {
                printf("%d ",i);
                visited[i]=1;
                ++tail;
                q[tail]=i;
             }
        }
    }
}

//Generare de permutari
void inline init(int k)
{
    st[k]=0;
}

int succesor(int k)
{
    if(st[k]<N)
    {
        ++st[k];
        return 1;
    }
    return 0;
}

int solution(int k)
{
    return k==N;
}
void printSolution(int k)
{
    int i;
    for(i=1;i<=k;i++)
        printf("%d ",st[i]);
    printf("%c",'\n');
}
int valid(int k)
{
    int i;
    for(i=1;i<k;i++)
        if(st[i]==st[k])
            return 0;
    return 1;
}
void bkt(int k)
{
   init(k);
   while(succesor(k))
   {
        if(valid(k))
        {
            if(solution(k))
                printSolution(k);
            else
                bkt(k+1);
        }
   }
}

int count_coin( int S[], int m, int n ){
    int i, j, x, y;
    int table[n+1][m];
    for (i=0; i<m; i++)
        table[0][i] = 1;

    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
            y = (j >= 1)? table[i][j-1]: 0;
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
}

int knapsack(int n, int g){
    static int d[100], w[100], p[100],i,j,ans;
    for(i=1; i<=n; i++)
        scanf("%d%d",&w[i],&p[i]);
    d[0]=1;

    for(i=1; i<=n; i++)
        for(j=g; j>=w[i]; j--)
            if(d[j-w[i]] && p[i]+d[j-w[i]]>=d[j])
                d[j]=p[i]+d[j-w[i]];

    for(i=0; i<=g; i++){
        if (d[i]>ans)
            ans=d[i];
    }
    return ans-1;
}
