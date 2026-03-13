#include<bits/stdc++.h>
using namespace std;

//brute
int maxProductSubArray(vector<int>& A){
    int n = A.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int product = 1;
            for (int k = i; k <= j; k++)
            {
                product *= A[k];
                maxi = max(maxi,product);
            }
        }   
    }
    return maxi;
}

//better
int MaxProductSubArray(vector<int>& A){
    int n = A.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int product = 1;
        for (int j = i; j < n; j++)
        {
            product *= A[j];
            maxi = max(maxi,product);
        }   
    }
    return maxi;
}

//optimal
int maxProductsubarray(vector<int>& A){
    int n = A.size();
    int maxi = INT_MIN;
    int pre = 1, suff = 1;
    for (int i = 0; i < n; i++)
    {
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;

        pre = pre * A[i];
        suff = suff * A[n-1-i];
        maxi = max(maxi,max(pre,suff));
    }
    return maxi;
}

int main(){
    vector<int> nums = {1,2,-3,0,-4,-5};
    cout<<"The maximum product subarray: "<<maxProductsubarray(nums);
    return 0;
}