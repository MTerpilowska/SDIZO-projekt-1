#include "BST.h"
#include <iostream>

using namespace std;

// Drzewo poszukiwañ binarnych BST

BST::BST()
{
	BST::root = NULL;
}

BST::~BST()
{
	free(BST::root);
}

void BST::displayPreorder()
{
	preorder(BST::root);
	cout << endl;
}

void BST::displayInorder()
{
	inorder(BST::root);
	cout << endl;
}

void BST::displayPostorder()
{
	postorder(BST::root);
	cout << endl;
}

void BST::delete1(int key)
{
	BST::root = delete2(BST::root, key);
}

BSTItem *BST::searchREC(int key)
{
	return BST::bstsearch(BST::root, key);
}

BSTItem *BST::searchIT(int key)
{
	BSTItem *node = BST::root;
	while(node != NULL && node->key != key) node=(node->key<key?node->left:node->right);
	return node;
}

void BST::createAndInsert(int key)
{
	BSTItem *node = new BSTItem;
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	if(insertNode(BST::root,node) == node) BST::root = node;
}

BSTItem *BST::insertNode(BSTItem *node, BSTItem *newNode)
{
	if(node == NULL) return newNode;
    if(newNode->key < node->key)
    {
        if(node->left == NULL)
        {
            node->left = newNode;
            newNode->parent = node;
        }
        else
        {
            insertNode(node->left,newNode);
        }
        return node;
    }
    else
    {
        if(node->right == NULL)
        {
            node->right = newNode;
            newNode->parent = node;
        }
        else
        {
            insertNode(node->right,newNode);
        }
        return node;
    }
}

BSTItem *BST::bstsearch(BSTItem *node, int key)
{
	if(node == NULL || node->key == key) return node;
	if(key < node->key) return bstsearch(node->left,key);
	else return bstsearch(node->right,key);
}

BSTItem *BST::consequent(BSTItem *root)
{
	if(root == NULL) return NULL;
	while(root->left != NULL) root = root->left;
	return root;
}

BSTItem *BST::delete2(BSTItem *root, int key)
{
	BSTItem *tmp;
	if(root == NULL) return root;
	if(root->key > key) root->left = delete2(root->left,key);
	else if(root->key < key) root->right = delete2(root->right,key);
	else
	{
		if(root->left == NULL && root->right == NULL)return NULL;
        if(root->left == NULL)
        {
            tmp = root->right;
            delete root;
            return tmp;
        }
        else if(root->right == NULL)
        {
            tmp = root->left;
            delete root;
            return tmp;
        }
        tmp = consequent(root->right);
        root->key = tmp->key;
        root->right = delete2(root->right,tmp->key);
	}
	return root;
}

void BST::preorder(BSTItem *p)
{
	cout << p->key << " ";
	if(p->left != NULL) preorder(p->left);
	if(p->right != NULL) preorder(p->right);
}

void BST::inorder(BSTItem *p)
{
	if(p->left != NULL) inorder(p->left);
	cout << p->key << " ";
	if(p->right != NULL) inorder(p->right);
}

void BST::postorder(BSTItem *p)
{
	if(p->left != NULL) postorder(p->left);
	if(p->right != NULL) postorder(p->right);
	cout << p->key << " ";
}
