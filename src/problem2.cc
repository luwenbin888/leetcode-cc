/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

#include <iostream>
#include <vector>

using namespace std;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *tail = NULL;
        int carry = 0;
        while (l1 || l2) {
        	int nodeVal = (l1?l1->val:0) + (l2?l2->val:0) + carry;
        	carry = 0;
        	if (nodeVal >= 10) {
        		nodeVal = nodeVal - 10;
        	    carry = 1;
        	}
        	ListNode *node = new ListNode(nodeVal);
        	if (!head) {
        		head = node;
        		tail = node;
        	}
        	else {
        		tail->next = node;
        		tail = node;
        	}

        	if (l1) l1 = l1->next;
        	if (l2) l2 = l2->next;
        }

        if (carry > 0) {
        	tail->next = new ListNode(carry);
        }

        return head;
    }
};

int main()
{
	std::vector<int> nums1;
	nums1.push_back(2);
	nums1.push_back(4);
	nums1.push_back(3);
	ListNode *l1 = getList(nums1);

	std::vector<int> nums2;
	nums2.push_back(5);
	nums2.push_back(6);
	nums2.push_back(4);
	ListNode *l2 = getList(nums2);

	std::cout<<"List1: "<<std::endl;
	printList(l1);
	std::cout<<"List2: "<<std::endl;
	printList(l2);

	Solution solution;
	ListNode* result = solution.addTwoNumbers(l1, l2);
	std::cout<<"Result :"<<std::endl;
	printList(result);
}