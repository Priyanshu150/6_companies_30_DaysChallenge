LINKS :- https://leetcode.com/problems/max-points-on-a-line/

INTUTION :- 
  
  Point on the straight line and parallel lines have same slope.
  Find the slope of the point and maintain a frequency of points in map that have same slope.
  To avoid the same slope of a parallel and straight line 
    - we can fixed a point and around that point we can find the slope with rest of point.
  
TIME COMPLEXITY :-  O(N^2) 
SPACE COMPLEXITY :- O(N) // FOR MAP
  
CODE :- 
   
 class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;
        int n = points.size();

        for(int i=0; i<n-1; ++i){
            unordered_map<double,int> m;
            for(int j=0; j<n; ++j){
                if(i==j)
                    continue;

                double y = (double)(points[j][1] - points[i][1]);
                double x = (double)(points[j][0] - points[i][0]);
                if(x==0)
                    m[10001]++;
                else{
                    double slope = y/x;
                    m[slope]++;
                }
            }
            for(auto it: m)
                ans = max(ans,it.second+1);
        }

        return ans;
    }
};
