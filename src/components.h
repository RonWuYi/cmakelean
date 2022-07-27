#pragma once

namespace components {
	struct SinglyListNode
	{
		int val;
		SinglyListNode *next;
		SinglyListNode(int x) : val(x), next(nullptr) {}
		// SinglyListNode* getNode(int index);
	};

	struct SinglyListNodeNew
	{
		int val;
		SinglyListNodeNew * next;
		SinglyListNodeNew(int x) : val(x), next(nullptr) {}
		SinglyListNodeNew* getNode(int index);
	};
	

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

	class MyLinkedListNew {
		private:
			SinglyListNodeNew* head;
		public:
			MyLinkedListNew() {
				head = nullptr;
			}
	};
}