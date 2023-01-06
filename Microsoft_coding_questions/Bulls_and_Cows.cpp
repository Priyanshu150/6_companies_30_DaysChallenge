Links:- https://leetcode.com/problems/bulls-and-cows/description/

Intution:- 
Maintain the map for secret in order to search the char present.  
Reducing the frequency every time we find a code and simultaneouly maintaining the count.
  
Time complexity:- O(N+M)
Space complexity:- O(N)
  
where, "N" is the len of secret code and "M" is lenght of guess.
  
Code:-
  
class Solution {
public:
    string getHint(string secret, string guess) {
        int a(0), b(0);
        map<char,int> m;

        for(int i=0; i<secret.size(); i++)
            m[secret[i]]++;
        
        for(int j=0; j<guess.size(); ++j){
            if(guess[j]==secret[j]){
                a++;
                m[guess[j]]--;
                if(m[guess[j]]<0)
                    b--;
            }
            else if(m[guess[j]]>0){
                b++;
                m[guess[j]]--;
            }
        }
        return to_string(a) + "A" + to_string(b) + "B";
    }
};
