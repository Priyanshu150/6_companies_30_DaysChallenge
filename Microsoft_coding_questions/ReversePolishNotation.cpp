Question :- You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Link :- https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

Code:-

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int res = 0;
        stack<int> st;

        for(int i=0; i<tokens.size(); ++i){
            if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/")
            {
                long long int op1 = st.top();
                st.pop();
                long long int op2 = st.top();
                st.pop();
                long long int ans;
                if(tokens[i]=="+")
                    ans = op2+op1;
                else if(tokens[i]=="-")
                    ans = op2-op1;
                else if(tokens[i]=="*")
                    ans = (op2*op1);
                else
                    ans = op2/op1;
                
                st.push(ans);
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};
