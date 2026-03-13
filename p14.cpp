#include<bits/stdc++.h>
using namespace std;

//brute
vector<int> twoSum(vector<int>& a,int target){
    int n = a.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(a[i]+a[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }   
    }   
    return {-1,-1};
}

//better
vector<int> TwoSum(vector<int>& a,int target){
    map<int,int>mpp;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        int more = target - num;
        if(mpp.find(more) != mpp.end()){
            return {mpp[more],i};
        }
        mpp[num] = i;
    }
    return {-1,-1};
}

//optimal
string twosum(vector<int>& a,int target){
    int n = a.size();
    int left = 0,right = n-1;
    sort(a.begin(),a.end());
    while(left<right){
        int sum = (a[left]+a[right]);
        if(sum == target){
            return "YES";
        } 
        else if(sum > target){
            right--;
        }
        else{
            left++;
        }
    }
    return "NO";
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    string res = twosum(arr,k);
    cout<<res;
    return 0;
}