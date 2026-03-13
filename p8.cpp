#include<bits/stdc++.h>
using namespace std;

//brute
int MissingNumber(vector<int>&a, int N) {
    for (int i = 1; i <= N; i++) {

        int flag = 0;

        for (int j = 0; j < N - 1; j++) {
            if (a[j] == i) {

                flag = 1;
                break;
            }
        }

        if (flag == 0) return i;
    }
    return -1;
}

//better
int missingNumber(vector<int>&a, int N) {

    int hash[N + 1] = {0}; 

    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++;

    for (int i = 1; i <= N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }
    return -1;
}

//optimal 1
int missingnumber(vector<int>& nums) {
    int n = nums.size();
    int s1 = n*(n+1)/2;
    int s2 = 0;
    for(int i = 0; i < n; i++){
        s2+=nums[i];
    }
    int d = s1-s2;
    return d;
}

//optimaL 2
int Missingnumber(vector<int>&a, int N) {

    int xor1 = 0, xor2 = 0;

    for (int i = 0; i < N - 1; i++) {
        xor2 = xor2 ^ a[i]; // XOR of array elements
        xor1 = xor1 ^ (i + 1); //XOR up to [1...N-1]
    }
    xor1 = xor1 ^ N; //XOR up to [1...N]

    return (xor1 ^ xor2); // the missing number
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int  i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<missingnumber(arr);
    return 0;
}