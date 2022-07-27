#pragma once

namespace components {
	struct  SinglyListNode
	{
		int val;
		SinglyListNode *next;
		SinglyListNode(int x) : val(x), next(nullptr) {}
	};
}