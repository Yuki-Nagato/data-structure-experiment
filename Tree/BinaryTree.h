#pragma once

#include <string>
#include <stack>
#include <algorithm>

struct Node {
	char data;
	Node* lchild, *rchild;
};

class BinaryTree {
private:
	Node* root;
	void init(const std::string& preorder, int& index, Node*& nowNode) {
		char data = preorder[index];
		if (data == '^')
			return;
		nowNode = new Node();
		nowNode->data = data;
		++index;
		init(preorder, index, nowNode->lchild);
		++index;
		init(preorder, index, nowNode->rchild);
	}
	std::string preOrder(Node* p) {
		if (p == nullptr)
			return std::string();
		std::string rst(1, p->data);
		rst += preOrder(p->lchild);
		rst += preOrder(p->rchild);
		return rst;
	}
	std::string preOrder() {
		std::stack<Node*> stk;
		std::string rst;
		Node* p = root;
		while (p != nullptr || !stk.empty()) {
			while (p != nullptr) {
				rst += p->data;
				stk.push(p);
				p = p->lchild;
			}
			if (!stk.empty()) {
				p = stk.top();
				stk.pop();
				p = p->rchild;
			}
		}
		return rst;
	}
	std::string inOrder(Node* p) {
		if (p == nullptr)
			return std::string();
		std::string rst;
		rst += inOrder(p->lchild);
		rst += p->data;
		rst += inOrder(p->rchild);
		return rst;
	}
	std::string inOrder() {
		std::stack<Node*> stk;
		std::string rst;
		Node* p = root;
		while (p != nullptr || !stk.empty()) {
			while (p != nullptr) {
				stk.push(p);
				p = p->lchild;
			}
			if (!stk.empty()) {
				p = stk.top();
				stk.pop();
				rst += p->data;
				p = p->rchild;
			}
		}
		return rst;
	}
	std::string postOrder(Node* p) {
		if (p == nullptr)
			return std::string();
		std::string rst;
		rst += postOrder(p->lchild);
		rst += postOrder(p->rchild);
		rst += p->data;
		return rst;
	}
	std::string postOrder() {
		std::stack<std::pair<Node*, bool> > stk;
		stk.push(std::make_pair(root, false));
		std::string rst;
		while (!stk.empty())
		{
			Node* p = stk.top().first;
			bool visited = stk.top().second;
			stk.pop();
			if (p == nullptr)
				continue;
			if (visited) {
				rst += p->data;
			}
			else {
				stk.push(std::make_pair(p, true));
				stk.push(std::make_pair(p->rchild, false));
				stk.push(std::make_pair(p->lchild, false));
			}
		}
		return rst;
	}
	int depthDfs(Node* n, int d) const {
		int rst = ++d;
		if (n->lchild != nullptr) {
			rst = std::max(rst, depthDfs(n->lchild, d));
		}
		if (n->rchild != nullptr) {
			rst = std::max(rst, depthDfs(n->rchild, d));
		}
		return rst;
	}
	void nodeCountDfs(Node* n, int& c) const {
		++c;
		if (n->lchild != nullptr) {
			nodeCountDfs(n->lchild, c);
		}
		if (n->rchild != nullptr) {
			nodeCountDfs(n->rchild, c);
		}
	}
	void leavesCountDfs(Node* n, int& c) const {
		bool add = true;
		if (n->lchild != nullptr) {
			leavesCountDfs(n->lchild, c);
			add = false;
		}
		if (n->rchild != nullptr) {
			leavesCountDfs(n->rchild, c);
			add = false;
		}
		if (add)
			++c;
	}
	void twoBranchesCountDfs(Node* n, int& c) const {
		int add = 0;
		if (n->lchild != nullptr) {
			twoBranchesCountDfs(n->lchild, c);
			++add;
		}
		if (n->rchild != nullptr) {
			twoBranchesCountDfs(n->rchild, c);
			++add;
		}
		if (add == 2)
			++c;
	}

public:
	BinaryTree(const std::string& preorder) {
		int index = 0;
		init(preorder, index, root);
	}
	
	enum traverseMethod
	{
		recursively,
		non_recursively
	};
	std::string preOrder(traverseMethod method) {
		return method == recursively ? preOrder(root) : preOrder();
	}
	std::string inOrder(traverseMethod method) {
		return method == recursively ? inOrder(root) : inOrder();
	}
	std::string postOrder(traverseMethod method) {
		return method == recursively ? postOrder(root) : postOrder();
	}
	int depth() const {
		return depthDfs(root, 0);
	}
	int nodeCount() const {
		int rst = 0;
		nodeCountDfs(root, rst);
		return rst;
	}
	int leavesCount() const {
		int rst = 0;
		leavesCountDfs(root, rst);
		return rst;
	}
	int twoBranchesCount() const {
		int rst = 0;
		twoBranchesCountDfs(root, rst);
		return rst;
	}
};