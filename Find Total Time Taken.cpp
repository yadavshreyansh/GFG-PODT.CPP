
class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time) {
        vector<bool> taken(n + 1, 0);
        
        int ans = -1;
         
        for(int i = 0; i < n; i++){
            if(!taken[arr[i]])
                ++ans, taken[arr[i]] = 1;
            else
                ans += time[arr[i] - 1];
        }
        
        return ans;
    }
};
