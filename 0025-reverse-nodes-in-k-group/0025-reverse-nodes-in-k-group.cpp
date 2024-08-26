/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* findkthNode(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newHead = NULL;
        while(head!=NULL){
            ListNode* forward = head->next;
            head->next = newHead;
            newHead = head;
            head = forward;
        }
        return newHead;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while(temp!=NULL){
            ListNode* kthNode = findkthNode(temp, k);
            if(kthNode==NULL){
                prevLast->next = temp;
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if(temp==head){
                head = kthNode;
            }else{
                prevLast->next = kthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};