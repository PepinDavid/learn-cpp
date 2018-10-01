#include "Node.h"

float Node::distance(Node* n2){
    return ((_p.x-n2->_p.x)*(_p.x-n2->_p.x) + (_p.y-n2->_p.y)*(_p.y-n2->_p.y));
}

Node::Node(){}

Node::Node(int id){
    _id = id;
}

Node::Node(int id, point p){
    _id = id;
    _p = p;
}

Node::~Node(){}

void Node::addChild(Node* n){
    bool isChild = false;
    float dist = distance(n);
    if(_children.size() == 0){
        _children.push_back(n);
        _distChildren.resize(_children.size());
        //_distChildren[n->getId()].push_back(dist);
        return;
    }
    for(auto child: _children){
        if(child->getId() == n->getId())
            isChild = true;
    }
    if(!isChild){
        _children.push_back(n);
        _distChildren.resize(_children.size());
        //_distChildren[n->getId()].push_back(dist);
    }

}

void Node::addParent(Node* n){
    bool isParent = false;
    float dist = distance(n);
    if(_parents.size() == 0){
        _parents.push_back(n);
        _distParents.resize(_parents.size());
        //_distParents[n->getId()].push_back(dist);
        return;
    }
    for(auto parent: _parents){
        if(parent->getId() == n->getId())
            isParent = true;
    }
    if(!isParent){
        _parents.push_back(n);
        _distParents.resize(_parents.size());
        //_distParents[n->getId()].push_back(dist);
    }
}

int Node::getId(){
    return _id;
}

int Node::sizeChildren(){
    return _children.size();
}

std::vector<Node*> Node::getChildren(){
    return _children;
}

int Node::sizeParents(){
    return _parents.size();
}

std::vector<Node*> Node::getParents(){
    return _parents;
}

std::list<int> Node::getParentsDist(){
    return _distParents;
}

std::list<int> Node::getChildrenDist(){
    return _distChildren;
}

bool Node::isRoot(){
    return (_parents.size() < 1);
}

bool Node::isLeaf(){
    return (_children.size() < 1);
}

int Node::hasNodeInPC(std::vector<Node*> *noeuds, Node* noeud){
    bool isIn = false;
    int index = -1;
    for(int i = 0; i < noeuds->size(); i++){
        if((*noeuds)[i]->getId() == noeud->getId()){
            isIn = true;
            index = i;
        }
    }
    if(!isIn){
        noeuds->push_back(noeud);
        return noeuds->size() -1;
    }else
        return index;
}
