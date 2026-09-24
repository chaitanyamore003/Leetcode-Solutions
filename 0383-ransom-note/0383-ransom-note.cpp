class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //storing the frequencies of all the elements
        vector<int> freq(26, 0);


        int n = ransomNote.size();
        int m = magazine.size();

        //if magazine has less elements then required to create a ransomNote then return false
        if (n > m)
            return false;

        //increase freq for magazine elements
        for (auto it : magazine)
            freq[it - 'a']++;

        //decrease the freq using ransomNote as we are using the elements
        for (auto it : ransomNote)
            freq[it - 'a']--;

        //if elements are negative means elements are not sufficient
        for (auto it : freq)
            if (it < 0)
                return false;

        //we have sufficient elements        
        return true;
    }
};