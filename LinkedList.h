#pragma once
#include <string>

struct Node
{
	std::string name;

	Node* next;

	Node* previous;
};




class LinkedList 
{

public:
	LinkedList();
	~LinkedList();

	void AddToList(Node* newNode);
	void RemoveFromList(int index);
	int ListSize();
	Node* ReturnBegin();
	Node* FindSpecificNode(int index);

private:
	int mListSize;
	Node* mBegin;
	Node* mCurrent;
	Node* mEnd;

};