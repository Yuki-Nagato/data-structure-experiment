#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

struct Edge {
	int v, w;
};

struct Dis {
	int u, v, d;
	bool operator< (const Dis& b) const {
		return d > b.d;
	}
};

struct FullEdge {
	int u, v, w;
	bool operator< (const FullEdge& b) const {
		return w > b.w;
	}
};

class Graph {
private:
	int n;
	std::vector<std::vector<Edge> > g;
	void inner_dfs(int u, std::vector<int>& rst, std::vector<bool>& vis) const {
		vis[u] = true;
		rst.push_back(u);
		for (Edge e : edgesFrom(u))
			if (!vis[e.v]) {
				inner_dfs(e.v, rst, vis);
			}
	}
public:
	Graph(int n) : n(n), g(n) {}
	void addEdge(int u, int v, int w) {
		g[u - 1].push_back({ v, w });
	}
	int countOfNode() const {
		return n;
	}
	const std::vector<Edge>& edgesFrom(int u) const {
		return g[u - 1];
	}
	std::vector<int> dfs() const {
		std::vector<int> rst;
		std::vector<bool> vis(countOfNode() + 1);
		for(int from = 1; from <= countOfNode(); from++)
			if(!vis[from])
				inner_dfs(from, rst, vis);
		return rst;
	}
	std::vector<int> bfs() const {
		std::vector<int> rst;
		std::queue<int> que;
		std::vector<bool> vis(countOfNode() + 1);
		for(int from = 1; from<=countOfNode(); from++)
			if (!vis[from]) {
				que.push(from);
				rst.push_back(from);
				vis[from] = true;
				while (!que.empty()) {
					int u = que.front();
					que.pop();
					for (const Edge& e : edgesFrom(u)) {
						if (vis[e.v])
							continue;
						que.push(e.v);
						vis[e.v] = true;
						rst.push_back(e.v);
					}
				}
			}
		return rst;
	}
	int dijkstra(int from, int to, std::stack<int>& route) {
		std::vector<int> dis(countOfNode() + 1, 0x3f3f3f3f), minFrom(countOfNode()+1);
		std::priority_queue<Dis> que;
		que.push({ -1, from, 0 });
		while (!que.empty()) {
			int u = que.top().v, d = que.top().d, last = que.top().u;
			que.pop();
			if (dis[u] <= d)
				continue;
			dis[u] = d;
			minFrom[u] = last;
			if (u == to) { // find
				while (u != -1) {
					route.push(u);
					u = minFrom[u];
				}
				return dis[to];
			}
			for (Edge e : edgesFrom(u)) {
				int v = e.v, w = e.w;
				if (dis[v] <= d + w)
					continue;
				que.push({ u, v, d + w });
			}
		}
		return -1;
	}
	int prim(std::vector<FullEdge>& edgeSet) const {
		std::vector<std::vector<int> > g(countOfNode() + 1, std::vector<int>(countOfNode() + 1, 0x3f3f3f3f));
		for (int i = 1; i <= countOfNode(); i++) {
			for (const Edge& e : edgesFrom(i)) {
				g[i][e.v] = g[e.v][i] = std::min(g[i][e.v], e.w);
			}
		}

		std::vector<int> mincost(countOfNode() + 1, 0x3f3f3f3f), from(countOfNode() + 1);
		std::vector<bool> vis(countOfNode() + 1);
		int u = 1, rst = 0;
		while (edgeSet.size() < countOfNode() - 1) {
			vis[u] = true;
			int minv = -1;
			for (int v = 2; v <= countOfNode(); v++) {
				if (vis[v])
					continue;
				if (g[u][v] < mincost[v]) {
					mincost[v] = g[u][v];
					from[v] = u;
				}
				if (minv == -1 || mincost[v] < mincost[minv]) {
					minv = v;
				}
			}
			rst += mincost[minv];
			edgeSet.push_back({ from[minv], minv, mincost[minv] });
			u = minv;
		}
		return rst;
	}
};
