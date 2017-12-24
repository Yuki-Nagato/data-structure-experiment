#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main() {
	cout << "线性表的顺序存储" << endl << endl;
	cout << "生成线性表" << endl;
	ArrayList<int> al({ 1,3,5,7,9,11,13,15 });
	cout << al << endl << endl;
	cout << "在第4个位置添加一个100" << endl;
	al.insert(100, 4);
	cout << al << endl << endl;
	cout << "删除第8个元素" << endl;
	al.remove(8);
	cout << al << endl << endl;
	system("pause");
	cout << endl;

	cout << "线性表的链式存储" << endl << endl;
	cout << "生成线性表" << endl;
	LinkedList<int> ll({ 2,4,6,8,10,12,14,16 });
	cout << ll << endl << endl;
	cout << "在第3个位置添加一个100" << endl;
	ll.insert(100, 3);
	cout << ll << endl << endl;
	cout << "删除第5个元素" << endl;
	ll.remove(5);
	cout << ll << endl << endl;
	cout << "逆置" << endl;
	ll.reverse();
	cout << ll << endl << endl;
	system("pause");
	cout << endl;

	cout << "栈的顺序存储" << endl << endl;
	cout << "依次存入1、2、3、4、5、6" << endl;
	ArrayStack<int> as;
	as.push(1); as.push(2); as.push(3); as.push(4); as.push(5); as.push(6);
	cout << "再依次出栈" << endl;
	while (!as.empty()) {
		cout << as.pop() << endl;
	}
	cout << endl;
	system("pause");
	cout << endl;

	cout << "栈的链式存储" << endl << endl;
	cout << "依次存入7、8、9、10、11、12" << endl;
	LinkedStack<int> ls;
	ls.push(7); ls.push(8); ls.push(9); ls.push(10); ls.push(11); ls.push(12);
	cout << "再依次出栈" << endl;
	while (!ls.empty()) {
		cout << ls.pop() << endl;
	}
	cout << endl;
	system("pause");
	cout << endl;

	cout << "循环队列" << endl << endl;
	cout << "建立一个大小为5的队列" << endl;
	CircularQueue<int> cq(5);
	cout << "依次将1、2、3、4、5入队" << endl;
	cq.push(1); cq.push(2); cq.push(3); cq.push(4); cq.push(5);
	cout << "前两个元素出队" << endl;
	cout << cq.pop() << endl;
	cout << cq.pop() << endl;
	cout << "让6、7入队，再全部出队" << endl;
	cq.push(6);
	cq.push(7);
	while (!cq.empty()) {
		cout << cq.pop() << endl;
	}
	cout << endl;
	return 0;
}