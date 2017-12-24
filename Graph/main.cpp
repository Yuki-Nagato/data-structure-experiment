#include <iostream>
#include <vector>
#include <stack>
#include "Graph.h"

using namespace std;

int main()
{
	cout << "������ͼ�Ķ������ͱ�����";
	int n, m;
	cin >> n >> m;
	Graph graph(n);
	for (int i = 1; i <= m; i++) {
		cout << "�������" << i << "���ߣ�";
		int u, v, w;
		cin >> u >> v >> w;
		graph.addEdge(u, v, w);
	}
	cout << endl;
	vector<int> dfsrst = graph.dfs();
	cout << "DFS���Ϊ��";
	for (int i : dfsrst)
		cout << i << ' ';
	cout << endl;
	vector<int> bfsrst = graph.bfs();
	cout << "BFS���Ϊ��";
	for (int i : bfsrst)
		cout << i << ' ';
	cout << endl;

	vector<FullEdge> mstEdges;
	cout << endl << "��С��������СΪ��" << graph.prim(mstEdges) << endl;
	cout << "�߼�Ϊ��" << endl;
	for (const auto& e : mstEdges) {
		cout << e.u << ' ' << e.v << ' ' << e.w << endl;
	}
	cout << endl << "�����������յ㣺";
	int from, to;
	cin >> from >> to;
	std::stack<int> route;
	cout << "���·��Ϊ" << graph.dijkstra(from, to, route) << endl;
	while (!route.empty()) {
		cout << route.top();
		route.pop();
		if (!route.empty())
			cout << "->";
	}
	cout << endl;
	return 0;
}

/*
7 11
1 2 6
1 4 3
1 3 5
2 4 6
3 5 1
4 5 3
5 6 1
6 7 2
2 7 10
3 6 7
2 6 2
1 7
*/