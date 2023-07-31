
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;

        queue<int> q;
        q.push(0);
        
        vector<int> vis(V, 0);
        vis[0] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            for(auto child : adj[node]){
                if(!vis[child]){
                    vis[child] = 1;
                    q.push(child);
                }
            }
        }
        
        return ans;
    }
};
