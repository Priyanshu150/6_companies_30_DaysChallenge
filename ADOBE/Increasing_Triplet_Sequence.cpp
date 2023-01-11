LINK :- https://leetcode.com/problems/increasing-triplet-subsequence/

INTUTION :-
  
  Maintain two variable c1 and c2;
  With c1 have least value, c2 has least value but greater than c1 of the array.
  If again we get a smaller value the return true;
  else false
  
TIME COMPLEXITY :- O(N)
SPACE COMPLEXITY :- O(1)

CODE :- 

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int c1 = INT_MAX, c2 = INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            if(c1 >= nums[i])
                c1 = nums[i];
            else if(c2 >= nums[i])
                c2 = nums[i];
            else 
                return true;
        }
        return false;
    }
};
