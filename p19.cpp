#include<bits/stdc++.h>
using namespace std;


bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); 
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
//brute
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    int longest = 1;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

//better
int LongestSequence(vector<int>& A){
    if(A.size() == 0) return 0;
    sort(A.begin(),A.end());
    int n = A.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        if(A[i]-1 == lastSmaller){
            cnt++;
            lastSmaller = A[i];
        }
        else if(lastSmaller != A[i]){
            cnt = 1;
            lastSmaller = A[i];
        }
        longest = max(longest,cnt);
    }
    return longest;
}

//optimal
int longestSuccesive(vector<int>& A){
    int n = A.size();
    if(n==0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(A[i]);
    }
    for(auto it : st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<longestSuccesive(arr);
    return 0;
}