#include<bits/stdc++.h>
using namespace std;

int nCr(int n,int r){
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}

//variation 1
int element(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

//variation 2 (brute force approach)
void generaterow(int n) {
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << " ";
}

//variation 2(optimal)
vector<int> generateRow(int n) {
    long long ans = 1;
    cout << ans << " "; 

    for (int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}
 
// variation 3
vector<vector<int>> pascalTriangle(int N){
    vector<vector<int>> ans;
    for (int i = 1; i < N; i++)
    {
        ans.push_back(generateRow(i));
    }
   return ans;
}
int main(){
     int n = 6;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << " ";
    }
    return 0;
}