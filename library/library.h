#ifndef library
#define library

    int adj_mat[100][100],st[100],N;
    int n,v[100],v1[100],v2[100],v3[100],nr;

    typedef struct Nod{
        int data;
        struct Nod *next;
    }Nod;

    typedef struct Node{
		int data;
		struct Node *l, *r;
	}Node;

    typedef struct Node_L{
		int data;
		struct Node_L *next;
	}Node_L;

    /**Push functions for single-linked lists**/
    void print_list(Nod *head);
    void push_first(Nod *head, int value);
    void push_last(Nod *head, int value);
    void push_poz(Nod *head, int poz, int value);

    /**Pop functions for single-linked lists**/
    int pop_first(Nod * head);
    int pop_last(Nod * head);
    int pop_poz(Nod *head, int poz);

    /**Read/Print functions**/
    void printArray(int arr[], int n);
    void readArray(int arr[], int n);
    void readMat(int a[100][100], int n);

    /**Heap sort funtions**/
    void initialise_heap(Node **root, int data);
	void add_to_heap(Node *root, int data);
	void heap_sort(Node *root, int *vec, int *sizee);
    void heapify(int arr[], int n, int i);
    void heapSort(int arr[], int n);

    /**Merge sort functions**/
    void mergeArray(int arr[], int l, int m, int r);
    void mergeSort(int arr[], int l, int r);

    /**Quick sort functions**/
    void swapp(int* a, int* b);
    int partitionn(int arr[], int l, int h);
    void quickSort(int arr[], int l, int h);

    /**Radix sort funtions**/
    int getMax(int arr[], int n);
    void countSort(int arr[], int n, int exp);
    void radixsort(int arr[], int n);

    /**List functions**/
	void initialise_list(Node_L **node);
	void add_to_list(Node_L **node, int data);
	void remove_first_list(Node_L **node);
	int get_first_elem_list(Node_L *node);

    /**Queue functions**/
    void initialise_queue(int *sq, int *eq);
	void add_to_queue(int *queue, int *sq, int *eq, int MAX, int data);
	int is_empty_queue(int *sq, int *eq);
	void pop_queue(int *sq, int *eq, int MAX);
	int  queue_front(int *queue, int *sq);

    /**Traversing graphs/trees functions**/
    void DFS(Node_L *V[], int *viz, int t);
	void BFS(Node_L *V[], int size, int *viz, int s);
    void dfs_mat(int root, int n);
    void bfs_mat(int root, int n);
	void sort_top(Node_L *V[], int *viz, Node_L **stk, int t);

    /**Backtracking standard functions**/
    void inline init(int k);
    int succesor(int k);
    int solution(int k);
    void printSolution(int k);
    int valid(int k);
    void bkt(int k);
    void queens(int k);

    /**Dynamic Programming algorithms**/
    int count_coin( int S[], int m, int n );    // need to read m(nr of coins) and n(the sum)
    int knapsack(int n, int g);                 // need to read n(nr of obj) and g(max value)
    int MatrixChainOrder(int p[], int n);

#endif
