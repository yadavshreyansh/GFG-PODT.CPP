class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        vector<int> dx(n, 0);
        
        for(int i = 0; i < k; i++)
            dx[updates[i] - 1]++;
            
        int toadd = 0;
        
        for(int i = 0; i < n; i++){
            toadd += dx[i];
            a[i] += toadd;
        }
    }
};
