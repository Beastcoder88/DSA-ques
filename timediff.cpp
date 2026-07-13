#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int times(string time){
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3, 2));
        int ss = stoi(time.substr(6, 2));

        int totalSeconds = hh * 3600 + mm * 60 + ss;

        return totalSeconds;
    }
    
    int secondsBetweenTimes(string startTime, string endTime) {
        int d = times(endTime);
        int s = times(startTime);
        int ans = d-s;
        return ans;
    }
};

int main() {
    
    return 0;
}