#include<bits/stdc++.h>
using namespace std;

//brute
int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); 
    int cnt = 0; 

    for (int i = 0 ; i < n; i++) { 
        for (int j = i; j < n; j++) {

            int sum = 0;
            for (int K = i; K <= j; K++)
                sum += arr[K];

            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

//better
int findAllsubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); 
    int cnt = 0;

    for (int i = 0 ; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) { 
            sum += arr[j];

            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

//optimal
int findAllsubarraysWithGivensum(vector < int > & arr, int k){
    map<int,int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        preSum += arr[i];
        int remove = preSum-k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }
    return cnt;
} 

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k = 6;
    int cnt = findAllsubarraysWithGivensum(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
    // return 0;
}