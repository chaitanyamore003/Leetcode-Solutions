class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a = "", b = "";
        for (auto it : s) {
            if (it == '#') {
                if (!a.empty())
                    a.pop_back();

            } else
                a += it;
        }

        for (auto it : t) {
            if (it == '#') {
                if (!b.empty())
                    b.pop_back();

            } else
                b += it;
        }

        return a == b;
    }
};