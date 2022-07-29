#pragma once
#include <unordered_set>

namespace node {
	struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode * right;
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	};
	
	class SearcheTreeNode {
		public:
			TreeNode* searchBST(TreeNode* root, int val);
			TreeNode* searchBSTIteration(TreeNode* root, int val);
	};

 	struct ListNode {
      	int val;
      	ListNode *next;
      	ListNode(int x) : val(x), next(nullptr) {}
  	};

	struct SinglyListNodeNew
	{
		int val;
		SinglyListNodeNew * next;
		SinglyListNodeNew(int x) : val(x), next(nullptr) {}
		// SinglyListNodeNew* getNode(int index);
	};


	class MyLinkedListNew {
		private:
			SinglyListNodeNew* head;
		public:
			MyLinkedListNew() {
				head = nullptr;
			}
	};


	class SolutionhasCycle {
	public:
		bool hasCycle(ListNode *head);
		bool hasCycleTwoPoint(ListNode *head);
		// {
		// 	bool flag = false;
		// 	int size = 0;
		// 	std::unordered_set<ListNode*> nodes;
		// 	while (true) {
		// 		nodes.insert(head);

		// 		if (size == nodes.size() && flag == false)
		// 			break;
		// 		size += 1;
		// 		head=head->next;
		// 		if (head != nullptr)
		// 		{
		// 			if (nodes.contains(head))
		// 			{
		// 				flag = true;
		// 				break;
		// 			}
		// 		}
		// 		else
		// 			break;
		// 	}

		// 	return flag;
		// }
};
}

namespace components {
	struct SinglyListNode
	{
		int val;
		SinglyListNode *next;
		SinglyListNode(int x) : val(x), next(nullptr) {}
		// SinglyListNode* getNode(int index);
	};

	// struct SinglyListNodeNew
	// {
	// 	int val;
	// 	SinglyListNodeNew * next;
	// 	SinglyListNodeNew(int x) : val(x), next(nullptr) {}
	// 	SinglyListNodeNew* getNode(int index);
	// };
	

	class MyLinkedList {
		public:
			int size = 0;
			SinglyListNode* head = new SinglyListNode(0);
			MyLinkedList();
			// MyLinkedList(int value);
			int get(int index);

			void addAtHead(int val);

			void addAtTail(int val);

			void addAtIndex(int index, int val);

			void deleteAtIndex(int index);
		private:
			int val;
			MyLinkedList* next;
	};

	// class MyLinkedListNew {
	// 	private:
	// 		SinglyListNodeNew* head;
	// 	public:
	// 		MyLinkedListNew() {
	// 			head = nullptr;
	// 		}
	// };
}