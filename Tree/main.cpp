#include <iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

int main() {
	string po;
	cout << "�밴ǰ���������һ������������^��ʾ��" << endl;
	cin >> po;
	BinaryTree bt(po);
	cout << "ǰ������ݹ飺" << endl
		<< bt.preOrder(BinaryTree::recursively) << endl
		<< "ǰ������ǵݹ飺" << endl
		<< bt.preOrder(BinaryTree::non_recursively) << endl
		<< "��������ݹ飺" << endl
		<< bt.inOrder(BinaryTree::recursively) << endl
		<< "��������ǵݹ飺" << endl
		<< bt.inOrder(BinaryTree::non_recursively) << endl
		<< "��������ݹ飺" << endl
		<< bt.postOrder(BinaryTree::recursively) << endl
		<< "��������ǵݹ飺" << endl
		<< bt.postOrder(BinaryTree::non_recursively) << endl
		<< "������ȣ�" << endl
		<< bt.depth() << endl
		<< "�ڵ�����" << endl
		<< bt.nodeCount() << endl
		<< "Ҷ�ӽڵ�����" << endl
		<< bt.leavesCount() << endl
		<< "����֦�ڵ�����" << endl
		<< bt.twoBranchesCount() << endl;
	return 0;
}
/*
1 �������ı���
2 ���������͹���������

ab^cd^^e^^fg^h^^i^jk^^^
*/