#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node *prev;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
		        this->prev = NULL;
	        }
        };

*****************************************************************/

Node *sortDLL(Node *head){
	if(head==NULL)return head;
	if(head->next==NULL)return head;
	Node*last=head;
	int maxi=head->data;
        while (last->next) {
          if (last->data > maxi)
            maxi = last->data;
          last = last->next;
        }
       if(last->data>maxi)maxi=last->data;
       while(last->data!=maxi)
		{
			Node*curr;
			for(curr=head;last->data>curr->data;curr=curr->next);
			if(curr==head){
				last->prev->next=NULL;
				last->next=head;
				head->prev=last;
				head=last;
				last=last->prev;
				head->prev=NULL;
			}
			else{
				Node*last_prev=last->prev;
				last_prev->next=NULL;
				last->next=curr;
				last->prev=curr->prev;
				last->prev->next=last;
				curr->prev=last;
				last=last_prev;
			}
		}
	return head;
}
