#include<bits/stdc++.h>
using namespace std;

//brute
int subarraysWithXorK(vector<int> a, int k){
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++){
            int xorr = 0;
            for(int k = i; k <= j; k++){
                xorr = xorr^a[k];
            }
            if(xorr == k) cnt++;
        }
    }
    return cnt;
}

//better
int subArraysWithXorK(vector<int> a, int k){
    int n = a.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int xorr = 0;
        for(int j = i; j < n; j++){
            xorr = xorr^a[j];
            if(xorr == k) cnt++;
        }
    }
    return cnt;
} 

//optimal
int SubArraysWithXorK(vector<int> a, int k){
    int n = a.size();
    map<int,int> mpp;
    int xr = 0;
    mpp[xr]++;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        xr = xr^a[i];
        int x = xr^k;
        cnt+=mpp[x];
        mpp[xr]++;
    }
    return cnt;
} 

int main(){
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subArraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}