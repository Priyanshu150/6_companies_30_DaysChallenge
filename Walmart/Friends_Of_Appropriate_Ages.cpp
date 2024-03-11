Link :- https://leetcode.com/problems/friends-of-appropriate-ages/description/

Intution :- 
  1. Use brute force for the same problem. (It will give TLE)
  2. Use hashing to store all the unique edges as there are only [1, 120] ages.
  3. To check the condition for friend request add the same from question.
  4. Use two loops to traverse into the map (120 * 120). Ex a & b are the two ages for the loops.
  5. If(a != b)  res += (cnt[a]*cnt[b]);
      If(a == b) res += (cnt[a]*(cnt[a]-1))

Space Complexity :- O(N^2) , where n is the number of unique ages.
Time Complexity :- O(N)
  
Leetcode discussion link :- https://leetcode.com/problems/friends-of-appropriate-ages/solutions/127029/c-java-python-easy-and-straight-forward/
  
Code :- 
class Solution {
private:
    bool isFriendRequestSent(int a, int b){
        return !(b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100));
    }

public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> count;

        for(int &age: ages)
            count[age]++;
        
        int res = 0;
        for(auto &a: count){
            for(auto &b: count){
                if(isFriendRequestSent(a.first, b.first))
                    res += a.second*(b.second - (a.first == b.first ? 1 : 0));
            }
        }
        return res;
    }
};
