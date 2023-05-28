#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minCost(int n, std::vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        std::sort(cuts.begin(), cuts.end());
        
        int m = cuts.size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(m, 0));
        
        return helper(0, m - 1, cuts, dp);
    }
    
private:
    int helper(int start, int end, std::vector<int>& cuts, std::vector<std::vector<int>>& dp) {
        if (end - start <= 1)
            return 0;
        
        if (dp[start][end] != 0)
            return dp[start][end];
        
        int minCost = INT_MAX;
        for (int i = start + 1; i < end; i++) {
            int cost = cuts[end] - cuts[start] + helper(start, i, cuts, dp) + helper(i, end, cuts, dp);
            minCost = std::min(minCost, cost);
        }
        
        dp[start][end] = minCost;
        return minCost;
    }
};
