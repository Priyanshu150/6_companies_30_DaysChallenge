LINKS:- https://leetcode.com/problems/valid-square/

INTUTION:-
  Calculate the side and diagonal of the square with the given point.
  There total will be 6 combination i.e 6 distance will be obtained.
  2 for the diagonal and 4 for the side.
  Store this in map and check for validity.
  If size of map > 2 or any lenght has other than 6 or 4 frequency or diagonal != sqrt(2)*side return false
  otherwise it is a valid square.

CODE:- 
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<double,int> m;
        vector<vector<int>> v = {p1, p2, p3, p4};
        for(double i=0; i<3; ++i){
            for(double j=i+1; j<4; ++j){
                double x = pow((v[j][0] - v[i][0]),2);
                double y = pow((v[j][1] - v[i][1]),2);
                double dis = sqrt(x+y);
                m[dis]++;
            }
        }
        if(m.size()>2)
            return false;
        
        int side, diagonal;
        for(auto it: m){
            if(it.second == 4)
                side = sqrt(2)*it.first;
            else if(it.second == 2)
                diagonal = it.first;
            else
                return false;
        }
       
        if(side != diagonal)
            return false;
        
        return true;
    }
};
