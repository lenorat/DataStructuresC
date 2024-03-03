#ifndef __LINKEDLIST_HEADER
#define __LINKEDLIST_HEADER
#include <stdbool.h>

typedef struct _Node
{
	// The data stored in this node.
	void* data;
	
	// The node after this one.
	struct _Node* next;
	
	// The node before this one.
	struct _Node* prev;
} Node;

typedef struct _LList
{
	// The first node in the list.
	Node* first;
	
	// The last node in the list.
	Node* last;
	
	// The current size of the list.
	int size;
	
	// The size of each element in the list in bytes.
	int itemSize;
	
	// The name of the data type stored in this list.
	char* type;	
} LinkedList;

// Return a pointer to an array list that holds a data type of size (int)
// in bytes and is named based on the provided string.
LinkedList* llist_initialize(int, char*);

// Add an element before the element at the given index.
bool        llist_add_at(LinkedList*, int, void*);

// Add an element to the front of the list.
bool        llist_add_first(LinkedList*, void*);

// Add an element to the end of the list.
bool        llist_add_last(LinkedList*, void*);

// Get a copy of the element at the given index.
void*       llist_get(LinkedList*, int);

// Get the index of the given element if it's present in the list.
int         llist_index_of(LinkedList*, void*);

// Remove the element at the given index and return it.
void*       llist_remove(LinkedList*, int);

// Remove the first element in the list and return it.
void*       llist_remove_first(LinkedList*);

// Remove the last element in the list and return it.
void*       llist_remove_last(LinkedList*);

// Destroy every node and piece of data in the linked list, then free the list.
bool        llist_destroy(LinkedList*);

#endif
