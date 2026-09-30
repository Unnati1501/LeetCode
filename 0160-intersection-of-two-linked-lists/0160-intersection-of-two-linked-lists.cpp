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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        int count1=0;
        int count2=0;
        while(temp1!=NULL){
            count1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            count2++;
            temp2=temp2->next;
        }
        temp1=headA;
        temp2=headB;
        if(count1>count2){
            int count=count1-count2;
            while(count>0){
                temp1=temp1->next;
                count--;
            }
        }
        else{
            int count=count2-count1;
            while(count>0){
                temp2=temp2->next;
                count--;
            }
        }

        while(temp1!=NULL){
            if(temp1==temp2){
                return temp1;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
};