#include<iostream>
#include<vector>
#include<queue>


using namespace std;



int main(){
  int k,n;
  cin>>k>>n;
  vector <int> a[k];
  vector<int> res;
  for(int i = 0; i < k;i++){
    for(int j = 0; j< n;j++){
      int x;
      cin>>x;
      a[i].push_back(x);
    }
  }
  priority_queue < pair<int,int> , vector < pair<int,int> > , greater< pair<int,int> > > pq;
  int pointers[k] = {0};
  // for(int i = 0; i < k;i++){
  //   pq.push(make_pair(a[i][0],i));
  // }
  for (int i=0; i<k; i++){
    for (int j=0; j<n; j++){
      pq.push(make_pair(a[i][j],i));
    }
  }
  while (pq.empty()==false){
    cout<< pq.top().first << " " ;
    pq.pop();
  }
  cout << endl;
  // for(int i = 0 ; i< n*k;i++){
  //   pair <int,int> p,q;
  //   p = pq.top();
  //   if(!pq.empty()){
  //   pq.pop();
  // }
  //
  //  cout<<p.first<<" "<<p.second<<endl;
  //   int index = p.second;
  //   res.push_back(p.first);
  //   int next_index = pointers[index]+1;
  //   cout<<next_index<<endl;
  //   if(next_index < n){
  //   pointers[index]++;
  //   q.first = a[index][next_index];
  //   q.second = index;
  //  cout<<q.first<<" "<<q.second<<endl;
  //   pq.push(q);
  // }
  //   //cout<<"--------"<<endl;
  // }
  // for(int i = 0; i < res.size();i++){
  //   cout<<res[i]<<" ";
  // }
}
