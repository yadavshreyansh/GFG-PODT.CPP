class Solution {
  public:
    int sumOfNaturals(int n) {
        const int mod = 1e9 + 7;
        long long ans = (n * (n + 1LL)) % mod;
        ans = (ans * 500000004LL) % mod;
        return ans;
    }
};
