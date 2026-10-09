class Solution {
public:
    string decodeString(string s) {
        stack<int> number;
        stack<string> st;

        string curr = "";
        int n = 0;

        for (auto it : s) {
            if ((it - '0') >= 0 && (it - '0') <= 9) {
                n = n * 10 + (it - '0');
            } else if (it == '[') { // store all previous stuff
                number.push(n);
                st.push(curr);
                n = 0;
                curr = "";
            } else if (it == ']') { // process this stuff
                string prev = st.top();
                st.pop();
                int multiply = number.top();
                number.pop();

                string temp = "";
                for (int i = 0; i < multiply; i++)
                    temp += curr;
                curr = prev + temp;
            } else {
                curr += it; // all the stuff between those brackets
            }
        }

        return curr;
    }
};