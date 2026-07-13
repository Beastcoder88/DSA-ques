#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getFirstDigit(long long num) {
        while (num >= 10) {
            num /= 10;
        }
        return (int)num;
    }

    bool isValid(long long sum, int x) {
        int lastDigit = sum % 10;
        int firstDigit = getFirstDigit(sum);

        return firstDigit == x && lastDigit == x;
    }
    
    int countValidSubarrays(vector<int>& nums, int x) {
        int valid = 0;

        for (int i = 0; i < nums.size(); i++) {
            long long sum = 0;   // reset for every new starting index

            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];  // extend current subarray

                if (isValid(sum, x)) {
                    valid++;
                }
            }
        }

        return valid;
    }
};

int main() {
    
    return 0;
}