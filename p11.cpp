#include<bits/stdc++.h>
using namespace std;

//brute
void sortColours(vector<int>& a){
    int count0 = 0,count1 = 1,count2 = 2;
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i]==0) count0++;
        else if(a[i]==1) count1++;
        else count2++;
    }
    for (int i = 0; i < count0; i++) a[i] = 0;
    for (int i = count0; i < (count0+count1); i++) a[i] = 1;
    for (int i = (count0+count1); i < a.size(); i++) a[i] = 2;
}

//optimal
void sortedAcolors(vector<int>& arr,int  n){
    int low = 0,mid = 0,high = n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}



int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sortedAcolors(arr,n);
    // sortColours(arr);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}