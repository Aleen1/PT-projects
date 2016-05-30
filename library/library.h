#ifndef library
#define library

    int adj_mat[100][100],st[100],N;

    typedef struct Nod{
        int data;
        struct Nod * next;
    }Nod;

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

    /**Traversing graphs/trees functions**/
    void dfs_mat(int root, int n);
    void bfs_mat(int root, int n);

    /**Backtracking standard functions**/
    void inline init(int k);
    int succesor(int k);
    int solution(int k);
    void printSolution(int k);
    int valid(int k);
    void bkt(int k);

    /**Dynamic Programming algorithms**/
    int count_coin( int S[], int m, int n );    // need to read m(nr of coins) and n(the sum)
    int knapsack(int n, int g);                 // need to read n(nr of obj) and g(max value)

#endif
