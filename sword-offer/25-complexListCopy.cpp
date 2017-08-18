/*
 *
 *题目描述
 输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
 *
 * 解决办法:采用map来处理随机链的映射，这样查找很方便
 */

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        RandomListNode* head=pHead;
        RandomListNode* p;
        map<RandomListNode*,RandomListNode*> nodeMap;
        
        //头节点
        RandomListNode* root=new RandomListNode(head->label);
        root->next = NULL;
        root->random = NULL;
        p=root;
        nodeMap[head]=root;
        
        //先进行单链复制
        while(head->next!=NULL)
            {
            	head = head->next;
            RandomListNode* node=new RandomListNode(head->label);
            p->next=node;
            p=node;
            nodeMap[head]=p;
        }
        p->next=NULL;//尾节点为空
        
        //利用map做随机链复制
        head=pHead;
        p=root;
        while(head->next!=NULL)
            {
            p->random=nodeMap[head->random];
            head = head->next;
            p=p->next;
        }
        
        return root;
    }
};
