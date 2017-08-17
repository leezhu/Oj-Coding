/*
 *题目描述
 输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

 *
 */

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        
        ListNode *head1,*head2,*newHead,*p;
        head1=pHead1;
        head2=pHead2;
        newHead=NULL;
        
        while(head1!=NULL && head2!=NULL)
            {
            if(head1->val >= head2->val)
              {
                if(head2==pHead2 &&newHead ==NULL)	//首节点
                {
                    newHead = head2;
                    head2=head2->next;
                    p=newHead;
                }else
                    {
                    p->next = head2;
                    p =head2;
                    head2=head2->next;
                }
                
            }
            else{
                if(head1==pHead1 &&newHead ==NULL)	//首节点,新首节点不为空，说明可以指向
                {
                    newHead = head1;
                    head1=head1->next;
                    p=newHead;
                }else
                    {
                    p->next = head1;
                    p =head1;
                    head1=head1->next;
                }
            }
            
        }
        
        if(head1!=NULL)
            p->next=head1;
        if(head2!=NULL)
            p->next=head2;
        return newHead;
    }
};
