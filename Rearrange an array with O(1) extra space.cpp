class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
        for(int i = 0; i < n; i++){
            long long need = arr[arr[i]];
            for(int j = 0; j < 17; j++){
                if((need >> j) & 1)
                    arr[i] |= (1LL << (j + 17));
            }
        }
        
        for(int i = 0; i < n; i++)
            arr[i] >>= 17;
    }
};
