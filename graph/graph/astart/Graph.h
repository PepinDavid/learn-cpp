#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>

#include "Node.h"

#ifndef DEF_GRAPH
#define DEF_GRAPH

const int INF = 2147483647;
const int NIL = -1;

enum {WHITE, GREY, BLACK};

class Graph{
    private:
        std::vector<Node*> _nodes;
        Node * _root;
    public:
        Graph();
        ~Graph();
        void addNode(Node* n);
        Node* findNode(int id);
        Node* findNode(Node* node);
        int returnItNodes(int id);
        int returnItNodes(Node* node);
        int sumNodes();
        std::vector<Node*> getNodes();
        std::vector<Node*> findLeafs();
        std::vector<Node*> findRoot();
        void bfs(int src);
        void parcoursProfondeur();
        void plusCourtChemin(int id1, int id2);
        void print_path(int src, int dest, std::vector<int> parent);
        void bfsReelDist(int src);
};

#endif
