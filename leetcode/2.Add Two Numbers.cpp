/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //方法二：逐个处理，
        ListNode* p1,*p2,*pr,*head;
        head = NULL;
        p1= l1;
        p2=l2;
        int sumTmp;//临时的一位相加
        int frontSum=0;//记录前一位相加的1
        while(p1!=NULL && p2!=NULL){
            sumTmp = p1->val + p2->val;
            ListNode* node = new ListNode((sumTmp + frontSum)%10);
            frontSum = (sumTmp + frontSum) / 10;
            if(head == NULL){
                head = node;
                pr = head;
            }else{
                pr->next = node;
                pr = node;
            }
            p1= p1->next;
            p2=p2->next;
        }
        
        //不为空直接添加，考虑最后的进位问题
        while(p1!=NULL){
            sumTmp = p1->val;
            ListNode* node = new ListNode((sumTmp + frontSum)%10);
            frontSum = (sumTmp + frontSum) / 10;
            pr->next = node;
            pr = node;
            p1= p1->next;
        }
        
        while(p2!=NULL){
            sumTmp = p2->val;
            ListNode* node = new ListNode((sumTmp + frontSum)%10);
            frontSum = (sumTmp + frontSum) / 10;
            pr->next = node;
            pr = node;
            p2= p2->next;
        }
        
        //考虑都为空，但是进位不为空，需要添加一个
        if(frontSum!=0){
            ListNode* node = new ListNode(frontSum);
            pr->next = node;
        }
        return head;
        
    }
};
