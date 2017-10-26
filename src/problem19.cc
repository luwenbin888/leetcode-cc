/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
*/

#include <iostream>
#include <vector>

using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head) {
 	while (head) {
 		std::cout<<head->val<<"-->";
 		head=head->next;
 	}

 	std::cout<<endl;
 }

 ListNode* getList(std::vector<int> nums) {
 	ListNode *head=NULL;
 	ListNode *current=NULL;
 	for (int i = 0; i < nums.size(); i++) {
 		if (!head) {
 			head = new ListNode(nums[i]);
 			current = head;
 		}
 		else {
 			current->next = new ListNode(nums[i]);
 			current = current->next;
 		}
 	}

 	return head;
 }

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = head;
        for (int i = 0; i < n; i++) {
        	p = p->next;
        }

        while (p && p->next) {
        	p = p->next;
        	q = q->next;
        }

        //ListNode *del = q->next;
        if (p == NULL && n == 1) head = NULL;
        else if (p == NULL && n > 1) {
        	head = head->next;
        }
        else {
        	q->next = q->next->next;
		}

        return head;
    }
};

int main()
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	/*
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	*/

	ListNode *head = getList(nums);
	printList(head);

	Solution solution;
	head = solution.removeNthFromEnd(head, 2);
	printList(head);
}