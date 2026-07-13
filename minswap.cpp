#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int minswap = 0;
        int zeros = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]==0){
                zeros++;
            }
        }
        int nonzeropart = nums.size()-zeros;
        for(int i = 0; i < nonzeropart; i++){
            if(nums[i]==0) minswap++;
        }
        return minswap;
    }
};

int main() {
    
    return 0;
}