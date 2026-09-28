class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //using monotonic stack
        int n = temperatures.size();
        stack<int> st;
        vector<int> answer(n);

        for(int i = n-1; i >= 0; i--){
            int curr = temperatures[i];

            //remove all the temperatures lesser then curr
            while(!st.empty() && temperatures[st.top()] <= curr){
                st.pop();
            }
            answer[i] = st.empty() ? 0 : st.top()-i;
            st.push(i);
        }
        return answer;
    }
};