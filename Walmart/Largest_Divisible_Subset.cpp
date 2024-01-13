Links :- https://leetcode.com/problems/largest-divisible-subset/description/

Intution :- 
  A vairation of standard "LIS" of dp.
  Change the tabulation code of lis add (nums[ind]%nums[prev]==0) and you're good to go.

Time Complexity :- O(N^2)
Space Complexity :- O(2*N)

Code :- 

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums){
        int n = nums.size();
        vector<int> dp(n,1), hash(n);
        int maxi = 1;
        int lastIndex = 0;
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n; ++i){
            hash[i] = i;
            for(int prev=0; prev<i; ++prev){
                if(nums[i]%nums[prev]==0 && 1+dp[prev] > dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                lastIndex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);

        while(hash[lastIndex]!=lastIndex){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        return temp;
    }
};
