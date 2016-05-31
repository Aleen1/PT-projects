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

void initialise_heap(struct Node **root, int data){
	*root = (Node*)malloc(sizeof(Node));
	(*root)->data = data;
	(*root)->l = NULL;
	(*root)->r = NULL;
}

void add_to_heap(Node *root, int data){
	if (data < root->data){
		if (root->l == NULL)
		{
			Node *temp_node_heap = (Node*)malloc(sizeof(Node));
			temp_node_heap->data = data;
			temp_node_heap->l = 0;
			temp_node_heap->r = 0;

			root->l = temp_node_heap;

		}
		else
			add_to_heap(root->l, data);
	}
	else{
		if (root->r == NULL){
			Node *temp_node_heap = (Node*)malloc(sizeof(Node));
			temp_node_heap->data = data;
			temp_node_heap->l = 0;
			temp_node_heap->r = 0;
			root->r = temp_node_heap;
		}
		else
			add_to_heap(root->r, data);
	}
}

void heap_sort(Node *root, int *vec, int *sizee){
	if (root->l != 0)
		heap_sort(root->l, vec, sizee);
	*sizee = *sizee + 1;
	vec[*sizee] = root->data;
	if (root->r != 0)
		heap_sort(root->r, vec, sizee);
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

void initialise_list(Node_L **node){
	*node = NULL;
}

void add_to_list(Node_L** node, int data){
	Node_L *p = (Node_L*)malloc(sizeof(Node_L));
	p->data = data;
	p->next = *node;
	*node = p;
}

void remove_first_list(Node_L **node){
	if (node)
	{
		Node_L *p = *node;
		*node = p->next;
		free(p);
	}
}

int get_first_elem_list(Node_L *node){
	if (node)
		return node->data;
	return -1;
}

void initialise_queue(int *sq, int *eq){
	*sq = *eq = -1;
}

void add_to_queue(int *queue, int *sq, int *eq, int MAX, int data){
	if (*sq == (-1) && *eq == (-1))
		*sq = *eq = 1, queue[*eq] = data;
	else
	{
		int t = (*eq + 1) % (MAX - 1);
		if (t == 0)
			t = 1;
		queue[t] = data;
		*eq = t;
	}
}

int is_empty_queue(int *sq, int *eq){
	if (*sq == (-1) && *eq == (-1))
		return 1;
	else
		return 0;
}

void pop_queue(int *sq, int *eq, int MAX){
	int t = (*sq + 1) % (MAX - 1);
	if (t == 0)
		t = 1;
	*sq = t;
	if (*sq > *eq)
		*sq = *eq = -1;
}

int  queue_front(int *queue, int *sq){
	return queue[*sq];
}

void DFS(Node_L *V[], int *viz, int t){
	viz[t] = 1;
	while (V[t])
	{
		if (!viz[V[t]->data])
			DFS(V, viz, V[t]->data);
		remove_first_list(&V[t]);
	}
}

void BFS(Node_L *V[], int size, int *viz, int s){
	int *queue = (int*)malloc(sizeof(int) * size);
	int sq, eq;

	initialise_queue(&sq, &eq);

	add_to_queue(queue, &sq, &eq, size + 1, s);

	while (!is_empty_queue(&sq, &eq))
	{
		int node = queue_front(queue, &sq);
		viz[node] = 1;
		int el;
		do
		{
			el = get_first_elem_list(V[node]);
			if (el != -1)
			{
				if (!viz[el])
				{
					viz[el] = 1;
					add_to_queue(queue, &sq, &eq, size + 1, el);
				}
				remove_first_list(&V[node]);
			}
		} while (el != -1);

		pop_queue(&sq, &eq, size + 5);
	}

	free(queue);
}

void sort_top(Node_L *V[], int *viz, Node_L **stk, int t){
	viz[t] = 1;
	Node_L *p = V[t];
	while (p)
	{
		if (!viz[p->data])
		{
			viz[p->data] = 1;
			sort_top(V, viz, stk, p->data);
		}
		p = p->next;
	}
	add_to_list(stk, t);

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

void inline init(int k){
    st[k]=0;                //Generare de permutari
}

int succesor(int k){
    if(st[k]<N)
    {
        ++st[k];
        return 1;
    }
    return 0;
}

int solution(int k){
    return k==N;
}

void printSolution(int k){
    int i;
    for(i=1;i<=k;i++)
        printf("%d ",st[i]);
    printf("%c",'\n');
}

int valid(int k){
    int i;
    for(i=1;i<k;i++)
        if(st[i]==st[k])
            return 0;
    return 1;
}

void bkt(int k){
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

int MatrixChainOrder(int p[], int n){
    static int m[100][100], i, j, k, L, q;

    for (L=2; L<n; L++)
    {
        for (i=1; i<=n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = 0x3f3f3f;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}

void printSol_queen(int board[N][N]){
    int i = 0;
    for (; i < N; i++)
    {
        int j = 0;
        for (; j < N; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int isSafe(int board[N][N], int row, int col){
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return 0;

    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
}

int solveNQUtil(int board[N][N], int col){

    if (col >= N)
        return 1;
    int i = 0;
    for (; i < N; i++)
    {
        if ( isSafe(board, i, col) )
        {
            board[i][col] = 1;
            if ( solveNQUtil(board, col + 1) )
                return 1;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return 0;
}

int solveNQ(){
    int board[100][100] = { {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    if ( solveNQUtil(board, 0) == 0 )
    {
      printf("Solution does not exist");
      return 0;
    }
    printSol_queen(board);
    return 1;
}
