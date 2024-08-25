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
    ListNode* findmiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next; // to find the first mid ** important
        while(fast!=NULL && fast->next !=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(left!=NULL && right!=NULL){
            if(left->val>=right->val){
                temp->next = right;
                right = right->next;
            }else{
                temp->next = left;
                left = left->next;
            }
            temp=temp->next;
        }
        if(left!=NULL){
            temp->next = left;
        }
        if(right!=NULL){
            temp->next = right;
        }
        return dummy->next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        // if(head==NULL || head->next==NULL){
        //     return head;
        // }
        // vector<int> arr;
        // ListNode* temp = head;
        // while(temp!=NULL){
        //     arr.push_back(temp->val);
        //     temp=temp->next;
        // }
        // sort(arr.begin(),arr.end());
        // temp=head;
        // int i=0;
        // while(temp!=NULL){
        //     temp->val=arr[i];
        //     i++;
        //     temp=temp->next;
        // }
        // return head;
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* middle = findmiddle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* left = head;
        left = sortList(left);
        right = sortList(right);
        return merge(left,right);
    }
};