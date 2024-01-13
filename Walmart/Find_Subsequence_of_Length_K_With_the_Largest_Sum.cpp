Links :- https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/

Time Complexity :- O(n*Log(n))
Space Complexity :- O(n)
  
Code :- 

->priority_queue_code.
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;

        for(int i=0; i<nums.size(); ++i){
            pq.push({nums[i], i});
            if(pq.size() > k)
                pq.pop();
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq1;

        while(!pq.empty()){
            pq1.push({pq.top().second, pq.top().first});
            pq.pop();
        }
        vector<int> ans;
        while(!pq1.empty()){
            ans.push_back(pq1.top().second);
            pq1.pop();
        }
        return ans;
    }
};

->Vector_Sorting_code.
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        vector<pair<int,int>> arr;
        vector<pair<int,int>> temp;

        for(int i=0; i<n; ++i)
            arr.push_back({nums[i], i});
        
        sort(begin(arr), end(arr), greater<pair<int,int>> ());

        for(int i=0; i<k; ++i)
            temp.push_back({arr[i].second, arr[i].first});
        
        sort(begin(temp), end(temp));

        for(int i=0; i<k; ++i)
            ans.push_back(temp[i].second);
        
        return ans;
    }
};
