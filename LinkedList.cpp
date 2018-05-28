#include "LinkedList.h"

//Constructor
LinkedList::LinkedList() :
	//Fancy Initializations
	mListSize(0), mBegin(nullptr), mCurrent(nullptr), mEnd(nullptr)
{
	//nullptr -> is a default pointer to an empty location

}

//Deconstructor
LinkedList::~LinkedList() 
{
	Node* tempNode;
	int count = 0;


	while (count < mListSize) // This is fancier than a counter
	{
		tempNode = mBegin->next;

		delete mBegin;

		mBegin = tempNode;

		count++;
	}
}

// Add a node to the list
void LinkedList::AddToList(Node* newNode) 
{
	//If there is no beginning node then it sets the new node as beginning
	if (mBegin == nullptr) 
	{
		mBegin = newNode;
		mCurrent = newNode; // Only one node in list, so it has to be current node
	}
	// Otherwise current node is set to the next node of the current, Ex: 1st node (Beginning) -> 2nd Node (current)
	else
	{
		mCurrent->next = newNode;
		mCurrent = newNode; // Current node is now the new node added
	}
	
	//The end node is now the new node added, since a node was tacked on after current node
	mEnd = newNode;

	//Increase the list size
	mListSize++;
}

//Remove a single node from the list
void LinkedList::RemoveFromList(int index) 
{
	Node* previousNode = nullptr; // The node behind beginning 
	Node* currentNode = mBegin;
	Node* nextNode = mBegin->next;

	if (index < mListSize) 
	{
		int counter = 0;

		while (counter < index) 
		{
			previousNode = mBegin;

			currentNode = nextNode;

			if (nextNode->next != nullptr) 
			{
				nextNode = nextNode->next;
			}
			else
			{
				//Error Message
			}

			counter++;
		}

		//If the current node is beginning...
		if (currentNode == mBegin)
		{
			//Set the next node as beginning since original will be deleted
			mBegin = nextNode;
		}
		//If current node is at the end and the list size is greater than 2...
		else if (currentNode == mEnd && mListSize > 2) 
		{  
			//Then end is equal to previous node, moving the end backward deleting original
			mEnd = previousNode;
		}
		//If current node is the second node in a list size of 2...
		else if (currentNode == mBegin ->next && mListSize == 2) 
		{
			//Then set the current node to the previous node (The first node)
			mCurrent = previousNode;
			//The end also become the first node since the second in is deleted, list is now 1/1
			mEnd = previousNode;
		}
		//If the node being deleted is between two //  N2 - D3 - N4  // Node = N, To delete node = D
		else 
		{
			//This is for reconnecting nodes when there is space in between
			//Then the node in front of previous node is set to the next node of the deleted node
			previousNode->next = nextNode;
		}
		
		//Delete selected node, and decrease list size;

		delete currentNode;
		mListSize--;
	}
		
}

//Search for single node put into index
Node* LinkedList::FindSpecificNode(int index) 
{
	Node* temp = mBegin;

	int counter = 0;
	
	// Check if the index was within range
	if (index <= mListSize)
	{

		// Keep looking through nodes until the specific node is found, break when found
		while (counter != index)
		{
			temp = temp->next;

			counter++;
		}
	}

	return temp; 
}

//Returns List size
int LinkedList::ListSize()
{


	return mListSize;
}


// Returns beginning node
Node* LinkedList::ReturnBegin() 
{

	return mBegin;
}