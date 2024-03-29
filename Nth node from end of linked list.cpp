class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {
           // Your code here
    
        
        Node* slow=head,*fast=head;
       while(n-- && fast)fast=fast->next;
           
      if(n>=0 && !fast)return -1;
       while(fast){
           slow=slow->next;
           fast=fast->next;
       }
       return slow->data;
    }
};
