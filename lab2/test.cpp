#include "pch.h"
#include "..\lab2\avl.h"

TEST(creating, parent) {
	node* node = new_node(1);
	EXPECT_EQ(1, node->key);
	EXPECT_EQ(1, node->height);
	EXPECT_EQ(nullptr, node->right);
	EXPECT_EQ(nullptr, node->left);
	EXPECT_EQ(nullptr, node->parent);
}
TEST(hight, new_node) {
	node* node = new_node(2);
	EXPECT_EQ(1, height(node));
}

TEST(hight, empty) {
	EXPECT_EQ(0, height(NULL));
}

TEST(hight, four_nodes) {
	node* node = new_node(1);
	node = insert(node, 2);
	node = insert(node, 3);
	node = insert(node, 4);
	EXPECT_EQ(3, height(node));
}

TEST(remove, node) {
	node* node = new_node(1);
	node = insert(node, 2);
	node = remove(node, 1);
	EXPECT_EQ(2, node->key);
}

TEST(remove, nonexistent) {
	node* node = new_node(1);
	node = remove(node, 2);
	EXPECT_EQ(1, node->key);
}

TEST(insert, add_right) {
	node* node = new_node(1);
	node = insert(node, 2);
	EXPECT_EQ(2, (node->right)->key);
}

TEST(insert, add_left) {
	node* node = new_node(2);
	node = insert(node, 1);
	EXPECT_EQ(1, (node->left)->key);
}

TEST(insert, rotate) {
	node* node = new_node(1);
	node = insert(node, 2);
	node = insert(node, 3);
	EXPECT_EQ(2, (node->key));
	EXPECT_EQ(1, (node->left)->key);
	EXPECT_EQ(3, (node->right)->key);
}

TEST(insert, rotate2) {
	node* node = new_node(3);
	node = insert(node, 2);
	node = insert(node, 1);
	EXPECT_EQ(2, (node->key));
	EXPECT_EQ(1, (node->left)->key);
	EXPECT_EQ(3, (node->right)->key);
}

TEST(insert, tree) {
	node* node = new_node(5);
	node = insert(node, 6);;
	node = insert(node, 3);
	node = insert(node, 2);
	node = insert(node, 4);
	node = insert(node, 7);
	EXPECT_EQ(5, node->key);
	EXPECT_EQ(6, (node->right)->key);
	EXPECT_EQ(7, ((node->right)->right)->key);
	EXPECT_EQ(3, (node->left)->key);
	EXPECT_EQ(4, ((node->left)->right)->key);
	EXPECT_EQ(2, ((node->left)->left)->key);
}