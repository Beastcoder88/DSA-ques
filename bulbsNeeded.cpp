#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<bool> visible(n,false);
        vector<int> diff(n+1,0);

        //step1
        for(int i = 0; i < n; i++){
            if(lights[i]>0){
                int range = lights[i];
                int left = max(0,i-range);
                int right = min(n-1,i+range);
                diff[left] += 1;
                if(right+1 < n){
                    diff[right+1] -= 1;
                }
            }
        }
        int activeCoverage = 0;
        for(int i = 0; i < n; i++){
            activeCoverage += diff[i];
            visible[i] = (activeCoverage>0);
        }

        //step2
        int bulbsneeded = 0;
        int i = 0;
        while(i<n){
            if(visible[i]){
                i++;
            }
            else{
                bulbsneeded++;
                i+=3;
            }
        }
        return bulbsneeded;
    }
};

int main() {
    
    return 0;
}