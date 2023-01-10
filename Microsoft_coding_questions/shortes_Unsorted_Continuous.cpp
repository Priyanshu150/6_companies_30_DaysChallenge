LINKS:- https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

INTUTION:-
  
  Create a duplicate array.
  sort one of the array.
  Take two pointer st and end at the end of the arrray
  Treaverse the both array from forward and backwards one time each time each.
  Check for the element which is not matching in the sorted and unsorted array and mark the index of elements.
  The lenght of the unsorted will be (ed-st+1)
  If array is sorted then return 0.
    
TIME COMPLEXITY :- O(N)
SPACE COMPLEXITY :- O(N)
  
CODE :-
  
  class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(); 
        vector<int> v = nums;
        sort(v.begin(),v.end());
        int st(0), ed(n-1);

        while(st<n && v[st]==nums[st])
            st++;
        
        while(ed>=0 && v[ed]==nums[ed])
            ed--;
        
        if(ed<0 || st>v.size()-1){return 0;}
        return ed-st+1;
    }
};
