//exercice C.I.G moyen

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node * Tree;

unsigned max(unsigned a,unsigned b)
{
	return (a>b)? a : b ;
}

class Node{
    protected:
    Node * m_parent;
    Node * m_nextRight;
    Node * m_nextLeft;
    int m_id;
    public:
    Node(){
        m_parent = NULL;
        m_nextRight = NULL;
        m_nextLeft = NULL;
    };
    Node(int id){
        m_id = id;
        m_parent = NULL;
        m_nextRight = NULL;
        m_nextLeft = NULL;
    };
    ~Node(){
        delete m_parent;
        delete m_nextLeft;
        delete m_nextRight;
    };
    int getId(){
        return m_id;
    };
    Node *getParent(){
        return m_parent;
    };
    Node * getRight(){
            return m_nextRight;
    };
    Node * getLeft(){
        return m_nextLeft;
    };
    Node *isRacine(){
        return isRacine(this);
    };
    void * setRight(Node * n){
        m_nextRight = n;
    };
    void setLeft(Node * n){
        m_nextLeft = n;
    };
    void setId(int id){
        m_id = id;
    };
    Node *search(int val){
        return search(val, this);
    };    
    void insert(int parentVal, int childVal){
        Node * n = isRacine()->search(parentVal);
        Node * c = isRacine()->search(childVal);
        cerr << n << " " << c << endl;
        if(c == NULL && n != NULL){
            n->insert(childVal);
        }else if(c != NULL && n == NULL){
            n = new Node(parentVal);
            n->insert(c);
        }else if(c != NULL && n != NULL){
            n->insert(c);
        }else{
            cerr << "une erreur est là : " << parentVal << " et " << childVal << endl;
        }
    };
    int height(){
        return height(this);
    }
    void draw (Node * T, string r = "[0]"){
        cerr << r << T->getId() << endl;
        if(T->getLeft() != NULL)
            draw(T->getLeft(), r + "L|");
        if(T->getRight() != NULL)
            draw(T->getRight(), r + "R|");
    }
    private:
    Node *isRacine(Tree T){
        if(T->getParent() == NULL)
            return T;
        else{
            return isRacine(T->getParent());
        }
            
    };
    Node *search(int val, Tree T){
        if(T == NULL)
            return NULL;
        if(T->getId() == val)
            return T;
        Node * pTarget = search(val, T->getLeft());
        if(pTarget == NULL)
            pTarget = search(val, T->getRight());

        return pTarget;
    };
    void insert(int childVal){
        Node * n = new Node(childVal);
        if(m_nextLeft == NULL){
            m_nextLeft = n;
            m_nextLeft->setParent(this);
        }else if(m_nextRight == NULL){
            m_nextRight = n;
            m_nextRight->setParent(this);    
        }else{
            cerr << "           C'est tout rempli !!! " << endl;
        }        
    };
    void insert(Node * childVal){
        if(m_nextLeft == NULL){
            m_nextLeft = childVal;
            m_nextLeft->setParent(this);
        }else if(m_nextRight == NULL){
            m_nextRight = childVal;
            m_nextRight->setParent(this);
        }else{
            cerr << "           C'est tout rempli !!! " << endl;
        }   
    };
    void setParent(Tree T){
        m_parent = T;
    };
    int height(Tree T){
        if(T == NULL)
            return 0;
        else
            return 1 + max(height(T->getLeft()), height(T->getRight()));
    }
};

int main()
{
    int n; // the number of relationships of influence
    cin >> n; cin.ignore();
    Node * noeuds = new Node();
    
    for (int i = 0; i < n; i++) {
        int x; // a relationship of influence between two people (x influences y)
        int y;
        cin >> x >> y; cin.ignore();
        cerr << " x : " << x << " child y " << y << endl;
        if(i == 0)
            noeuds->setId(x);
        noeuds->insert(x, y);
    }
    noeuds->draw(noeuds->isRacine());
    // The number of people involved in the longest succession of influences
    cout << noeuds->isRacine()->height() << endl;
}