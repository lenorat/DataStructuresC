#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

#include <string.h>

ArrayList* alist_initialize(int maxSize, int itemSize, char* type){
	//allocate enough memory for it
	ArrayList* list = malloc(sizeof(*list));
	if(list == NULL){
		return NULL;
	}
	//size of array
	list->arr = malloc(sizeof(*(list->arr))*maxSize);
	//type size and type
	list->type = malloc(strlen(type)+1);
	strcpy(list->type, type);
	list->itemSize = itemSize;
	//curr size
	list->size = 0;
	list->maxSize = maxSize;
	return list;
}

bool alist_add(ArrayList* alist, void* element){
	if(alist == NULL){
		return false;
	}
	//attemp to add element to END
	alist_add_at(alist, alist->size, element);
}
bool alist_add_at(ArrayList* alist, int index, void* element){
	if(alist==NULL || element == NULL || index < 0 || index > alist->size){
		return false;
	}
	//first we check if we even have room to add a new element
	if(alist->size == alist->maxSize){
		bool didItWork=_alist_resize(alist);
		if(!didItWork){
			return false;
		}
	}
	//shifting current elements to make room for added element
	for(int i = alist->size; i > index; i--){
		alist->arr[i] = alist->arr[i-1];
	}
	//increase size by 1
	alist->size++;
	//allocate emory to added element
	alist->arr[index] = malloc(alist->itemSize);
	//we only add values using MEMCPY
	memcpy(alist->arr[index], element, alist->itemSize);

	return true;

}
void alist_clear(ArrayList* alist){
	for(int i = 0; i < alist->maxSize; i++){
		free(alist->arr[i]);
		alist->arr[i]=NULL;
	}
	alist->size = 0;

}

void* alist_get(ArrayList* alist, int index){
	if(alist == 0){
		return NULL;
	}
	//checking if index is within range
	if( !(index <= alist->size && index >= 0)){
		return NULL;
	}
	void* get = memcpy(malloc(alist->itemSize), alist->arr[index], alist->itemSize);
	return get;
}

int alist_index_of(ArrayList* alist, void* ptr){
	
	if(alist==NULL || ptr == NULL){
		return -1;
	}
	
	for(int i = 0; i<alist->size; i++){
		//memcmp compares two elements within n size
		//if ==0 theyre same
		if(memcmp(alist->arr[i], ptr , alist->itemSize)==0){
			return i;
		}
	}
	return -1;
}

void* alist_remove(ArrayList* alist, int index){
	if(index<0|| alist->size<= index || alist == NULL){
		return NULL;
	}
	//to return later
	void* rem = alist->arr[index];
	//iterate through the arraylist starting at given index, before last element (NULL)
	//move index pos to curr pos at each iteration (to update placement of elements)
	for(int i = index; i < alist->size-1; i++){
		alist->arr[i] = alist -> arr[i+1];
	}
	//now, update the last index we currently have to NULL
	alist->arr[alist->size-1] = NULL;
	//decrement value since we remove ONE element
	alist->size--;
	//returning removed element
	return rem;
}
bool alist_destroy(ArrayList* alist){
	if(alist==NULL){
		return true;
	}
	alist_clear(alist);
	free(alist->type);
	free(alist);
	return true;
}

bool _alist_resize(ArrayList* alist){
	if(alist == NULL){
		return false;
	}
	//reallocate to a new array so that we dont overwrite original
	void* copy = realloc(alist->arr, alist->maxSize * 2 * sizeof(*(alist->arr)));
	if (copy == NULL){
		//couldnt reallocate
		return false;
	}
	//otherwise, we could reallocate
	alist->maxSize *= 2;
	alist->arr = copy;
	return true;
}
