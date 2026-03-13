#include<bits/stdc++.h>
using namespace std;

//brute
int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; 

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

//better
int maxsubarraySum(int arr[], int n) {
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];

            maxi = max(maxi, sum); 
        }
    }
    return maxi;
}

//optimal
long long MaxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN;
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;
        }

        if (sum < 0) {
            sum = 0;
        }
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    } 
    cout<<MaxSubarraySum(arr,n); 
    return 0;
}