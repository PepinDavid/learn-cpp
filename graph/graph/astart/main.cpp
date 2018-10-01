#include <stdio.h>
#include <iostream>
#include <map>
#include "Node.h"
#include "Graph.h"

using namespace std;

void changeXYpoint(point *p, int x, int y){
    p->x = x;
    p->y = y;
}

int main(int argc, char **argv)
{
    point p;
    changeXYpoint(&p, 1, 1);
    Node* A = new Node(1, p); //A
    changeXYpoint(&p, 2, 0);
    Node* D = new Node(4, p); //D
    changeXYpoint(&p, 2, 2);
    Node* B = new Node(2, p); //B
    changeXYpoint(&p, 2, 4);
    Node* C = new Node(3, p); //C
    changeXYpoint(&p, 8, 2);
    Node* E = new Node(5, p); //E
    changeXYpoint(&p, 6, 4);
    Node* F = new Node(6, p); //F
    changeXYpoint(&p, 6, 6);
    Node* G = new Node(7, p);  //G
    //ID => A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7    
	vector<pair<Node*, Node*>> graphe = {{A, B}, {A, C}, {B, D}, {B, E}, {E, F}, {E, G}, {C, F}, {F, G}};

    Graph noeuds;
    Node* noeud = 0;
    for(auto n: graphe){
        noeuds.addNode(n.first);
        noeuds.addNode(n.second);
        noeud = noeuds.findNode(n.first);
       // cout << " ptr et id " << n.first <<  " " << n.first->getId() << endl;
        noeud->addChild(n.second);
        noeud = noeuds.findNode(n.second);
        //cout << " ptr et id " << n.second <<  " " << n.second->getId() << endl;
        noeud->addParent(n.first);
    }
    //cout << noeuds.sumNodes() << endl;
    int src = 1;

    //noeuds.bfs(src);
    noeuds.bfsReelDist(src);
    
    
    
	return 0;
}


/*
 *     D
 *     |
 * A---B--------E
 *  |           |
 *  |      |----|
 *  |--C---F--->G
 *
 *
 *
 *
 *
 */
