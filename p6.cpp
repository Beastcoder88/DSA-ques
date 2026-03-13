#include<bits/stdc++.h>
using namespace std;

//solution 1
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  map < int, int > freq;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    freq[arr1[i]]++;
  for (int i = 0; i < m; i++)
    freq[arr2[i]]++;
  for (auto & it: freq)
    Union.push_back(it.first);
  return Union;
}

//solution 2
void sortedArray(int a[],int b[],int m,int n){
    set<int>st;
    for (int i = 0; i < m; i++)
    {
        st.insert(a[i]);
    } 
    for (int i = 0; i < n; i++)
    {
        st.insert(b[i]);
    }
    for(auto it : st){
        cout << it <<" ";
    }
}

//solution 3
vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  int i = 0, j = 0; // pointers
  vector < int > Union; // Uninon vector
  while (i < n && j < m) {
    if (arr1[i] <= arr2[j]) // Case 1 and 2
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    } else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}

int main(){
    int n1,n2;
    cin>>n1;
    int arr[n1];
    for (int i = 0; i < n1; i++)
    {
        cin>>arr[i];
    }
    cin>>n2;
    int brr[n2];
     for (int i = 0; i < n2; i++)
    {
        cin>>brr[i];
    }
    n1 = sizeof(arr)/sizeof(arr[0]);
    n2 = sizeof(brr)/sizeof(brr[0]);
    cout<<"union of two sorted arrays : ";
    sortedArray(arr,brr,n1,n2);

    return 0;
}