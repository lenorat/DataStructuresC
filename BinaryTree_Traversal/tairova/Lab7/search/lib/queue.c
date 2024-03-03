#include "queue.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked_list.h"
Queue* queue_initialize(int dataTypeSize, char* dataType){
	LinkedList* list = llist_initialize(dataTypeSize, dataType);
	if(dataTypeSize == 0 || dataType == NULL || list == NULL){
		return NULL;	
	}
	Queue* queue = malloc(sizeof(*queue));
	if(queue==NULL){
		llist_destroy(list);
		return NULL;
	}
	queue->linklist = list;
	return queue;
}
bool queue_enqueue(Queue* q, void* element){
	if(q == NULL || element == NULL){
		return false;
	}
	//create enough memory for element first or call method 
	llist_add_last(q->linklist, element);
	return true;
}

void* queue_dequeue(Queue* q){
	if(q == NULL){
		return NULL;
	}
	void* removed = llist_remove_first(q->linklist);
	return removed;
}
void* queue_peek(Queue* q){
	if(q==NULL){
		return NULL;
	}
	void* front = llist_get(q->linklist, 0);
	return front;
}

int queue_size(Queue* q){
	if(q==NULL){
		return -1;
	}
	return q->linklist->size;
}
bool queue_contains(Queue* q, void* element){
	if(q == NULL || element == NULL){
		return false;
	}
	//this fn returns -1 if element is not in the llist
	if(llist_index_of(q->linklist, element) != -1){
		return true;
	}
	else{
		return false;
	}
}

bool queue_destroy(Queue* q){
	if(q==NULL){
		return false;
	}
	llist_destroy(q->linklist);
	q->size = 0;
	free(q->datatype);
	free(q);
	return true;
}
