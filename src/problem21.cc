/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode *dummy = new ListNode(0);
    	ListNode *current = dummy;

    	while (l1 || l2) {
    		if (l1 && l2) {
	    		if (l1->val <= l2->val) {
	    			current->next = l1;
	    			l1=l1->next;
	    			current = current->next;
	    		}
	    		else {
	    			current->next = l2;
	    			l2=l2->next;
	    			current = current->next;
	    		}
    		}
    		else if (l1 && !l2) {
    			current->next = l1;
    			break;
    		}
    		else if (!l1 && l2) {
    			current->next = l2;
    			break;
    		}
    	}

    	return dummy->next;
    }
};

int main()
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(6);

	std::vector<int> v2;
	v2.push_back(2);
	v2.push_back(5);
	v2.push_back(6);

	ListNode *l1 = getList(v1);
	ListNode *l2 = getList(v2);

	Solution solution;
	ListNode *head = solution.mergeTwoLists(l1, l2);
	printList(head);
}