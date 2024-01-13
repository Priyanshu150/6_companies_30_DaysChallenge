Links :- https://leetcode.com/problems/top-k-frequent-words/description/

Intution :- 
  Count the frequency of each words using map.
  Insert each word with frequency in vector and sort that vector.
  Extract the answer from vector.
  
Time complexity :- O(n*log(n))
Space complexity :- O(n)
  
Code :- 
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        
        for(int i=0; i<words.size(); i++)
            m[words[i]]++;
        
       vector<pair<int,string>> v;
        
        for(auto it: m)
            v.push_back({-it.second, it.first});
        
        sort(v.begin(), v.end());
        vector<string> ans;
        
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};
