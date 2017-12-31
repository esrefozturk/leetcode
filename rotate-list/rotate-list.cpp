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
    
    int len(ListNode* h){
        if(!h) return 0;
        int l = 1;
        while((h=h->next)) l+=1;
        return l;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int l = len(head);
        k = k%l;
        if(!k) return head;
        ListNode* a = head;
        ListNode* b = head;
        for(int i=0;i<k;i++) b = b->next;
        while(b->next){
            a = a->next;
            b = b->next;
        }
        ListNode* r = a->next;
        a->next = NULL;
        b->next = head;
        return r;
    }
};
