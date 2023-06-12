class Solution{
  public:
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                int x, y;
                x = y = 0;
                
                if(j - i > -1)
                    x = price[i - 1] + dp[i][j - i];
                    
                y = dp[i - 1][j];
                
                dp[i][j] = max(x, y);
            }
        }
        
        return dp[n][n];
    }
};
