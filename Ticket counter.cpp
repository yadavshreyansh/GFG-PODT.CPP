class Solution {
  public:
    int distributeTicket(int N, int K) {
        int cut = N / (2 * K);
        int left = 1 + (cut * K);
        int right = N - (cut * K);
        
        if(right < left){
            return left;
        }
        
        if(right - left + 1 <= K){
            return right;
        }
        else{
            left += K;
            return left;
        }
    }
};
