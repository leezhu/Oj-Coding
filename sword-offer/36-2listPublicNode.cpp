/*
 *题目描述
 输入两个链表，找出它们的第一个公共结点。
 *
 *解法:只会是Y型
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        stack<ListNode*> p1,p2;
        ListNode* head1=pHead1;
        ListNode* head2=pHead2;
        ListNode* node=NULL;
        
        while(head1!=NULL)
           {
            p1.push(head1);
            head1=head1->next;
        }
        
         while(head2!=NULL)
           {
            p2.push(head2);
            head2=head2->next;
        }
        
        while(!p1.empty() && !p2.empty())
            {
            if(p1.top()==p2.top())
                node = p1.top();
            else
                break;
            p1.pop();
            p2.pop();
                
        }
        
        return node;
    }
};
