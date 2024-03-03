#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

BinaryTree* bintree_initialize(int typesize, char* typename, int(*compare)(void*, void*), void(*print)(void*)){
	BinaryTree* bintree = malloc(sizeof(*bintree));
	if(bintree==NULL){
		return NULL;
	}
	bintree->itemSize = typesize;
	bintree->type = malloc(strlen(typename)+1);
	strcpy(bintree->type, typename);
	bintree->top = NULL;
	bintree->compare = compare;
	bintree->print = print;

	return bintree; 		
}

BinaryTreeNode* bintree_create_node(int datasize, void* element){
	BinaryTreeNode* node = malloc(sizeof(*node));
	if(node == NULL){
		return NULL;
	}
	node->data = malloc(datasize);
	memcpy(node->data,element, datasize);
	node->left = NULL;
	node->right = NULL;
	return node;
}

bool bintree_insert(BinaryTree* t, void* element){
	if(t==NULL||element==NULL){
		return false;
	}
	if(t->top == NULL){
		BinaryTreeNode* node = bintree_create_node(t->itemSize, element);
		t->top = node;
		if(t->top == NULL){return false;}
		return true;
	}
	else{return _bintree_insert_recursive(t, t->top, element);}

}
bool bintree_search(BinaryTree* t, void* element){
	if(t==NULL || element == NULL){
		return false;
	}
	return _bintree_search_recursive(t, t->top, element);
}
void bintree_print_in_order(BinaryTree* t){
	if(t==NULL || t->top == NULL){
		return;
	}
	return _bintree_in_order_recursive(t, t->top);
}
void bintree_print_pre_order(BinaryTree* t){
	if(t==NULL||t->top==NULL){
		return;
	}
	return _bintree_pre_order_recursive(t, t->top);
}
void bintree_print_post_order(BinaryTree* t){
	if(t==NULL||t->top==NULL){
		return;
	}
	return _bintree_post_order_recursive(t, t->top);
}
void bintree_print_reverse_order(BinaryTree* t){
	if(t==NULL||t->top==NULL){
		return;
	}
	return _bintree_reverse_order_recursive(t, t->top);
}

bool _bintree_insert_recursive(BinaryTree* t, BinaryTreeNode* n, void* element){
	if(t==NULL || n == NULL || element == NULL || t->top == NULL){
		return false;
	}
	if(t->compare(n->data,element)>=0){
		if(n->right == NULL){
			n->right = bintree_create_node(t->itemSize, element);
			return true;
		}
		return _bintree_insert_recursive(t, n->right, element);
	}
	if(t->compare(n->data, element)<0){
		if(n->left==NULL){
			n->left = bintree_create_node(t->itemSize, element);
			return true;
		}
		return _bintree_insert_recursive(t, n->left, element);
	}
}

bool _bintree_search_recursive(BinaryTree* t, BinaryTreeNode* n, void* element){
	if(t==NULL || n == NULL || element==NULL){
		return false;
	}
	//found immediately
	if(t->compare(n->data, element) == 0){
		return true;
	}
	//search right tree
	if(t->compare(n->data, element) > 0){
		return _bintree_search_recursive(t, n->right, element);
	}
	//search left tree
	if(t->compare(n->data, element) < 0){
		return _bintree_search_recursive(t, n->left, element);
	}
	return false;
}
void _bintree_in_order_recursive(BinaryTree* t, BinaryTreeNode* n){
	if(t==NULL || n == NULL){
		return;
	}
	if(n->left!=NULL){
		_bintree_in_order_recursive(t, n->left);
	}
	t->print(n->data);
	if(n->right!=NULL){
		_bintree_in_order_recursive(t, n->right);
	}
}
void _bintree_pre_order_recursive(BinaryTree* t, BinaryTreeNode* n){
	if(t==NULL || n == NULL){
		return;
	}
	t->print(n->data);
	if(n->left!=NULL){
		_bintree_pre_order_recursive(t, n->left);
	}if(n->right!=NULL){
		_bintree_pre_order_recursive(t, n->right);
	}

}
void _bintree_post_order_recursive(BinaryTree* t, BinaryTreeNode* n){
	if(t==NULL || n==NULL){
		return;
	}
	if(n->left!=NULL){
		_bintree_post_order_recursive(t, n->left);
	}
	if(n->right!=NULL){
		_bintree_post_order_recursive(t, n->right);
	}
	t->print(n->data);
}

void _bintree_reverse_order_recursive(BinaryTree* t, BinaryTreeNode* n){
	if(t==NULL || n==NULL){
		return;
	}
	if(n->right !=NULL){
		_bintree_reverse_order_recursive(t, n->right);
	}
	
	t->print(n->data);
	
	if(n->left !=NULL){
		_bintree_reverse_order_recursive(t, n->left);
	}
}

void bintree_print_breadth_first(BinaryTree* t){

	if(t==NULL || t->top == NULL){
		return;
	}
	//make QUEUE
	Queue* q = queue_initialize(sizeof(BinaryTreeNode), "nodes");
	//print first element of tree
	queue_enqueue(q, t->top);
	//to hold temp vars
	BinaryTreeNode* node = NULL;
	while(queue_size(q)!= 0){
		node = queue_dequeue(q);
		t->print(node->data);
		if(node->left!=NULL){
			queue_enqueue(q, node->left);
		}
		if(node->right!=NULL){
			queue_enqueue(q, node->right);
		}
	}
	return;
}

void bintree_print_depth_first(BinaryTree* t){
	if(t==NULL || t->top == NULL){
		return;
	}
	Stack* stack = stack_initialize(sizeof(BinaryTreeNode), "nodes");
	BinaryTreeNode* node = NULL;
	stack_push(stack, t->top);
	while(stack_size(stack)!=0){
		node = stack_pop(stack);
		t->print(node->data);
		//similar to the prev. but we check right subtree first
		//because when we pop off the stack
		//it is in reverse.
		if(node->right!=NULL){
			stack_push(stack, node->right);
		}
		if(node->left!=NULL){
			stack_push(stack, node->left);
		}


	}
	return;
}

bool bintree_insert_replace(BinaryTree* t, void* element){
	if(t==NULL || element == NULL){
		return false;
	}
	//if tree is empty, make one!
	if(t->top == NULL){
		t->top = bintree_create_node(t->itemSize, element);
		//if still null return false
		if(t->top == NULL){
			return false;
		}
		//otherwise if it is not null, we succesfully made a first node
		return true;
	}
	else{
		return _bintree_insert_replace_recursive(t, t->top, element);
	}
}
//todo
bool _bintree_insert_replace_recursive(BinaryTree* t, BinaryTreeNode* node, void* element){
	//here we have to check which node is greater (left or right of tree)
	//to do this we will be using the compare function
	//does one already exist?
	//is it greater or less than?
	//does it go left or right?
	int compResult = t->compare(node->data, element);
	if(compResult == 0){
		//equal: replace data
		memcpy(node->data, element, t->itemSize);
		return true;
	}	
	if(compResult > 0 ){
		//to the right
		if(node->right == NULL){
			node->right = bintree_create_node(t->itemSize, element);
			if(node->right == NULL){
				return false;
			}
			return true;
		}
		else{
			return _bintree_insert_replace_recursive(t, node->right, element);
		}
	}
	else{
		if(node->left){
		node->left = bintree_create_node(t->itemSize, element);
			if(node->left == NULL){
			return false;
		}
		return true;
		}
		else{
			return _bintree_insert_replace_recursive(t, node->left, element);
		}

		
	}
}
