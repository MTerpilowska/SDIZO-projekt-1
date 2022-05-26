#ifndef BST_H
#define BST_H
#include"BSTItem.h"


class BST
{
    public:
        BST();
		virtual ~BST();

		void displayPreorder();
		void displayInorder();
		void displayPostorder();
		void delete1(int key);
		BSTItem *searchREC(int key);
		BSTItem *searchIT(int key);
		void createAndInsert(int key);

    protected:

    private:
        BSTItem *root;
		BSTItem *insertNode(BSTItem *node, BSTItem *newNode);
		BSTItem *bstsearch(BSTItem *node, int key);
		BSTItem *consequent(BSTItem *root);
		BSTItem *delete2(BSTItem *root, int key);
		void preorder(BSTItem *p);
		void inorder(BSTItem *p);
		void postorder(BSTItem *p);

};

#endif // BST_H
