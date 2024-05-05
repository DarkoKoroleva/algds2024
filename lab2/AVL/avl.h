#include <stdio.h>
#include <stdlib.h>
typedef struct// структура для представления узлов дерева
{
	int key;
	int height;
	struct node* left;
	struct node* right;
	struct node* parent;
} node;

// Функция для создания нового узла с заданным ключом.
node* new_node(int key) {
	node* current_node = (node*)malloc(sizeof(node));
	current_node->key = key;
	current_node->left = NULL;
	current_node->right = NULL;
	current_node->height = 1; // узел без потомков
	return current_node;
}

int height(node* p)
{
	return p ? p->height : 0;
}

int balance_factor(node* p)
{
	return height(p->right) - height(p->left);
}

void fixheight(node* p)
{
	int hl = height(p->left);
	int hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	q->parent = p->parent;
	p->parent = q;
	fixheight(p);
	fixheight(q);
	return q;
}

node* rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	p->parent = q->parent;
	q->parent = p;
	fixheight(q);
	fixheight(p);
	return p;
}

node* balance(node* p) // балансировка узла p
{
	fixheight(p);
	if (balance_factor(p) == 2)
	{
		if (balance_factor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (balance_factor(p) == -2)
	{
		if (balance_factor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // балансировка не нужна
}

node* insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p)
		return new_node(k);
	node* current = p;
	node* parent = NULL;

	while (current != NULL) {
		parent = current;
		if (k < current->key)
			current = current->left;
		else if (k > current->key)
			current = current->right;
		else // ключ уже существует
			return p;
	}

	node* newNode = new_node(k);
	newNode->parent = parent;

	if (k < parent->key)
		parent->left = newNode;
	else
		parent->right = newNode;

	return balance(p);
}

node* findmin(node* p) {
	node* current = p;

	while (current->left != NULL) {
		current = current->left;
	}

	return current;
}

node* removenode(node* p, int key) {
	node* current = p;
	node* parent = NULL;

	while (current != NULL) {
		if (key < current->key) {
			parent = current;
			current = current->left;
		}
		else if (key > current->key) {
			parent = current;
			current = current->right;
		}
		else {
			node* toDelete = current;

			if (current->left == NULL) {
				if (parent == NULL) {
					p = current->right;
				}
				else if (current == parent->left) {
					parent->left = current->right;
				}
				else {
					parent->right = current->right;
				}
			}
			else if (current->right == NULL) {
				if (parent == NULL) {
					p = current->left;
				}
				else if (current == parent->left) {
					parent->left = current->left;
				}
				else {
					parent->right = current->left;
				}
			}
			else {
				node* minNode = findmin(current->right);
				current->key = minNode->key;
				current = minNode;
			}

			free(toDelete);
			break;
		}
	}
	return p;
}


void draw_tree(node* p) {
	if (p != NULL) {
		draw_tree(p->left);
		printf("%d ", p->key);
		draw_tree(p->right);
	}
}
