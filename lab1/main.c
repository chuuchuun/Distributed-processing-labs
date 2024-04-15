#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>
#include "priority_queue_list.h"

int
main(int argc, char** argv) {
	printf("Menu options:\n1.insert new node to the list\n2.remove a node by index\n3.print the list\n4.exit the program\n");
	pqueue* queue = NULL;
	while (1) {
		int func;
		scanf("%d", &func);
		switch (func) {
		case 1:
			printf("Please write the text data of an inserted node\n");
			char* node;
			node = (char*)malloc(sizeof(char)*40);
			scanf("%s", node);
			qinsert(&queue, _strdup(node));
			printf("Menu options:\n1.insert new node to the list\n2.remove a node by index\n3.print the list\n4.exit the program\n");
			free(node);
			break;
		case 2:
			printf("Please write the index of the node you would like to remove\n");
			int index;
			scanf("%d", &index);
			qremove(&queue, index);
			printf("Menu options:\n1.insert new node to the list\n2.remove a node by index\n3.print the list\n4.exit the program\n");
			break;
		case 3:
			qlist(queue);
			printf("Menu options:\n1.insert new node to the list\n2.remove a node by index\n3.print the list\n4.exit the program\n");
			break;
		case 4:
			qclear(&queue);
			_CrtDumpMemoryLeaks();
			return 0;
		}
	}
}
