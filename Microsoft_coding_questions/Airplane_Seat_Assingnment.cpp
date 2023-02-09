LINKS :- https://leetcode.com/problems/airplane-seat-assignment-probability/description/

INTUTION :- https://assets.leetcode.com/users/images/4aef6a27-3a83-40d4-a05e-430afb2453ca_1672919611.447311.jpeg
  
TIME COMPLEXITY :- O(1)
SPACE COMPLEXITY :- O(1)
  
CODE :-
  
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1)
            return 1.0;
        
        return 0.5;
    }
};
