
class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int l, r, ans;
        l = r = ans = 0;
        long long product = a[0];
        
        while(r < n){
            if(product < k){
                ans += (r - l + 1);
                ++r;
                if(r < n)
                    product *= a[r];
            }
            else{
                product /= a[l];
                
                if(l == r){
                    ++r;
                    if(r < n)
                        product *= a[r];
                }
                
                ++l;
            }
        }
        
        return ans;
    }
};
