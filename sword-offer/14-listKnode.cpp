/*
 *
 *题目描述
 输入一个链表，输出该链表中倒数第k个结点。
 *
 * 维持两个指针，第一个先移动K,然后第二个跟着第一个一起移动，直到第一个到末尾
 * 注意点:鲁棒性，k<=0，头结点为空，k比链表结点少
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	
        ListNode* firstP,*secondP;
        firstP = pListHead;
        secondP = pListHead;
        
        if(pListHead==NULL || k<=0)
            return NULL;
        
        for(int i=1;i<k;i++)
            {
            if(firstP->next!=NULL)
           		 firstP = firstP->next;
            else
                return NULL;
        }
        
        
        while(firstP->next!=NULL)
            {
            
            firstP=firstP->next;
            	secondP = secondP->next;
            
        }
        return secondP;
    }
};

