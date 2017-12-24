#include <iostream>
#include <vector>
#include <stack>
#include "Graph.h"

using namespace std;

int main()
{
	cout << "请输入图的顶点数和边数：";
	int n, m;
	cin >> n >> m;
	Graph graph(n);
	for (int i = 1; i <= m; i++) {
		cout << "请输入第" << i << "条边：";
		int u, v, w;
		cin >> u >> v >> w;
		graph.addEdge(u, v, w);
	}
	cout << endl;
	vector<int> dfsrst = graph.dfs();
	cout << "DFS结果为：";
	for (int i : dfsrst)
		cout << i << ' ';
	cout << endl;
	vector<int> bfsrst = graph.bfs();
	cout << "BFS结果为：";
	for (int i : bfsrst)
		cout << i << ' ';
	cout << endl;

	vector<FullEdge> mstEdges;
	cout << endl << "最小生成树大小为：" << graph.prim(mstEdges) << endl;
	cout << "边集为：" << endl;
	for (const auto& e : mstEdges) {
		cout << e.u << ' ' << e.v << ' ' << e.w << endl;
	}
	cout << endl << "请输入起点和终点：";
	int from, to;
	cin >> from >> to;
	std::stack<int> route;
	cout << "最短路径为" << graph.dijkstra(from, to, route) << endl;
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