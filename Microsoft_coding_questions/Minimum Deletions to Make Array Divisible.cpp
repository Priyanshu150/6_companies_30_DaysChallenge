LINKS :- https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/

INTUTION :- 
 
  > Used a map for freq and sorting the nums 
  > Applying the concept using normal approach specified in explanation.

TIME COMPLEXITY :-  O(N*M) + O(N*LOG_N) [traversing the map*traversing the array + updating the freq of nums in map]
SPACE COMPLEXITY :-   O(N)

CODE :- 

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int> m;

        for(auto it: nums)
            m[it]++;
        
        int ans = 0;

        for(auto it: m){
            bool flag = true;
            int num = it.first;

            for(auto itr: numsDivide){
                if(itr%num!=0){
                    flag = false;
                    ans += it.second;
                    break;
                }
            }

            if(flag)
                return ans;
        }
        return -1;
    }
};
