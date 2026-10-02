class Solution {
private:
    bool isomorphicPattern(string p, vector<string> s) {
        if (p.size() != s.size())
            return false;
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;

        for (int i = 0; i < p.size(); i++) {
            if (map1.count(p[i]) && map1[p[i]] != s[i])
                return false;
            if (map2.count(s[i]) && map2[s[i]] != p[i])
                return false;

            map1[p[i]] = s[i];
            map2[s[i]] = p[i];
        }
        return true;
    }

public:
    bool wordPattern(string pattern, string s) {
        vector<string> arr;
        string temp;
        stringstream ss(s);

        while (ss >> temp) {
            arr.push_back(temp);
        }

        return isomorphicPattern(pattern, arr);
    }
};