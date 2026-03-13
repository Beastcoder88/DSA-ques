#include<bits/stdc++.h>
using namespace std;

int linearsearch(int arr[],int n,int num){
    for (int i = 0; i < num; i++)
    {
        if(arr[i] == num ){
            return i;
        }
    }
    return -1;
}

int sumDivisibleByK(vector<int>& nums, int k) {
    unordered_map<int,int> mpp;
    for(int i = 0; i < nums.size(); i++){
        mpp[nums[i]]++;
    }
    int sum = 0;
    for(auto it: mpp){
        if(it.second%k==00){
            sum+=(it.first*it.second);
        }
    }
    return sum;
}

int main(){
    int n,num;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    } 
    cout<<"enter number to be search : ";
    cin>>num;
    cout<<linearsearch(arr,n,num); 
    return 0;
}