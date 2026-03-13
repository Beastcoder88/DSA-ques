#include<bits/stdc++.h>
using namespace std;

//brute
int majority(vector<int> v){
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if(v[i]==v[j]){
                cnt++;
            }
        }
        if(cnt>(n/2)){
            return v[i];
        }
    }
    return -1;
}

//better
int majorityelement(vector<int> v){
    map<int,int>mpp;
    for (int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;
    }
    for(auto it : mpp){
        if(it.second > (v.size()/2)){
            return it.first;
        }
    }
    return -1;
}

//optimal
int majorityElement(vector<int> v){
    int cnt = 0;
    int el;
    for (int i = 0; i < v.size(); i++)
    {
        if(cnt == 0){
            cnt = 1;
            el = v[i];
        }
        else if(v[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] == el) cnt1++;
    }
    if(cnt1>(v.size()/2)){
        return el;
    }
    return el;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    } 
    cout<<majorityElement(arr);    
    return 0;
}