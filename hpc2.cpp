#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

void BubbleSort(vector<int>& arr){
 int n = arr.size();
 bool swapped = true;
 
 while(swapped){
  swapped=false;
  #pragma omp parallel for
  for(int i=0;i<n-1;i++){
    if(arr[i]>arr[i+1]){
      swap(arr[i],arr[i+1]);
      swapped=true;
    }
  }
 }
}

void merge(vector<int>& arr,int l,int m,int r){
 vector<int> temp;
 int left = l;
  int right = m+1;
 
  
  while(left<=m && right<=r){
  if(arr[left]<=arr[right]){
    temp.push_back(arr[left]);
    left++;
  }
  else{
    temp.push_back(arr[right]);
    right++;
  }
  }
  
  while(left<=m){
  temp.push_back(arr[left]);
  left++;
  }
  
  while(right<=r){
  temp.push_back(arr[right]);
  right++;
  }
  
  for(int i=l;i<=r;i++){
  arr[i]=temp[i-l];
  }
}

void MergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            MergeSort(arr, l, m);
            #pragma omp section
            MergeSort(arr, m + 1, r);
        }
        merge(arr, l, m, r);
    }
}

int main(){
int n;
cout<<"Enter total no. of elements:";
cin>>n;

vector<int> arr(n);
cout<<"Enter the elements:";
for(int i=0;i<n;i++){
  cin>>arr[i];
}

vector<int> arr_bubble = arr;
double start1,end1;
start1=omp_get_wtime();
BubbleSort(arr_bubble);
end1=omp_get_wtime();

double Btime = end1-start1;

cout<<"Your sorting using Bubble sort is :";
  for(int num : arr_bubble){
    cout<<num<<" ";
  }
  
cout<<"Bubble Sort time:"<<Btime<<"sec"<<endl;

vector<int> arr_merge = arr;
double start2,end2;
start2=omp_get_wtime();
MergeSort(arr_merge,0,n-1);
end2=omp_get_wtime();

double Mtime = end2-start2;

cout<<"Your sorting using Merge Sort is:";
  for(int num : arr_merge){
    cout<<num<<" ";
  }

cout<<"Merge Sort time: "<<Mtime<<"sec"<<endl;
}
