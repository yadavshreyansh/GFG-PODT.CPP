
class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       queue<pair<int,Node *>> q;
       q.push({0, root});
       
       vector<int> ans;
       
       while(!q.empty()){
            int level;
            Node * node;
            tie(level, node) = q.front();
           
            q.pop();
           
            if(ans.size() == level)
                ans.push_back(node -> data);
            else
                ans[level] = node -> data;
                
            if(node -> left != nullptr)
                q.push({level + 1, node -> left});
            if(node -> right != nullptr)
                q.push({level + 1, node -> right});
       }
       
       return ans;
    }
};
