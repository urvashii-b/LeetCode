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
    ListNode* reverseLL(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* newHead = NULL;
        while(head!=NULL){
            ListNode* fwd = head->next;
            head->next = newHead;
            newHead = head;
            head = fwd;
        }
        return newHead;
    }
public:
    int pairSum(ListNode* head) {
        // vector<int> arr;
        // ListNode* head2 = head;
        // while(head2!=NULL){
        //     arr.push_back(head2->val);
        //     head2=head2->next;
        // }
        // int sum = 0, maxii = 0, n = arr.size();
        // int i=0, j=n-1;
        // while(i<j){
        //     sum = arr[i]+arr[j];
        //     if(sum>maxii){
        //         maxii = sum;
        //     }
        //     i++;
        //     j--;
        // }
        // return maxii;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevSlow = NULL;
        while(fast!=NULL && fast->next!=NULL){
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prevSlow->next = NULL;
        ListNode* L2 = reverseLL(slow);
        int sum = 0, maxi = 0;
        while(L2!=NULL){
            sum = L2->val + head->val;
            if(sum>maxi){
                maxi=sum;
            }
            head=head->next;
            L2=L2->next;
        }
        return maxi;
    }
};