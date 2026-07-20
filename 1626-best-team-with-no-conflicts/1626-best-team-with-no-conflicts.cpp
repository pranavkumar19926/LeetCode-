class Solution {
public:

    int ans(vector<pair<int,int>> &vec, int newin, int oldin,
            vector<vector<int>> &dp) {

        if (newin == vec.size())
            return 0;

        if (dp[newin][oldin + 1] != -1)
            return dp[newin][oldin + 1];

        // Don't take current player
        int notTake = ans(vec, newin + 1, oldin, dp);

        // Take current player
        int take = 0;

        if (oldin == -1 || vec[newin].second >= vec[oldin].second) {
            take = vec[newin].second +
                   ans(vec, newin + 1, newin, dp);
        }

        return dp[newin][oldin + 1] = max(take, notTake);
    }

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        int n = scores.size();

        vector<pair<int,int>> vec;

        for (int i = 0; i < n; i++) {
            vec.push_back({ages[i], scores[i]});
        }

        sort(vec.begin(), vec.end());

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return ans(vec, 0, -1, dp);
    }
};