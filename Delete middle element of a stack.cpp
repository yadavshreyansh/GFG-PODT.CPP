
class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int toremove = sizeOfStack / 2; 
        
        stack<int> store;
        
        while(toremove--){
            store.push(s.top());
            s.pop();
        }
        
        s.pop();
        
        while(store.size()){
            s.push(store.top());
            store.pop();
        }
    }
};
