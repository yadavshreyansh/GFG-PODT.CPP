
class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
        unordered_map<int, int> f;
        queue<char> q;
        
        for(auto i : S){
            ++f[i];
            
            if(f[i] == 1)
                q.push(i);
                
            while(q.size() and f[q.front()] > 1)
                q.pop();
        }
        
        return q.size() ? q.front() : '$';
    }

};
