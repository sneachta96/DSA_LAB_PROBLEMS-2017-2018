#include<iostream>
#include<vector>


using namespace std;

struct node{
  long long int value;
  int array;
};

node heap[200009];
int heap_size;

int parent(int i){
  return (i-1)/2;
}
int left(int i ){
  return (2*i)+1;
}
int right(int i){
  return (2*i)+2;
}
void insert(node n){
  int index = heap_size ;
  heap[index] = n;
 //cout<<index<<endl;
  while(index > 0 && heap[parent(index)].value > heap[index].value){
  //cout<<parent(index)<<" "<<heap[parent(index)].value<<" "<<index<<" "<<heap[index].value<<endl;
    node temp = heap[parent(index)];
    heap[parent(index)] = heap[index];
    heap[index] = temp;
  //  cout<<parent(index)<<" "<<heap[parent(index)].value<<" "<<index<<" "<<heap[index].value<<endl;
    index = parent(index);
  }
}
void minHeapify(int index){
  int l = left(index);
  int r = right(index);
  int smallest;
  if(l < heap_size && heap[l].value < heap[index].value){
    smallest = l;
  }
  else{
    smallest = index;
  }
  if(r < heap_size && heap[r].value < heap[smallest].value){
    smallest = r;
  }
  if(smallest != index){
    node temp = heap[smallest];
    heap[smallest] = heap[index];
    heap[index] = temp;
    minHeapify(smallest);
  }
}
node extract_min(){
  node n = heap[0];
  heap[0] = heap[heap_size-1];
  heap_size = heap_size-1;
  minHeapify(0);
  return n;
}

int main(){
  int k,n;
  cin>>k>>n;
  heap_size = 0;
  vector < node > a[k];
  for(int i = 0; i< k;i++){
    for(int j = 0; j< n;j++){
      long long int  x;
      cin>>x;
      node n ;
      n.value = x;
      n.array = i;
      a[i].push_back(n);
    }
  }
  for(int i = 0;i < k;i++){
    for(int j = 0; j < n;j++){
      insert(a[i][j]);
      heap_size+=1;
    }
  }
  for(int i = 0; i < n*k;i++){
    node n = extract_min();
    cout<<n.value<<" ";
  }
  cout<<endl;
}
