#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int arr[1000009];
int n;
bool minHeap(int i){
    int left = (2*i)+1;
    int right = (2*i)+2;
    //cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right]<<endl;
    if(left < n && arr[i] > arr[left]  || left<n && !minHeap(left)){
      return false;
    }
    if(right < n && arr[i] > arr[right] || right<n && !minHeap(right)){
      return false;
    }
    return true;
}

bool maxHeap(int i){
  int left = (2*i)+1;
  int right = (2*i)+2;
  //cout<<arr[i]<<" "<<arr[left]<<" "<<arr[right]<<endl;
  if(left < n && arr[i] < arr[left]  || left<n && !maxHeap(left)){
    return false;
  }
  if(right < n && arr[i] < arr[right] || right<n && !maxHeap(right)){
    return false;
  }
  return true;
}

int main(){
  cin>>n;
  memset(arr,0,sizeof(arr));
  for(int i = 0; i < n;i++){
    cin>>arr[i];
  }
  int flag1=0,flag2=0;
  if(arr[0] <= arr[1] && arr[0] < arr[2] && minHeap(1) && minHeap(2)){
    flag1 = 1;
  }
  else if(arr[0] >= arr[1] && arr[0] > arr[2] && maxHeap(1) && maxHeap(2)){
  //  cout<<"hey"<<endl;
    flag2 = 1;
  }
  if(flag1 == 1){
    cout<<"MINHEAP"<<endl;
  }
  else if(flag2 == 1){
    cout<<"MAXHEAP"<<endl;
  }
  else{
    cout<<"NONE"<<endl;
  }
}
