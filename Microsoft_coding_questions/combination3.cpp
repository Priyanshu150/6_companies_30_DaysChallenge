Links:-  https://leetcode.com/problems/combination-sum-iii/description/

class Solution {
private:
    set<vector<int>> s;

    void f(int prev,vector<int> &temp, int k, int n){
        if(temp.size()>k)
            return;
        
        if(temp.size()==k && n==0){
            s.insert(temp);
            return;
        }
        
        for(int i=prev+1; i<=9; ++i){
            temp.push_back(i);
            f(i,temp,k,n-i);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        f(0,temp, k, n);

        vector<vector<int>> ans;
        for(auto it:s)
            ans.push_back(it);
        return ans;
    }
};
