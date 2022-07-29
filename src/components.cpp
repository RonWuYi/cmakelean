#include "components.h"


components::MyLinkedList::MyLinkedList() {
}

// components::MyLinkedList::MyLinkedList(int value) : val(value), next(nullptr) {
// }

int components::MyLinkedList::get(int index) {
	if (index >= size)
		return -1;
	SinglyListNode* temp = head->next;

	for (int i= 0; i < index; i++)
	{
		temp = temp->next;
	}
	
	return temp->val;
}

void components::MyLinkedList::addAtHead(int val) {
	SinglyListNode* temp = head->next;
	head->next = new SinglyListNode(val);
	head->next->next = temp;
	size++;
}

void components::MyLinkedList::addAtTail(int val) {
	SinglyListNode* temp = head;
	while (temp->next != nullptr)
	{
		temp=temp->next;
	}
	temp->next = new SinglyListNode(val);
	size++;
}

void components::MyLinkedList::addAtIndex(int index, int val) {
	if(index>size) return;   
	SinglyListNode* temp = head;
	for (int i = 0; i < index; i++)
		temp= temp->next;
	// SinglyListNode* temp1 = new SinglyListNode(val);
	SinglyListNode* temp1=temp->next;
	temp->next->next = temp1;
	size++;
}

void components::MyLinkedList::deleteAtIndex(int index) {
	if (index>= size) return;
	SinglyListNode* temp = head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	SinglyListNode* temp1=temp->next;
	temp->next=temp1->next;
	temp1->next = nullptr;
	size--;
	delete temp1;
}

// SinglyListNodeNew* components::SinglyListNodeNew::getNode(int index) {
// 	SinglyListNodeNew* cur = head;
// 	for (int i = 0; i < index && cur; i++)
// 	{
// 		cur = cur->next;
// 	}
// 	return cur;
// }

// node::SinglyListNodeNew* node::SinglyListNodeNew::getNode(int index) {
// 	node::SinglyListNodeNew* cur = head;
// 	for (int i = 0; i < index; ++i)
// 	{
// 		cur=cur->next;
// 	}
// 	return cur;	
// }

bool node::SolutionhasCycle::hasCycle(ListNode *head) {
	bool flag = false;
		int size = 0;
		std::unordered_set<ListNode*> nodes;
		while (true) {
			nodes.insert(head);

			if (size == nodes.size() && flag == false)
				break;
			size += 1;
			head=head->next;
			if (head != nullptr)
			{
				if (nodes.contains(head))
				{
					flag = true;
					break;
				}
			}
			else
				break;
		}

		return flag;
}

bool node::SolutionhasCycle::hasCycleTwoPoint(ListNode *head) {
	if (head == nullptr)
		return false;

	ListNode* fast = head;
	ListNode* slow = head;

	while (fast != nullptr && fast->next != nullptr)
	{
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow)
			return true;
	}
	
	return false;
}

node::TreeNode* node::SearcheTreeNode::searchBST(TreeNode* root, int val) {
	if (root == nullptr || root->val == val)
		return root;
	if (val > root->val)
		return searchBST(root->right, val);
	else
		return searchBST(root->left, val);
    
}

node::TreeNode* node::SearcheTreeNode::searchBSTIteration(TreeNode* root, int val) {
    
}
