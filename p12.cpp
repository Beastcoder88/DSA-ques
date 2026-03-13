#include<bits/stdc++.h>
using namespace std;

//brute
int appearance(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        int num = arr[i],count = 0;
        for (int j = 0; j < n; j++)
        {
            if(arr[j]==num){
                count++;
            }
        }
        if(count == 1) return num;
    }
    return -1;
} 

//better
int Appear(vector<int>& arr){
    map<long long,int>mpp;
    for (int i = 0; i < arr.size(); i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        if(it.second == 1){
            return it.first;
        }
    }
    
}


//better
int appear(int arr[],int n){
    int maxi =  arr[0];
    int hash[maxi];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi,arr[i]);
        hash[maxi] = {0};
    }
    for (int j = 0; j < n; j++)
    {
        hash[arr[j]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if(hash[arr[i]] == 1){
            return arr[i];
        }
    }
    return -1;
}

//optimal
int APPEAR(vector<int>& arr){
    int xorr = 0;
    for (int i = 0; i < arr.size(); i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<APPEAR(arr);
    return 0;
}