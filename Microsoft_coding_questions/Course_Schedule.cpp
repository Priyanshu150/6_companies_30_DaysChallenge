LINK:- https://leetcode.com/problems/course-schedule/description/

INTUTION :-
  
  Form a graph using the array.
  If the cycle detected then return false else true
  
  Topological sorting and Detecting a cycle concept can be used here 
  

TIME COMPLEXITY:- O(N+E)
  
SPACE COMPLEXITY:- O(N)
  
CODE:- 
  
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto v:prerequisites)
            adj[v[0]].push_back(v[1]);
        
        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; ++i)
            for(auto it: adj[i])
                indegree[it]++;
            
        queue<int> q;
        for(int i=0; i<numCourses; ++i)
            if(!indegree[i])
                q.push(i);

        int n = 0;    
        while(!q.empty()){
            int nd = q.front();
            q.pop();
            n++;
            for(auto it: adj[nd]){
                indegree[it]--;
                if(!indegree[it])
                    q.push(it);
            }
        }
        if(n==numCourses)
            return true;
        
        return false;
    }
};
