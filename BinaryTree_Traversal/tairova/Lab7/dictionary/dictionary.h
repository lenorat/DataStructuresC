#ifndef __MAPS_HEADER
#define __MAPS_HEADER
#include <stdbool.h>
#include "lib/array_list.h"
#include "lib/bintree.h"
typedef struct _Pair{
	void* first;
	void* second;
}Pair;

typedef struct _Dictionary{
	BinaryTree* tree;
}Dictionary;
//comparison fn, print fn
Dictionary* dict_initialize(int(*)(void*,void*),void(*)(void*));
bool dict_insert(Dictionary*, void*, void*);
void* dict_get(Dictionary*, void*);
ArrayList* dict_key_list(Dictionary*, int);
bool dict_contains(Dictionary*,void*);
ArrayList* _dict_key_list_helper(BinaryTreeNode*, ArrayList*);

#endif
