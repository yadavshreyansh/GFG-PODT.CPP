
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        int len=0;
        Node* temp=head,*pichli;
        while(temp){
            temp=temp->next;
            len++;
        }
        if(len%2)len++;
        len=len/2;
        len++;
        temp=head;
        int c=1;
        while(c!=len){
            pichli=temp;
            temp=temp->next;
            c++;
        }
        Node* prev=NULL,*curr=temp,*agli;
        while(curr){
            agli=curr->next;
            curr->next=prev;
            prev=curr;
            curr=agli;
        }
        pichli->next=prev;
        Node* first=head,*second=prev;
        while(second){
            int t = first->data;
            first->data=second->data-first->data;
            second->data=t;
            first=first->next;
            second=second->next;
        }
        prev=NULL;
        curr=pichli->next;
        while(curr){
            agli=curr->next;
            curr->next=prev;
            prev=curr;
            curr=agli;
        }
        pichli->next=prev;
        return head;
    }
    
