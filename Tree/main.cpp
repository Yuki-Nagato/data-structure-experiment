#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main() {
	string po;
	cout << "请按前序遍历输入一棵树，空树用^表示：" << endl;
	cin >> po;
	BinaryTree bt(po);
	cout << "前序遍历递归：" << endl
		<< bt.preOrder(BinaryTree::recursively) << endl
		<< "前序遍历非递归：" << endl
		<< bt.preOrder(BinaryTree::non_recursively) << endl
		<< "中序遍历递归：" << endl
		<< bt.inOrder(BinaryTree::recursively) << endl
		<< "中序遍历非递归：" << endl
		<< bt.inOrder(BinaryTree::non_recursively) << endl
		<< "后序遍历递归：" << endl
		<< bt.postOrder(BinaryTree::recursively) << endl
		<< "后序遍历非递归：" << endl
		<< bt.postOrder(BinaryTree::non_recursively) << endl
		<< "树的深度：" << endl
		<< bt.depth() << endl
		<< "节点数：" << endl
		<< bt.nodeCount() << endl
		<< "叶子节点数：" << endl
		<< bt.leavesCount() << endl
		<< "二分枝节点数：" << endl
		<< bt.twoBranchesCount() << endl;
	return 0;
}
/*
1 二叉树的遍历
2 哈夫曼树和哈夫曼编码

ab^cd^^e^^fg^h^^i^jk^^^
*/