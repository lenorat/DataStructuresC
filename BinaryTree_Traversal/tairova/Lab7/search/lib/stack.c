#include "stack.h"
#include <stdlib.h>

Stack* stack_initialize(int datatypesize, char* dataType){
	LinkedList* list = llist_initialize(datatypesize, dataType);
	if(list == NULL){ return NULL;}
	Stack* stack = malloc(sizeof(*stack));
	if(stack== NULL){ return NULL;}
	stack->linklist=list;
	return stack;
}

bool stack_push(Stack* s, void* element){
	if(s==NULL || element == NULL){
		return false;
	}
	llist_add_first(s->linklist, element);
	return true;
}

void* stack_pop(Stack* s){
	if(s==NULL){
		return NULL;
	}
	void* removed = llist_remove_first(s->linklist);
	return removed;
}
void* stack_peek(Stack* s){
	//0 is first or is s->size
	if(s==NULL){
		return NULL;
	}
	void* top = llist_get(s->linklist, 0);
	return top;
}
int stack_size(Stack* s){
	if(s==NULL){
		return -1;
	}
	return s->linklist->size;
}

bool stack_contains(Stack* s, void* element){
	if(s == NULL || element == NULL){
		return false;
	}
	if(llist_index_of(s->linklist, element)!=-1){
		return true;
	}
	else{
		return false;
	}
	
}

bool stack_destroy(Stack* s){
	if(s==NULL){
		return false;
	}
	llist_destroy(s->linklist);
	free(s);
	return true;
}

