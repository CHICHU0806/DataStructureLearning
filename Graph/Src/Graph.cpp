#include "Graph.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

Graph::Graph(int n)
        : numVertex(n), numEdge(0), mark(n, 0) {}

int Graph::n() const { return numVertex; }

int Graph::e() const { return numEdge; }

int Graph::getMark(int v) const { return mark[v]; }

void Graph::setMark(int v, int m) { mark[v] = m; }

AdjListGraph::AdjListGraph(int n)
        : Graph(n), adj(n) {}

void AdjListGraph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    numEdge++;
}

void AdjListGraph::removeEdge(int u, int v) {
    auto &lst = adj[u];
    for (auto it = lst.begin(); it != lst.end(); ++it) {
        if (it->to == v) {
            lst.erase(it);
            numEdge--;
            return;
        }
    }
}

bool AdjListGraph::isEdge(int u, int v) const {
    for (const auto &e : adj[u]) {
        if (e.to == v) return true;
    }
    return false;
}

int AdjListGraph::weight(int u, int v) const {
    for (const auto &e : adj[u]) {
        if (e.to == v) return e.weight;
    }
    return 0;
}

int AdjListGraph::first(int u) const {
    if (adj[u].empty()) return -1;
    return adj[u][0].to;
}

int AdjListGraph::next(int u, int w) const {
    const auto &lst = adj[u];
    for (size_t i = 0; i < lst.size(); ++i) {
        if (lst[i].to == w && i + 1 < lst.size()) {
            return lst[i + 1].to;
        }
    }
    return -1;
}

void GraphAlgo::DFS_Visit(Graph &g, int v, std::vector<int> &result) {
    g.setMark(v, 1);
    result.push_back(v);
    int w = g.first(v);
    while (w != -1) {
        if (g.getMark(w) == 0) DFS_Visit(g, w, result);
        w = g.next(v, w);
    }
}

void GraphAlgo::DFS(Graph &g, int v) {
    std::vector<int> result;
    for (int i = 0; i < g.n(); ++i) g.setMark(i, 0);
    DFS_Visit(g, v, result);

    // 输出
    for (int x : result) std::cout << x << " ";
    std::cout << std::endl;
}

void GraphAlgo::BFS(Graph &g, int v) {
    for (int i = 0; i < g.n(); ++i) g.setMark(i, 0);

    std::queue<int> q;
    q.push(v);
    g.setMark(v, 1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        std::cout << u << " ";

        int w = g.first(u);
        while (w != -1) {
            if (g.getMark(w) == 0) {
                g.setMark(w, 1);
                q.push(w);
            }
            w = g.next(u, w);
        }
    }
    std::cout << std::endl;
}

void GraphAlgo::TopSort_DFS(Graph &g, std::vector<int> &result) {
    result.clear();
    for (int i = 0; i < g.n(); ++i) g.setMark(i, 0);

    std::stack<int> st;
    std::function<void(int)> dfs_visit = [&](int v) {
        g.setMark(v, 1);
        int w = g.first(v);
        while (w != -1) {
            if (g.getMark(w) == 0) dfs_visit(w);
            w = g.next(v, w);
        }
        st.push(v);
    };

    for (int i = 0; i < g.n(); ++i)
        if (g.getMark(i) == 0) dfs_visit(i);

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
}

void GraphAlgo::TopSort_Kahn(Graph &g, std::vector<int> &result) {
    result.clear();
    std::vector<int> indeg(g.n(), 0);

    for (int u = 0; u < g.n(); ++u) {
        int w = g.first(u);
        while (w != -1) {
            indeg[w]++;
            w = g.next(u, w);
        }
    }

    std::queue<int> q;
    for (int i = 0; i < g.n(); ++i)
        if (indeg[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        int w = g.first(u);
        while (w != -1) {
            indeg[w]--;
            if (indeg[w] == 0) q.push(w);
            w = g.next(u, w);
        }
    }
}
