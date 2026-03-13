#include<bits/stdc++.h>
using namespace std;

int maxconsecutive(vector<int>& arr){
    int n = arr.size();
    int c = 0,m=0;
    for(int i = 0; i < n; i++){
        if(arr[i]==1){
            c++;
            m = max(m,c);
        }
        else{
            c = 0;
        }
    }
    return m;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<maxconsecutive(arr);
    
    return 0;
}