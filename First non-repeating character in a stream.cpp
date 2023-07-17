
class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char> q;
		    vector<int> f(26, 0);
		    string ans = "";
		    
		    for(auto i : A){
		        ++f[i - 'a'];
		        
		        if(f[i - 'a'] == 1)
		            q.push(i);
		            
		        while(q.size() and f[q.front() - 'a'] > 1)
		            q.pop();
		            
		        if(q.size())
		            ans += q.front();
		        else
		            ans += '#';
		    }
		    
		    return ans;
		}

};
