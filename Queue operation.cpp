class Solution{
    public:
    
    // Function to insert element into the queue
    void insert(queue<int> &q, int k){
        q.push(k);
    }
    
    // Function to find frequency of an element
    // return the frequency of k
    int findFrequency(queue<int> &q, int k){
        // Your code here
        queue<int> p;
        int ans = 0;
        while(q.size()){
            p.push(q.front());
            ans += q.front() == k;
            q.pop();
        }
        
        while(p.size()){
            q.push(p.front());
            p.pop();
        }
        
        return ans;
    }
    
};
