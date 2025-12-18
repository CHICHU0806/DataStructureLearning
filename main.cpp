#include <iostream>
#include "SeqList.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "DoublyCircularLinkedList.h"
#include "Graph.h"
#include "StaticLinkedList.h"
#include "Stack/Inc/SeqStack.h"
#include "Stack/Inc/LnkStack.h"
#include "Queue/Inc/SeqQueue.h"
#include "Queue/Inc/LinkedQueue.h"
#include "Tree/Inc/BinaryTree.h"
#include "Tree/Inc/BinarySearchTree.h"
#include "Tree/Inc/SeqBinaryTree.h"
#include "queue"
using namespace std;

int main() {
    //
    // AdjListGraph g(7);
    //
    // g.addEdge(0, 1);
    // g.addEdge(0, 2);
    // g.addEdge(1, 3);
    // g.addEdge(1, 4);
    // g.addEdge(2, 4);
    // g.addEdge(3, 5);
    // g.addEdge(4, 6);
    //
    // std::cout << "Graph created." << std::endl;
    // std::cout << "Vertex count: " << g.n() << std::endl;
    // std::cout << "Edge count: " << g.e() << std::endl;
    //
    // std::cout << "\nDFS from node 0: ";
    // std::vector<int> dfsResult;
    // GraphAlgo::DFS(g, 0);
    //
    // for (int i = 0; i < g.n(); ++i) g.setMark(i, 0);
    // std::vector<int> dfsPath;
    // std::function<void(int)> dfsTest = [&](int v){
    //     g.setMark(v, 1);
    //     dfsPath.push_back(v);
    //     int w = g.first(v);
    //     while (w != -1) {
    //         if (g.getMark(w) == 0)
    //             dfsTest(w);
    //         w = g.next(v, w);
    //     }
    // };
    // dfsTest(0);
    //
    // for (int x : dfsPath) std::cout << x << " ";
    // std::cout << std::endl;
    //
    // std::cout << "\nBFS from node 0: ";
    // for (int i = 0; i < g.n(); ++i) g.setMark(i, 0);
    //
    // std::vector<int> bfsPath;
    // std::queue<int> q;
    // q.push(0);
    // g.setMark(0, 1);
    //
    // while (!q.empty()) {
    //     int u = q.front();
    //     q.pop();
    //     bfsPath.push_back(u);
    //     int w = g.first(u);
    //     while (w != -1) {
    //         if (g.getMark(w) == 0) {
    //             g.setMark(w, 1);
    //             q.push(w);
    //         }
    //         w = g.next(u, w);
    //     }
    // }
    //
    // for (int x : bfsPath) std::cout << x << " ";
    // std::cout << std::endl;
    //
    // std::vector<int> topDFS;
    // GraphAlgo::TopSort_DFS(g, topDFS);
    // std::cout << "\nTopSort (DFS version): ";
    // for (int x : topDFS) std::cout << x << " ";
    // std::cout << std::endl;
    //
    // std::vector<int> topKahn;
    // GraphAlgo::TopSort_Kahn(g, topKahn);
    // std::cout << "\nTopSort (Kahn version): ";
    // for (int x : topKahn) std::cout << x << " ";
    // std::cout << std::endl;
    //
    // std::cout << "\n\nTesting first / next from node 1: ";
    // int w = g.first(1);
    // while (w != -1) {
    //     std::cout << w << " ";
    //     w = g.next(1, w);
    // }
    // std::cout << std::endl;
    //
    // std::cout << "\nTesting edge info: ";
    // std::cout << "isEdge(1,4) = " << g.isEdge(1,4);
    // std::cout << ", weight = " << g.weight(1,4) << std::endl;
    //
    // std::cout << "isEdge(4,1) = " << g.isEdge(4,1) << std::endl;
    //
    // std::cout << "\nRemoving edge 1 to 4 ..." << std::endl;
    // g.removeEdge(1,4);
    // std::cout << "isEdge(1,4) = " << g.isEdge(1,4) << std::endl;

    // Dijkstra Test
    std::cout << "\nTesting Dijkstra from node 0:" << std::endl;

    AdjListGraph g2(5);
    g2.addEdge(0, 1, 10);
    g2.addEdge(0, 4, 5);
    g2.addEdge(1, 2, 1);
    g2.addEdge(1, 4, 2);
    g2.addEdge(2, 3, 4);
    g2.addEdge(3, 2, 6);
    g2.addEdge(3, 0, 7);
    g2.addEdge(4, 1, 3);
    g2.addEdge(4, 2, 9);
    g2.addEdge(4, 3, 2);

    std::vector<int> dist, prev;
    GraphAlgo::Dijkstra(g2, 0, dist, prev);

    for (int i = 0; i < g2.n(); ++i) {
        std::cout << "Dist to " << i << ": " << dist[i] << ", Prev: " << prev[i] << std::endl;
    }

    return 0;
}