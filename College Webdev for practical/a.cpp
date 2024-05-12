#include <iostream>
#include <vector>
#include <queue>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i=0; i<n; i++){
      int key = arr[i];
      int j = i-1;
      while(j>=0 && key<arr[j]){
        arr[j+1] = arr[j];
        j = j-1;
      }
      arr[j+1] = key;
    }
for(int i=0; i<n; i++){
  cout<<arr[i]<<" ";
}
}

void merge(int arr[], int lb, int mid, int ub){
  int i = lb, j = mid+1, k = lb, arr_sorted[ub];
  while(i<=mid && j<=ub){
    if(arr[i]<=arr[j]){
      arr_sorted[k] = arr[i];
      i++;
    }
    else{
      arr_sorted[k] = arr[j];
      j++;
    }
    k++;
  }
  while(i<=mid){
    arr_sorted[k] = arr[i];
    k++;i++;
  }
  while(j<=ub){
    arr_sorted[k] = arr[j];
    k++;j++;
  }
  for(int t = lb; t<=ub; t++){
    arr[t] = arr_sorted[t];
  }
}

void mergeSort(int arr[], int lb, int ub){
  if(lb<ub){
    int mid = lb + (ub-lb)/2;
    mergeSort(arr, lb, mid);
    mergeSort(arr, mid+1, ub);
    merge(arr, lb, mid, ub);
  }
}

int partition(int arr[], int lb, int ub){
  int pivot = arr[lb];
  int start = lb, end = ub;
  while(start<end){
    while(arr[start]<=pivot){
      start++;
    }
    while(arr[end]>pivot){
      end--;
    }
    if(start<end){
      swap(arr[start], arr[end]);
    }
  }
  swap(arr[lb], arr[end]);
  return end;
}

void quickSort(int arr[], int lb, int ub){
  if(lb<ub){
    int loc = partition(arr, lb, ub);
    quickSort(arr, lb, loc);
    quickSort(arr, loc+1, ub);
  }
}

void max_heapify(int arr[], int n, int i){
  int largest = i;
  int left = 2*i + 1;
  int right = 2*i + 2;
  while(left<=n && arr[largest]<arr[left]){
    largest = left;
  }
  while(right<=n && arr[largest]<arr[right]){
    largest = right;
  }
  if(largest != i){
    swap(arr[largest], arr[i]);
    max_heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n){
  for(int i = n/2; i>=0; i--){
    max_heapify(arr, n-1, i);
  }
  for(int i = n-1; i>0; i--){
    swap(arr[0], arr[i]);
    max_heapify(arr, i-1, 0);
  }
}

int maximum(int arr[], int n){
  int max = arr[0];
  for(int i = 0; i<n; i++){
    if(arr[i]>max){
      max = arr[i];
    }
  }
  return max;
}

void countSort(int arr[], int n){
  int k = maximum(arr, n);
  int *count = new int[k+1];
  for(int i = 0; i<=k; i++){
    count[i] = 0;
  }
  int arr_sorted[n];
  for(int i = 0; i<n; i++){
    ++count[arr[i]];
  }
  for(int i = 1; i<=k; i++){
    count[i] = count[i] + count[i-1];
  }
  for(int i = n-1; i>=0; i--){
    arr_sorted[--count[arr[i]]] = arr[i];
  }
  for(int i = 0; i<n; i++){
    arr[i] = arr_sorted[i];
  }
}

void addEdge(vector<vector<int>> & adjlist, int u, int v){
  adjlist[u].push_back(v);
}

void bfs(vector<vector<int>> &adjlist, int startNode, vector<bool> visited){
  queue<int> q;
  visited[startNode] = true;
  q.push(startNode);

  while(!q.empty()){
    int currentNode = q.front();
    q.pop();
    cout<<currentNode<<" ";

    for(int neighbor : adjlist[currentNode]){
      if(visited[neighbor] == false){
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

void dfs_recursive(vector<vector<int>> &adjlist, int node, unordered_set<int> &visited){
  visited.insert(node);
  cout<<node<<" ";

  for(int neighbor : adjlist[node]){
    if(visited.find(neighbor) == visited.end()){
      dfs_recursive(adjlist, neighbor, visited);
    }
  }
    
}

void dfs(vector<vector<int>> &adjlist, int start){
  unordered_set<int> visited;
  dfs_recursive(adjlist, start,  visited);
}

int max(int x, int y){
  return (x>y) ? x : y;
}

int knapSack(int n, int W, int v[], int w[]){
  int k[n+1][W+1];
  for(int i = 0; i<=n; i++){
    for(int wt=0; wt<=W; wt++){
      if(i == 0 || wt == 0){
        k[i][wt] = 0;
      }
      else if(wt >= w[i-1]){
        k[i][wt] = max(v[i-1] + k[i-1][wt - w[i-1]], k[i-1][wt]);
      }
      else{
        k[i][wt] = k[i-1][wt];
      }
      
    }
  }
  return k[n][W];
}

vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

void strassenMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C) {
    int n = A.size();
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Create submatrices
    vector<vector<int>> A11(n / 2, vector<int>(n / 2));
    vector<vector<int>> A12(n / 2, vector<int>(n / 2));
    vector<vector<int>> A21(n / 2, vector<int>(n / 2));
    vector<vector<int>> A22(n / 2, vector<int>(n / 2));
    vector<vector<int>> B11(n / 2, vector<int>(n / 2));
    vector<vector<int>> B12(n / 2, vector<int>(n / 2));
    vector<vector<int>> B21(n / 2, vector<int>(n / 2));
    vector<vector<int>> B22(n / 2, vector<int>(n / 2));

    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + n / 2];
            A21[i][j] = A[i + n / 2][j];
            A22[i][j] = A[i + n / 2][j + n / 2];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + n / 2];
            B21[i][j] = B[i + n / 2][j];
            B22[i][j] = B[i + n / 2][j + n / 2];
        }
    }

    // Calculate Strassen's products
    vector<vector<int>> M1(n / 2, vector<int>(n / 2));
    vector<vector<int>> M2(n / 2, vector<int>(n / 2));
    vector<vector<int>> M3(n / 2, vector<int>(n / 2));
    vector<vector<int>> M4(n / 2, vector<int>(n / 2));
    vector<vector<int>> M5(n / 2, vector<int>(n / 2));
    vector<vector<int>> M6(n / 2, vector<int>(n / 2));
    vector<vector<int>> M7(n / 2, vector<int>(n / 2));

    strassenMultiply(addMatrix(A11, A22), addMatrix(B11, B22), M1);
    strassenMultiply(addMatrix(A21, A22), B11, M2);
    strassenMultiply(A11, subtractMatrix(B12, B22), M3);
    strassenMultiply(A22, subtractMatrix(B21, B11), M4);
    strassenMultiply(addMatrix(A11, A12), B22, M5);
    strassenMultiply(subtractMatrix(A21, A11), addMatrix(B11, B12), M6);
    strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21, B22), M7);

    // Calculate result matrix C
    vector<vector<int>> C11(n / 2, vector<int>(n / 2));
    vector<vector<int>> C12(n / 2, vector<int>(n / 2));
    vector<vector<int>> C21(n / 2, vector<int>(n / 2));
    vector<vector<int>> C22(n / 2, vector<int>(n / 2));

    C11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);
    C12 = addMatrix(M3, M5);
    C21 = addMatrix(M2, M4);
    C22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);

    // Combine submatrices into C
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            C[i][j] = C11[i][j];
            C[i][j + n / 2] = C12[i][j];
            C[i + n / 2][j] = C21[i][j];
            C[i + n / 2][j + n / 2] = C22[i][j];
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// #define V 5 // Number of vertices in the graph

void addEdge(vector<vector<pair<int, int>>> &adjList, int u, int v, int weight) {
    adjList[u].push_back(make_pair(v, weight));
    adjList[v].push_back(make_pair(u, weight));
}

int minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int key[], int vertices) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < vertices; i++)
        cout << parent[i] << " - " << i << " \t" << key[i] << " \n";
}

void primMST(vector<vector<pair<int, int>>> &adjList, int vertices) {
    int parent[vertices];
    int key[vertices];
    bool mstSet[vertices];
    for (int i = 0; i < vertices; i++)
        key[i] = INT_MAX, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;
        for (auto edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (mstSet[v] == false && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
  printMST(parent, key, vertices);
}


int main(){
  cout<<"Practice on"<<endl;
  // int arr[5] = {3,0,8,4,2};
  // mergeSort(arr, 0, 4);
  // countSort(arr, 5);
  // for(int i = 0; i < 5; i++){
  //   cout<<arr[i]<<" ";
  // }
  cout<<endl;

  // cout<<"Enter the number of vertex "<<endl;
  // int vertex, edge, u,v;
  // cin>>vertex;
  // vector<vector<int>> adjlist(vertex);
  // cout<<"Enter the number of edge "<<endl;
  // cin>>edge;
  // for(int i = 1 ;i<=edge; i++){
  //   cout<<"Enter the edge associated with edge "<<i<<endl;
  //   cin>>u>>v;
  //   addEdge(adjlist, u,v);
  // }

  // vector<bool> visited(vertex, false);
  // // bfs(adjlist, 0, visited);
  // dfs(adjlist, 0);

  // int n,W;
  // cout<<"Enter the number of items: "<<endl;
  // cin>>n;
  // cout<<"Enter the capacity of knapsack: "<<endl;
  // cin>>W;
  // int v[n], w[n];
  // for(int i = 0; i<n; i++){
  //   cout<<"Enter the value and weight of knapsack: "<<endl;
  //   cin >> v[i];
  //   cin >> w[i];
  // }
  // cout<<knapSack(n , W, v, w)<<endl;

  // vector<vector<int>> A = {{1, 2}, {3, 4}};
  // vector<vector<int>> B = {{5, 6}, {7, 8}};
  int n;
  cout<< "Enter the size of matrix"<<endl;
  cin>>n;
  vector<vector<int>> A(n, vector<int>(n));
  vector<vector<int>> B(n, vector<int>(n));

  cout<<"Enter the element of the A matrix"<<endl;
  for(int i=0; i<n; i++){
    for(int j= 0; j<n; j++){
      cout<<"Enter the element at A"<<i+1<<j+1<<endl;
      cin>>A[i][j];
    }
  }
  cout<<"Enter the element of the B matrix"<<endl;
  for(int i=0; i<n; i++){
    for(int j= 0; j<n; j++){
      cout<<"Enter the element at B"<<i+1<<j+1<<endl;
      cin>>B[i][j];
    }
  }
  // int n = A.size();
  vector<vector<int>> C(n, vector<int>(n));
  strassenMultiply(A, B, C);
  cout << "Matrix A:\n";
  printMatrix(A);
  cout << "Matrix B:\n";
  printMatrix(B);
  cout << "Matrix C (Result of Multiplication):\n";
  printMatrix(C);


  int vertices, edges;
  cout << "Enter the number of vertices in the graph: ";
  cin >> vertices;
  vector<vector<pair<int, int>>> adjList(vertices);

  cout << "Enter the number of edges: ";
  cin >> edges;
  for (int j = 0; j < edges; j++) {
      int u, v, weight;
      cout << "Enter vertices associated with edge " << j + 1 << " and its weight: ";
      cin >> u >> v >> weight;
      addEdge(adjList, u, v, weight);
  }

  primMST(adjList, vertices);
  return 0;
}