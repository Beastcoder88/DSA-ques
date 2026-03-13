#include<bits/stdc++.h>
using namespace std;

//brute
int RemoveDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int j = 0;
  for (int x: set) {
    arr[j++] = x;
  }
  return k;
}

//optimal
int removeDuplicates(int nums[],int n) {
    int temp = 1;
    for(int i = 1; i < n; i++){
        if(nums[i-1]!=nums[i]){
            nums[temp] = nums[i];
            temp++;
        }
    }
    return temp;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<removeDuplicates(arr,n)<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}