#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

Dictionary* dict_initialize(int(*compare)(void*, void*), void(*print)(void*)){
	Dictionary* dict = malloc(sizeof(Dictionary));
	if(dict == NULL){
		return NULL;
	}
	dict->tree = bintree_initialize(sizeof(Pair), "Pair", compare, print);
	if(dict->tree = NULL){
		//free it?
		return NULL;
	}
	return dict;
}

bool dict_insert(Dictionary* dict, void* key, void* value){
	if(dict == NULL || key == NULL || value == NULL){
		return false;
	}
	if(dict->tree == NULL){
		return false;
	}
	Pair* pair = malloc(sizeof(Pair));
	//malloc these?
	pair->first = key;
	pair->second = value;
	//bintreeinsert fun (dict->tree, Pair)
	return bintree_insert_replace(dict->tree, pair);
}

void* dict_get(Dictionary* dict, void* key){
	if(dict==NULL || key==NULL || dict->tree == NULL){
		return NULL;
	}
	Pair* pair = malloc(sizeof(Pair));
	pair->first = key;
	pair->second = NULL;

	BinaryTreeNode* topNode = dict->tree->top;
	//we will use the compare function to find get the wanted node
	//if it is equal to 0 - correct node
	//negative value means we go left
	//otherwise we go right (pos value)
	while(topNode != NULL){
		int compResult = dict->tree->compare(topNode->data, pair);
		if(compResult==0){
			//cast topNode to Pair
			//to retrieve the value associated with the key
			return ((Pair*)topNode->data)->second;
		}
		if(compResult<0){
			//check Left subtree
			topNode = topNode->left;
		}
		else{
			//check Right subtree
			topNode = topNode->right;
		}
	}
	//not found
	return NULL;
}

ArrayList* dict_key_list(Dictionary* dict,int keyAllocSize){
	if(dict == NULL || keyAllocSize == 0){
		return NULL;
	}
	//make an array to hold elements
	//it will hold x number of elements (can grow as needed)
	ArrayList* alist = alist_initialize(25, keyAllocSize, "element");
	//struggling
	//call helper function
	_dict_key_list_helper(dict->tree->top, alist);
	return alist;
}

bool dict_contains(Dictionary* dict, void* key){
	//same as dict_get?
	if(dict == NULL || key == NULL){
		return false;
	}
	Pair* pair = malloc(sizeof(Pair));
	pair->first = key;
	pair->second = NULL;

	return bintree_search(dict->tree, pair);
}

ArrayList* _dict_key_list_helper(BinaryTreeNode* tempNode, ArrayList* keys){
	//we can use inorder traversal to get
	//keys in the correct order
	//copying from bintree.c
	if(tempNode->left != NULL){
		_dict_key_list_helper(tempNode->left, keys);
	}
	//instead of printing them we actually add them to list
	alist_add(keys, ((Pair*)tempNode->data)->first);
	if(tempNode->right != NULL){
		_dict_key_list_helper(tempNode->right, keys);
	}
}

