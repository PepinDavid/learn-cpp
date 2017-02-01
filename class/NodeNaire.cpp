//exercice C.I.G moyen

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int id;
    int nbParents = 0;
    int nbChildren = 0;
    vector<node *> parents;
    vector<node *> children;

};
unsigned max(unsigned a,unsigned b)
{
    return (a>b)? a : b ;
}
class Tree{
    protected:
        node * root;
    public:
        Tree();
        Tree(int id);
        ~Tree();
        void insert(int parentKey, int childKey);
        node *search(int key);
        int height();
    private:
        void insert(int parentKey, int childKey, node *leaf);
        void insert(int childKey, node *leaf);
        node *search(int key, node *leaf);
        node *isRoot(node *leaf);
        int height(node *leaf, string r = "root ");
        int isLeaf(node *leaf);
};

Tree::Tree(){
    root = NULL;
};
Tree::Tree(int id){
    root->id = id;
};
void Tree::insert(int parentKey, int childKey){
    if(root == NULL){
        root = new node;
        root->id = parentKey;       
        insert(childKey, root);
    }else{
        insert(parentKey, childKey, root);
    }
};
void Tree::insert(int parentKey, int childKey, node *leaf){
    node *_p = search(parentKey);
    node *_c = search(childKey);
    if(_p != NULL){
        if(_c == NULL){
            insert(childKey, _p);
        }else{
            if(search(_p->id, _c) == NULL){
                _c->nbParents++;
                _c->parents.push_back(_p);
            }
            if(search(_c->id, _p) == NULL){
                _p->nbChildren++;
                _p->children.push_back(_c);
            }
        }
    }else{
        if(_c != NULL){
            _p = new node;
            _p->id = parentKey;
            _p->nbChildren = 1;
            _p->children.push_back(_c);
    
            _c->nbParents++;
            _c->parents.push_back(_p);
        }else{
            _p = new node;
            _p->id = parentKey;
            _p->nbChildren = 1;
            _c = new node;
            _c->id = parentKey;
            _c->nbParents = 1;
            _p->children.push_back(_c);
            _c->parents.push_back(_p);
        }
    }
};
void Tree::insert(int childKey, node *leaf){
    node * child = new node;
    child->id = childKey;
    child->nbParents = 1;
    child->parents.push_back(leaf);
    
    leaf->nbChildren++;
    leaf->children.push_back(child);
};
node * Tree::search(int key){
    node * r = isRoot(root);
    return search(key, r);
}
node * Tree::search(int key, node *leaf){
    cerr << "key search " << key << " leaf id " << leaf->id << " leaf ptr " << leaf << endl;
    if(leaf == NULL)
        return NULL;
    if(leaf->id == key)
        return leaf;
    for(int i = 0; i < leaf->nbChildren; i++){
        node * pTarget = search(key, leaf->children[i]);
        if(pTarget != NULL)
            return pTarget;
    }
    return NULL;
}
node * Tree::isRoot(node *leaf){
    if(leaf == NULL)
        return NULL;
    if(leaf->nbParents < 1)
        return leaf;
    for(int i = 0; i < leaf->nbParents; i++){
        node * pTarget = isRoot(leaf->parents[i]);
        if(pTarget != NULL)
            return pTarget;
    }
    return NULL;
}
int Tree::height(){
    node * r = isRoot(root);
    string s = "racine ";
    return height(r, s);
}
int Tree::height(node *leaf, string r){
    r += to_string(leaf->id);
    cerr << r << endl;
    r += " --| ";
    if(leaf->nbChildren < 1){
        return 1;
    }else{
        int maxDepth = 0;
        for(int i = 0; i < leaf->nbChildren; i++){
            maxDepth = max(maxDepth, height(leaf->children[i]));
        }
        return maxDepth+1;
    }
}
int Tree::isLeaf(node * leaf){
    if(leaf->nbChildren < 1)
        return 0;
    return 1;
}
int main()
{
    int n; // the number of relationships of influence
    cin >> n; cin.ignore();
    Tree * tree = new Tree();
    
    for (int i = 0; i < n; i++) {
        int x; // a relationship of influence between two people (x influences y)
        int y;
        cin >> x >> y; cin.ignore();
        cerr << " x : " << x << " child y " << y << endl;
        tree->insert(x,y);
    }
    // The number of people involved in the longest succession of influences
    cout << tree->height() << endl;
}