class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n < 11)
            return {};

        vector<string> ans;

        //using hash map
        unordered_map<string, int> freq;

        for(int i = 0; i <= n-10; i++){
            string str = s.substr(i, 10);
            freq[str]++;
            if(freq[str] == 2) ans.push_back(str);
        }

        return ans;
    }
};