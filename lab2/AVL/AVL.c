#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)
#include "avl.h"

int main() {
	node* p = NULL;

	p = insert(p, 10);
	p = insert(p, 20);
	p = insert(p, 30);
	p = insert(p, 15);

	printf("Before deletion: ");
	draw_tree(p);
	printf("\n");

	p = removenode(p, 15);

	printf("After deletion: ");
	draw_tree(p);
	printf("\n");

	return 0;
}