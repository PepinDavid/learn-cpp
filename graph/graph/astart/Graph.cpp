#include "Graph.h"

Graph::Graph(){
    _root = NULL;
}

Graph::~Graph(){
    for(auto n: _nodes){
        delete n;
    }
}

void Graph::addNode(Node* n){
    bool findIt = false;
    for(auto node: _nodes){
        if(node->getId() == n->getId())
            findIt = true;
    }
    if(!findIt)
        _nodes.push_back(n);
}

Node* Graph::findNode(int id){
    for(auto n: _nodes){
        if(id == n->getId())
            return n;
    }
    return nullptr;
}

Node* Graph::findNode(Node* node){
    for(auto n: _nodes){
        if(node->getId() == n->getId())
            return n;
    }
    return nullptr;
}

int Graph::returnItNodes(int id){
    for(unsigned int i = 0; i < _nodes.size(); i++){
        if(id == (_nodes[i])->getId())
            return i;
    }
    return -1;
}

int Graph::returnItNodes(Node* node){
    for(unsigned int i = 0; i < _nodes.size(); i++){
        if(node->getId() == (_nodes[i])->getId())
            return i;
    }
    return -1;
}

std::vector<Node*> Graph::getNodes(){
    return _nodes;
}

std::vector<Node*> Graph::findLeafs(){
    std::vector<Node*> v;
    for(auto n: _nodes){
        if(n->sizeChildren() < 1)
            v.push_back(n);
    }
    return v;
}

std::vector<Node*> Graph::findRoot(){
    std::vector<Node*> v;
    for(auto n: _nodes){
        if(n->sizeParents() < 1)
            v.push_back(n);
    }
    return v;
}

int Graph::sumNodes(){
    return _nodes.size();
}


/* Affiche le chemin menant de src à dest */
void Graph::print_path(int src, int dest, std::vector<int> children){
   if(src == dest)
       printf("%d", src);
   else if(children[dest] == NIL)
       printf("Il n'y a pas de chemin de %d vers %d", src, dest);
   else{
       print_path(src, children[dest], children);
       printf(" %d", dest);
   }
}

void Graph::bfs(int src){ //src node->getId()
    int max =  _nodes.size(); //nombre de noeuds

    std::vector<int> color(max+1); //Tableau pour marquer les couleurs
    std::vector<int> dist(max+1); //Tableau pour calculer les distances
    std::vector<int> children(max+1); //Tableau pour marquer les enfants

    std::list<int> graph[max+1]; //list contenant les id des noeuds (int)

    int n = max+1;
    //convertion du vector de ptr de noeuds en list
    while(n-- > 1){
        Node * node = (*this).findNode(n);

        graph[node->getId()]; //on insert le noeud
        for(auto child: node->getChildren()){//pour tout les enfants
            graph[node->getId()].push_front(child->getId()); // node est connecté à child ...
            graph[child->getId()].push_front(node->getId()); // et child aussi est connecté à node
        }
    }

    for(int i = 0; i < max; i++){
        color[i] = WHITE; //on colorie tous les noeuds en blanc
        dist[i] = INF; //on affecte INF à la distance de chaque noeud
        children[i] = NIL; //on affecte NIL au enfant de chaque noeud
    }

    color[src] = GREY; //on colorie la source en gris, on vient de le découvrir
    dist[src] = 0; //Puisque c'est le premier noeud découvert, sa distance est 0
    children[src] = NIL; //La source n'a pas de parent

    std::queue<int> q;
    q.push(src); // on insere notre source en tete de queue

    while(!q.empty()){
        int u = q.front(); //on récupere le noeud en tête de queue
        q.pop(); //on défile la queue
        //on parcourt la liste des adjacents(enfants)
        for(std::list<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++){
            int v = *it;
            if(color[v] == WHITE){ //Si c'est la premiere fois qu'on découvre v
                color[v] = GREY; //on le marque comme deja découvert
                dist[v] = dist[u] + 1; //on calcule la distance avec la source
                children[v] = u; //on affecte a son enfant u

                q.push(v); //on insere v a la tete de la file
            }
        }
        color[u] = BLACK;
    }

    for(unsigned int i = 1; i <= _nodes.size(); ++i){
        printf("Chemin de %d vers %d : ", src, i);
        print_path(src, i, children);
        printf("\n");
    }

    return ;
}

void Graph::bfsReelDist(int src){ //src node->getId()
    int max =  _nodes.size(); //nombre de noeuds

    std::vector<int> color(max+1); //Tableau pour marquer les couleurs
    std::vector<int> dist(max+1); //Tableau pour calculer les distances
    std::vector<int> children(max+1); //Tableau pour marquer les enfants

    std::list<int> graph[max+1]; //list contenant les id des noeuds (int)

    int n = max+1;
    //convertion du vector de ptr de noeuds en list
    while(n-- > 1){
        Node * node = (*this).findNode(n);

        graph[node->getId()]; //on insert le noeud
        for(auto child: node->getChildren()){//pour tout les enfants
            graph[node->getId()].push_front(child->getId()); // node est connecté à child ...
            graph[child->getId()].push_front(node->getId()); // et child aussi est connecté à node
        }
    }

    for(int i = 0; i < max; i++){
        color[i] = WHITE; //on colorie tous les noeuds en blanc
        dist[i] = INF; //on affecte INF à la distance de chaque noeud
        children[i] = NIL; //on affecte NIL au enfant de chaque noeud
    }

    color[src] = GREY; //on colorie la source en gris, on vient de le découvrir
    dist[src] = 0; //Puisque c'est le premier noeud découvert, sa distance est 0
    children[src] = NIL; //La source n'a pas de parent

    std::queue<int> q;
    q.push(src); // on insere notre sourceen tete de queue

    while(!q.empty()){
        int u = q.front(); //on récupere le noeud en tête de queue
        q.pop(); //on défile la queue
        Node *n1 = (*this).findNode(u);
        //on parcourt la liste des adjacents(enfants)
        for(std::list<int>::iterator it = graph[u].begin(); it != graph[u].end(); it++){
            int v = *it;
            if(color[v] == WHITE){ //Si c'est la premiere fois qu'on découvre v
                color[v] = GREY; //on le marque comme deja découvert
                dist[v] = dist[u] + n1->distance((*this).findNode(v)); //on calcule la distance entre u et v
                printf("id %d -> %d et dist: %d \n",u,v,dist[v]);
                children[v] = u; //on affecte a son enfant u

                q.push(v); //on insere v a la tete de la file
            }
        }
        color[u] = BLACK;
    }

    for(unsigned int i = 1; i <= _nodes.size(); ++i){
        printf("Chemin de %d vers %d : ", src, i);
        print_path(src, i, children);
        printf("\n");
    }

    return ;
}

void Graph::parcoursProfondeur(){

}

void Graph::plusCourtChemin(int idDep, int idArr){

}
