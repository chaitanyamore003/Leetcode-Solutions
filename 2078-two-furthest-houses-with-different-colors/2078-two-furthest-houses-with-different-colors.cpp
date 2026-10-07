class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int i = n-1;
        int dis = 0;
        while (i >= 0 && colors[i] == colors[0])
            i--;

        dis = max(dis, i);
        
        i = 0;
        while(i < n && colors[i] == colors[n-1]) i++;

        dis = max(dis, n - 1 - i);
    
        return dis;
    }
};