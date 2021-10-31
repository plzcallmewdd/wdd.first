//未完全版自动AVL树
#include<iostream>
using namespace std;
typedef struct avltree {
	avltree *leftchild;
	avltree *rightchild; 
	int height; //节点深度
	int val; //节点权重
	int avl; //平衡因子

	//构造函数
	avltree(int val = 0) :val(val), leftchild(nullptr), rightchild(nullptr), height(1),avl(0) {};

	//获得当前节点的高度
	void getheight() { 
		int lefth = 0, righth = 0;
		if (leftchild)
			lefth = leftchild->height;
		if (rightchild)
			righth = rightchild->height;
		height = max(lefth, righth) + 1;
	}

	//获得当前节点的平衡因子
	void getavl() {
		if (leftchild && rightchild)
			avl = rightchild->height - leftchild->height;
		else if (!leftchild && !rightchild)
			avl = 0;
		else
			avl = !rightchild ? 0 - (leftchild->height) : rightchild->height;
	}

	//删除函数
	void deletenode() {

	}

	//清空函数
	void doempty() {

	}

	//插入函数
	void findposition(avltree* &head, avltree* tempnode) {
		if (tempnode->val < head->val) {
			if (!head->leftchild) {
				head->leftchild = tempnode;
			}
			else
				findposition(head->leftchild, tempnode);
		}
		else {
			if (!head->rightchild) {
				head->rightchild = tempnode;
			}
			else
				findposition(head->rightchild, tempnode);
		}
		head->getavl();
		if (head->avl > 1) {
			if (head->rightchild->avl > 0)
				head->LL(head);
			else
				head->RL(head);
		}
		if (head->avl < -1) {
			if (head->leftchild->avl < 0)
				head->RR(head);
			else
				head->LR(head);
		}
		head->getheight();
	}

	//插入函数调用
	void insertnode(avltree* &head, int val) {
		if (!head)
			return;
		avltree* temp = new avltree(val);
		head->findposition(head, temp);
	}

	//右旋
	void RR(avltree* &head) {
		avltree* temp = head->leftchild;
		head->leftchild = temp->rightchild;
		temp->rightchild = head;
		head = temp;
		temp = nullptr;
		delete temp;
		head->rightchild->getavl();
		head->rightchild->getheight();
		head->getavl();
	}

	//左旋
	void LL(avltree* &head) {
		avltree* temp = head->rightchild;
		head->rightchild = temp->leftchild;
		temp->leftchild = head;
		head = temp;
		temp = nullptr;
		delete temp;
		head->leftchild->getavl();
		head->leftchild->getheight();
		head->getavl();
	}

	//先右旋再左旋
	void RL(avltree* &head) {
		head->RR(head->rightchild);
		head->LL(head);
	}

	//先左旋再右旋
	void LR(avltree* &head) {
		head->LL(head->leftchild);
		head->RR(head);
	}


	void postorder(avltree* head) {
		if (!head)
			return;
		postorder(head->leftchild);
		postorder(head->rightchild);
		cout << head->val;
	}
	void inorder(avltree* head) {
		if (!head)
			return;
		inorder(head->leftchild);
		cout << head->val;
		inorder(head->rightchild);
	}
	void preorder(avltree* head) {
		if (!head)
			return;
		cout << head->val;
		preorder(head->leftchild);
		preorder(head->rightchild);
	}
};

class Solution {
public:

};

int main() {
	//测试用例
	//avltree* head = new avltree(5);
	//head->insertnode(head, 6);
	//head->insertnode(head, 8);
	//head->insertnode(head, 3);
	//head->insertnode(head, 2);
	//head->insertnode(head, 4);
	//head->insertnode(head, 7);
	//head->inorder(head);
	//cout << endl;
	//head->postorder(head);
	//cout << endl;
	//head->preorder(head);
	return 0;
}