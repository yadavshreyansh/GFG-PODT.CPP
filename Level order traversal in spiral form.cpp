
vector<int> findSpiral(Node *root)
{
    deque<pair<int,Node*>> q;
    q.push_back({0, root});
    
    vector<int> ans;
    
    int curlevel = 0;
    
    while(!q.empty()){
        int level;
        Node * node;
        
        if(curlevel & 1){
            if(q.front().first != curlevel)
                ++curlevel;
        }
        else{
            if(q.back().first != curlevel)
                ++curlevel;
        }
        
        if(curlevel & 1){
            tie(level, node) = q.front();
            q.pop_front();
        }
        else{
            tie(level, node) = q.back();
            q.pop_back();
        }
        
        ans.push_back(node -> data);
        
        if(level & 1){
            if(node -> left != nullptr)
                q.push_back({level + 1, node -> left});
            if(node -> right != nullptr)
                q.push_back({level + 1, node -> right});
        }
        else{
            if(node -> right != nullptr)
                q.push_front({level + 1, node -> right});
            if(node -> left != nullptr)
                q.push_front({level + 1, node -> left});
        }
    }
    
    return ans;
}
