class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        stack<char> st;

    
        for(auto it : s){
            //if opening braces push to stack
            if(it == '(') st.push(it);
            else if(it == ')'){ //if closing braces pop from stack
                st.pop();
            }
            //this gives us maximum number of opening brakcets in a row
            int ele = st.size();
            ans = max(ans, ele);
        }
        return ans;
    }
};