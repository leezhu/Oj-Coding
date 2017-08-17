/*
 *
 *题目描述
 输入一个链表，反转链表后，输出链表的所有元素。
 *
 * 维持三个指针，实现
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
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead==NULL)
            return NULL;
        
        ListNode *head,*fp,*bp;
        head = pHead;
        fp = bp = head->next;
        
        while(fp!=NULL)
            {
            bp=fp->next;
            
            fp->next = head;
            if(head == pHead)
                head->next = NULL;
            head = fp;
            fp = bp;

        }
        return head;
    }
};

