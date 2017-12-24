#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
	cout << "���Ա��˳��洢" << endl << endl;
	cout << "�������Ա�" << endl;
	ArrayList<int> al({ 1,3,5,7,9,11,13,15 });
	cout << al << endl << endl;
	cout << "�ڵ�4��λ�����һ��100" << endl;
	al.insert(100, 4);
	cout << al << endl << endl;
	cout << "ɾ����8��Ԫ��" << endl;
	al.remove(8);
	cout << al << endl << endl;
	system("pause");
	cout << endl;

	cout << "���Ա����ʽ�洢" << endl << endl;
	cout << "�������Ա�" << endl;
	LinkedList<int> ll({ 2,4,6,8,10,12,14,16 });
	cout << ll << endl << endl;
	cout << "�ڵ�3��λ�����һ��100" << endl;
	ll.insert(100, 3);
	cout << ll << endl << endl;
	cout << "ɾ����5��Ԫ��" << endl;
	ll.remove(5);
	cout << ll << endl << endl;
	cout << "����" << endl;
	ll.reverse();
	cout << ll << endl << endl;
	system("pause");
	cout << endl;

	cout << "ջ��˳��洢" << endl << endl;
	cout << "���δ���1��2��3��4��5��6" << endl;
	ArrayStack<int> as;
	as.push(1); as.push(2); as.push(3); as.push(4); as.push(5); as.push(6);
	cout << "�����γ�ջ" << endl;
	while (!as.empty()) {
		cout << as.pop() << endl;
	}
	cout << endl;
	system("pause");
	cout << endl;

	cout << "ջ����ʽ�洢" << endl << endl;
	cout << "���δ���7��8��9��10��11��12" << endl;
	LinkedStack<int> ls;
	ls.push(7); ls.push(8); ls.push(9); ls.push(10); ls.push(11); ls.push(12);
	cout << "�����γ�ջ" << endl;
	while (!ls.empty()) {
		cout << ls.pop() << endl;
	}
	cout << endl;
	system("pause");
	cout << endl;

	cout << "ѭ������" << endl << endl;
	cout << "����һ����СΪ5�Ķ���" << endl;
	CircularQueue<int> cq(5);
	cout << "���ν�1��2��3��4��5���" << endl;
	cq.push(1); cq.push(2); cq.push(3); cq.push(4); cq.push(5);
	cout << "ǰ����Ԫ�س���" << endl;
	cout << cq.pop() << endl;
	cout << cq.pop() << endl;
	cout << "��6��7��ӣ���ȫ������" << endl;
	cq.push(6);
	cq.push(7);
	while (!cq.empty()) {
		cout << cq.pop() << endl;
	}
	cout << endl;
	return 0;
}