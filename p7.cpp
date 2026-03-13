#include<bits/stdc++.h>
using namespace std;

void intersectionArray(int A[],int B[],int m ,int n){
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<m && j<n){
        if(A[i]<B[j]){
            i++;
        }
        else if(B[j]<A[i]){
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    for(auto it : ans){
        cout << it <<" ";
    }
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
    cout<<"intersection of two sorted arrays : ";
    intersectionArray(arr,brr,n1,n2);

    return 0;
}