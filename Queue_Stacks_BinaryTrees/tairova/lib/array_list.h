#ifndef __ARRAYLIST_HEADER
#define __ARRAYLIST_HEADER

#include <stdbool.h>

// Array List struct for containing the array list fields.
typedef struct _AList
{
	// The underlying array is an array of void pointers.
	void** arr;
	
	// The current number of elements in the list.
	int size;
	
	// The maximum capacity of the array before it needs to resize.
	int maxSize;
	
	// The size of each element stored in the array list.
	int itemSize;	
	
	// The name of the data type stored in this array list.
	char* type;	
} ArrayList;

// Creates an array list. Given a starting capacity (>0), the size
// of the data type being stored, and the name of the data type being stored.
ArrayList* alist_initialize(int, int, char*);

// Add an element to the end of the array list. The element should before
// passed in as a void pointer.
bool       alist_add(ArrayList*, void*);

// And an element before a specified index in the list. The index is given,
// as well as the element as a void pointer.
bool       alist_add_at(ArrayList*, int, void*);

// Clear the array list. Removes all elements and sets the current size to 0.
void       alist_clear(ArrayList*);

// Get a copy of the element stored at the given index.
void*      alist_get(ArrayList*, int);

// Get the index of a given element.
int        alist_index_of(ArrayList*, void*);

// Remove an item from the list at the specified index and return it.
void*      alist_remove(ArrayList*, int);

// Completely destroy an array list, freeing all associated memory.
bool       alist_destroy(ArrayList*);

// Swap the positions of the elements at the two given indexes in the list.
bool       alist_swap(ArrayList*, int, int);

// For internal use only.
bool 	   _alist_resize(ArrayList*);

#endif
