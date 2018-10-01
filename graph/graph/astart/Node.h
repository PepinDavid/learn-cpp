#include <stdio.h>
#include <string>
#include <vector>
#include <list>

#ifndef DEF_NODE
#define DEF_NODE

struct point{
    int x,y;
};

class Node{
     private:
        int _id;
        point _p;
        std::vector<Node*> _children;
        std::vector<Node*> _parents;
        std::list<int> _distChildren;
        std::list<int> _distParents;
    public:
        Node();
        Node(int id);
        Node(int id, point p);
        ~Node();
        int getId();
        void addChild(Node* n);
        void addParent(Node* n);
        int sizeChildren();
        std::vector<Node*> getChildren();
        std::list<int> getChildrenDist();
        int sizeParents();
        std::vector<Node*> getParents();
        std::list<int> getParentsDist();
        bool isRoot();
        bool isLeaf();
        float distance(Node* n2);

        static int hasNodeInPC(std::vector<Node*> *noeuds, Node* n);
};

#endif
