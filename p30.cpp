#include<bits/stdc++.h>
using namespace std;

//better
vector<int> FindMissingRepeatingNumbers(vector<int>& A){
    int n = A.size();
    int hash[n+1] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[A[i]]++;
    }
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;
        
        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {repeating,missing};
}

//optimal
vector<int> findMissingRepeatingNumbers(vector<int> A){
    long long  n = A.size();
    long long SN = (n*(n+1)) / 2;
    long long S2N = (n*(n+1)*(2*n+1)) / 6;
    long long S = 0,S2 = 0;
    for (int i = 0; i < n; i++)
    {
        S += A[i];
        S2 += (long long)A[i] * (long long)A[i];
    }
    long long val1 = (S-SN); //(X-Y)
    long long val2 = (S2 - S2N);
    val2 = val2/val1; // (X+Y)
    long long X = (val1+val2)/2;
    long long Y = val2 - X;
    return {(int)X,(int)Y};
}

int main(){
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}