#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector <int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0] = nums[0];
        if (nums.size() >= 2) {
            dp[1] = max(nums[0],nums[1]);
        }
        for ( int i = 1; i < dp.size(); i++) {
            if ( i-2 >= 0)  dp[i] = max(dp[i], nums[i] + dp[i-2]);
            dp[i] = max(dp[i], dp[i-1]);
        }
        return dp.back();
    }   
};