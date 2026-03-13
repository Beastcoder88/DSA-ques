#include<bits/stdc++.h>
using namespace std;

//brute or solution 1
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size();

    int len = 0;
    for (int i = 0; i < n; i++) { 
        for (int j = i; j < n; j++) {
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s += a[K];
            }

            if (s == k)
                len = max(len, j - i + 1);
        }
    }
    return len;
}

//solution 2
int longestSubarray(vector<int>& a,long long k){
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum+=a[i];
        if(sum==k){
            maxLen = max(maxLen,i+1);
        }
        long long rem = sum-k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i-preSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

//solution 3
int LongestSubarray(vector<int>& a,long long k){
    int left = 0,right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();
    while(right<n){
        while(left <= right && sum>k){
            sum -= a[left];
            left++;
        }
        if(sum==k){
            maxLen = max(maxLen,right-left+1);
        }
        right++;
        if(right<n) sum+=a[right];
    }
    return maxLen;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<LongestSubarray(arr,k);
    return 0;
}