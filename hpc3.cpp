#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

int parallelmax(vector<int> val){
  int max_val = val[0];
  
  #pragma omp parallel for
  for(int i=0;i<val.size();i++){
    if(val[i]>max_val){
      max_val = val[i];
    }
  }
  return max_val;
}

int parallelmin(vector<int> val){
  int min_val=val[0];
  
  #pragma omp parallel for
  for(int i =0; i<val.size();i++){
  if(val[i]<min_val){
  min_val = val[i];
  }
  }
  return min_val;
}

int parallelsum(vector<int> val){
  int sum=0;
  
  #pragma omp parallel for
  for(int i=0;i<val.size();i++){
  sum +=val[i];
  }
  return sum;
  
}

float parallelavg(vector<int> val){
  int sum = parallelsum(val);
  float avg = float(sum)/val.size();
  return avg;
}

int main(){
  int n;
  cout<<"Enter total no. of elements:";
  cin>>n;
  
  vector<int> val(n);
  
  cout<<"Enter all elements:";
  for(int i=0;i<n;i++){
    cin>>val[i];
  }
  
  cout<<"MAX value is :"<<parallelmax(val)<<endl;
  cout<<"Min value is :"<<parallelmin(val)<<endl;
  cout<<"Total sum is :"<<parallelsum(val)<<endl;
  cout<<"Average is :"<<parallelavg(val)<<endl;
}


