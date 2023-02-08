LINK :- https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

INTUTION:-
  After going throught the question, the general intution was to go with recursion.
  But, given time complex 10^5. It can not be possible and DP can also not be applied.
  Hence, we can go with "Sliding Window technique".
 
  First we find the window in which all three char are present.
  Then keeping two pointer one at starting and other at the ending of the window.
  Start removing the character from starting of window, if the any of the three char get out of the window then find another window from given point.
  
  For each window caluclate the number of sequence possible,
      i.e 1(current window) + remaining char left from the ending point.
        = 1 + (N-J-1) [N is the length of string, J is the pointer for the window at end]
  
SPACE COMPLEXITY :- O(1)
TIME COMPLEXITY :- O(N)
  
CODE :-
  
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);
        int i(0), j(0);
        int n = s.size();

        while((!freq[0] || !freq[1] || !freq[2]) && j<n){
            freq[s[j]- 'a']++;
            j++;
        }
        j--;
        int ans;

        while(i<n && j<n){
            while((!freq[0] || !freq[1] || !freq[2]) && j+1<n){
                j++;
                freq[s[j]- 'a']++;
            }
            
            if(freq[0] && freq[1] && freq[2])
                ans += (n-j);

            freq[s[i]- 'a']--;
            i++;
        }
        return ans;
    }
};
