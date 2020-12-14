#include<iostream>
#include "BinarySearchTree.h"
using namespace std;

void BinarySearchTree::insert(int key) {
	Node* t = root;
	Node* r = nullptr;
	Node* p;

	p = new Node;
	p->data = key;
	p->lchild = nullptr;
	p->rchild = nullptr;

	if (root == nullptr) {
		root = p;	
		return;
	}
	
	while (t)
	{
		r = t;
		if (key < t->data)t = t->lchild;
		else if (key > t->data)t = t->rchild;
		else return;
	}

	if (key < r->data) {
		r->lchild = p;
	}
	else {
		r->rchild = p;
	}
	
	
}

void BinarySearchTree::InOrder(Node* t) {
	if (t) {
		InOrder(t->lchild);
		cout << t->data << " ";
		InOrder(t->rchild);
	}
}

void BinarySearchTree::deleteNodes(Node* t) {
	if (t) {
		deleteNodes(t->lchild);
		delete t;
		deleteNodes(t->rchild);
	}
}

Node* BinarySearchTree::Rinsert(Node* t, int key) {
	Node* p;
	if (t == NULL) {
		p = new Node;
		p->data = key;
		p->lchild = p->rchild = nullptr;
		return p;
	}
	if (key < t->data) {
		t->lchild = Rinsert(t->lchild, key);
	}
	else if (key > t->data) {
		t->rchild = Rinsert(t->rchild, key);
	}
	return t;
}

int BinarySearchTree::Height(Node* t) {
	int x, y;
	x = Height(t->lchild);
	y = Height(t->rchild);
	return x > y ? x + 1 : y + 1;
}

Node* BinarySearchTree::Inpre(Node* t) {
	if (t && t->rchild != nullptr) {
		t = t->rchild;
	}
	return t;
}

Node* BinarySearchTree::InSucc(Node* t) {
	if (t && t->lchild != nullptr) {
		t = t->lchild;
	}
	return t;
}

Node* BinarySearchTree::Delete(Node* p, int key) {
	Node* q;
	if (p == nullptr) {
		return nullptr;
	}
	if (p->lchild == nullptr && p->rchild == nullptr) {
		if (p == nullptr) {
			root = nullptr;
		}
		delete p;
		return nullptr;
	}
	if (key < p->data) {
		p->lchild = Delete(p->lchild, key);
	}
	else if (key > p->data) {
		p->rchild = Delete(p->rchild, key);
	}
	else {
		if (Height(p->lchild) < Height(p->rchild)) {
			q = Inpre(p->lchild);
			p->data = q->data;
			p->lchild = Delete(p->lchild, q->data);
		}
		else {
			q = InSucc(p->rchild);
			p->data = q->data;
			p->rchild = Delete(p->rchild, q->data);
		}
	}
	return p;
}

int main() {
	int ch;
	cout << "######## Welcome to BST Data Structure ###########" <<endl;
	BinarySearchTree B;
	do {
		cout << "\nEnter the Operation, you want to perform on the binary tree " << endl;
		cout << "[1] - Insert an Element" << endl;
		cout << "[2] - Display Inorder"<<endl;
		cout << "[3] - Display Inorder Predecessor" << endl;
		cout << "[4] - Display Inorder Successor" << endl;
		cout << "[5] - Delete a Node" << endl;
		cout << "[6] - Display Height" << endl;
		cout << "[0] - Quit" << endl;
		cout << "\nEnter your choice : ";
		cin >> ch;

		if (ch == 1) {
			cout << "\nChoose an option!\n";
			cout << "[1] - Recurrsive insert" << endl;
			cout << "[2] - Iterative insert" << endl;
			cout << "\nEnter your choice : ";
			int subch;
			cin >> subch;
			int key;
			cout << "\nEnter the key, you want to insert in the Binary Search Tree : ";
			cin >> key;
			if (subch == 2) {
				B.insert(key);
			}
			else if (subch == 1) {
				B.root=B.Rinsert(B.root, key);
			}
			else {
				cout << "\nInvalid Choice, Enter again" << endl;
			}
			cout << "\nInserted Successfully" << endl;
		}
		else if (ch == 2) {
			cout<<"INORDER : "<<endl;
			B.InOrder(B.root);
		}
		else if (ch == 3) {
			Node* q;
			q = B.Inpre(B.root);
			cout << "INORDER Predecessor: "<<q->data << endl;

		}
		else if (ch == 4) {
			Node* q;
			q=B.InSucc(B.root);
			cout << "INORDER Successor: " << q->data<<endl;

		}
		else if (ch == 5) {
			int key;
			cout << "\nEnter the key, you want to delete from the Binary Search Tree : ";
			cin >> key;
			
			B.Delete(B.root,key);
			cout << "Deleted Successfully! " << endl;
		}
		else if (ch == 6) {
			cout << "Height : " << endl;
			B.Height(B.root);
		}
		else if (ch == 0) {
			cout << "\nThanks for using the Application"<<endl;
		}
		else {
			cout << "\nInvalid Choice, Enter again!" << endl;
		}
	} while (ch != 0);
	return 0;
}