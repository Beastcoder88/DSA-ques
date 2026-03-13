#include<bits/stdc++.h>
using namespace std;

int BuySell(vector<int> prices){
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    for (int i = 0; i < n; i++)
    {
        int cost = prices[i]-mini;
        maxProfit = max(maxProfit,cost);
        mini = min(mini,prices[i]);
    }
    return maxProfit;
}

int main(){
    int n;
    cin>>n;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin>>price[i];
    }
    cout<<BuySell(price);
    return 0;
}