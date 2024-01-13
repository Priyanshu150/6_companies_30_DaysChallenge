Links :- https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/?envType=daily-question&envId=2024-01-10

Intution :- 
  Mark the parent of each node using map data structure.
  Use "BFS" traversal starting from the given start node.
  Mark the visted node as true. In order to note revisit it again.
  
Time Complexity :- O(N)
Space Complexity :- O(N)

Code :-

class Solution {
private:
    TreeNode* strt = NULL;
    unordered_map<TreeNode*, TreeNode*> parents;

    void markParent(TreeNode* root, TreeNode* parent, int &start){
        if(!root)   return;
        if(root->val == start)  strt = root;

        parents[root] = parent;
        markParent(root->left, root, start);
        markParent(root->right, root, start);
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        markParent(root, NULL, start);

        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> vis;
        int cnt = 0;

        q.push(strt);
        vis[strt] = true;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left && vis[node->left]==false){
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if(node -> right && vis[node->right]==false){
                    q.push(node->right);
                    vis[node->right] = true;
                }
                if(parents[node] && vis[parents[node]]==false){
                    q.push(parents[node]);
                    vis[parents[node]] = true;
                }
            }
            ++cnt;
        }
        return cnt-1;
    }
};
