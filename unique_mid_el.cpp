#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if((nums[mid]==nums[low]) || (nums[mid] == nums[high])){
                return false;
            }
            else{
                low++;
                high--;
            }
        }
        return true;
    }
};

int main() {
    
    return 0;
}