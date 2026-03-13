#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &A) {
    int n = A.size();

    int ind = -1; 
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] < A[i + 1]) {
            ind = i;
            break;
        }
    }

    if (ind == -1) {
        reverse(A.begin(), A.end());
        return A;
    }

    for (int i = n - 1; i > ind; i--) {
        if (A[i] > A[ind]) {
            swap(A[i], A[ind]);
            break;
        }
    }
    reverse(A.begin() + ind + 1, A.end());

    return A;
}

//brute
vector<int> Leaders(vector<int>& A){
    int n = A.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        bool leader = true;
        for (int j = i+1; j < n; j++)
        {
            if(A[j]>A[i]){
                leader = false;
                break;
            }
        }  
         if(leader == true) ans.push_back(A[i]); 
    }
    return ans;
}

//optimal
vector<int> leaders(vector<int> A){
    int n = A.size();
    int maxi = INT_MIN;
    vector<int> ans;
    for (int i = n-1; i >= 0; i--)
    {
        if(A[i]>maxi){
            ans.push_back(A[i]);
        }
        maxi = max(A[i],maxi);
        
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int> ans = nextGreaterPermutation(arr); 
  
    for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
    }
    return 0;
}