//
// Created by 20852 on 2025/12/12.
//

#ifndef DATASTRUCTANDALGORITHMLEARING_GRAPH_H
#define DATASTRUCTANDALGORITHMLEARING_GRAPH_H
#pragma once
#include <vector>
#include <utility>
#include <functional>

class Graph {
public:
    Graph(int n);
    virtual ~Graph() = default;

    virtual int n() const;
    virtual int e() const;

    virtual int getMark(int v) const;
    virtual void setMark(int v, int m);

    virtual void addEdge(int u, int v, int w = 1) = 0;
    virtual void removeEdge(int u, int v) = 0;
    virtual bool isEdge(int u, int v) const = 0;
    virtual int weight(int u, int v) const = 0;

    virtual int first(int u) const = 0;
    virtual int next(int u, int w) const = 0;

protected:
    int numVertex;
    int numEdge;
    std::vector<int> mark;
};

class AdjListGraph : public Graph {
public:
    AdjListGraph(int n);
    ~AdjListGraph() override = default;

    void addEdge(int u, int v, int w = 1) override;
    void removeEdge(int u, int v) override;
    bool isEdge(int u, int v) const override;
    int weight(int u, int v) const override;

    int first(int u) const override;
    int next(int u, int w) const override;

private:
    struct Edge {
        int to;
        int weight;
    };

    std::vector<std::vector<Edge>> adj;
};

class GraphAlgo {
public:
    static void DFS(Graph &g, int v);
    static void BFS(Graph &g, int v);
    static void TopSort_DFS(Graph &g, std::vector<int> &result);
    static void TopSort_Kahn(Graph &g, std::vector<int> &result);

private:
    static void DFS_Visit(Graph &g, int v, std::vector<int> &result);
};

#endif //DATASTRUCTANDALGORITHMLEARING_GRAPH_H