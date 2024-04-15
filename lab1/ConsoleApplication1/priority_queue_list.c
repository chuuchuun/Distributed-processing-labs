#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "priority_queue_list.h"
pqueue* qnode(pqueue* head, int index) {
	pqueue* current = head;
	int count = 0;
	while (current != NULL && count < index) {
		current = current->next;
		count++;
	}
	if (current == NULL) {
		return NULL;
	}
	return current;
}

void
qlist(pqueue* head) {
	pqueue* p;
	printf("The list:\n");
	for (p = head; p != NULL; p = p->next) {
		printf("%s\n", p->data);
	}
}


void qinsert(pqueue** phead, char* data) {
	pqueue* curr = (pqueue*)malloc(sizeof(pqueue));
	if (!curr) return;
	curr->data = data;
	curr->next = NULL;
	curr->prev = NULL;

	if (*phead == NULL) {
		*phead = curr;
	}
	else {
		pqueue* current = *phead;
		
		if (strcmp(data, (*phead)->data) > 0) {
			curr->next = *phead;
			(*phead)->prev = curr;
			*phead = curr;
		}
		else {
			while (current->next != NULL && strcmp(data, (char*)current->next->data) <= 0) {
				current = current->next;
			}
			curr->next = current->next;
			if (current->next != NULL) {
				current->next->prev = curr;
			}
			current->next = curr;
			curr->prev = current;
		}
	}
}



void qremove(pqueue** phead, int k) {
	if (*phead == NULL || k < 0) {
		printf("Index out of range.\n");
		return;
	}
	pqueue* temp1 = *phead;
	int i;
	for (i = 0; temp1 != NULL && i < k; i++) {
		temp1 = temp1->next;
	}
	if (temp1 == NULL) {
		printf("Index out of range.\n");
		return;
	}
	if (*phead == temp1) {
		*phead = temp1->next;
		if (*phead != NULL) {
			(*phead)->prev = NULL;
		}
	}
	else { 
		if (temp1->next != NULL) {
			temp1->next->prev = temp1->prev;
		}
		if (temp1->prev != NULL) {
			temp1->prev->next = temp1->next;
		}
	}
	free(temp1->data);
	free(temp1);
}

void qclear(pqueue** phead) {
	pqueue* current = *phead;
	pqueue* next = NULL;
	while (current != NULL) {
		next = current->next;
		free(current->data);
		free(current);
		current = next;
	}
	*phead = NULL;
}

