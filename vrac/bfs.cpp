#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

const int INF = 2147483647; // Notre valeur "infini"
const int NIL = -1; // On choisit -1 comme valeur pour NIL
const int N = 10; 
const int MAX = N + 1;

enum {WHITE, GREY, BLACK}; // Une énumération pour les couleurs BLANC, GRIS et NOIR

vector<int> color(MAX); // Tableau pour marquer les couleurs
vector<int> dist(MAX); // Tableau pour calculer les distances
vector<int> parent(MAX); // Tableau pour marquer les parents

//parcours en largeur
void bfs(int src, list<int> graph[])
{
    /* Pour commencer */
    for(int i = 1; i <= N; ++i)
    {
        color[i] = WHITE; // On colorie tous les noeuds en blanc
        dist[i] = INF; // On affecte INF à la distance de chaque noeud
        parent[i] = NIL; // On affecte NIL au parent de chaque noeud
    }

    color[src] = GREY; // On colorie la source en gris, on vient de le découvrir
    dist[src] = 0; // Puisque c'est le 1er noeud découvert, sa distance vaut 0
    parent[src] = NIL; // La source n'a pas de parent

    queue<int> q;
    q.push(src); // On y insère notre source

    while(!q.empty())
    {
        int u = q.front(); // on récupère le noeud en tête de la queue
        q.pop(); // On défile la queue

        /* On parcourt la liste d'adjacence de u */
        for(list<int>::iterator it = graph[u].begin(); it != graph[u].end(); ++it)
        {
            int v = *it; // Simple convénience, on va utiliser v au lieu de *it

            if(color[v] == WHITE) // Si c'est la première fois qu'on découvre v
            {
                 dist[v] = dist[u] + 1; // On calcule sa distance
                 color[v] = GREY; // On le marque comme déjà découvert
                 parent[v] = u; // On affecte à son parent u

                 q.push(v); // On insère v à la tête de la file
            }
        }

        color[u] = BLACK;
    }
}


/* Affiche le chemin menant de src à dest */
void print_path(int src, int dest)
{
   if(src == dest)
       printf("%d", src);
   else if(parent[dest] == NIL)
       printf("Il n'y a pas de chemin de %d vers %d", src, dest);
   else
   {
       print_path(src, parent[dest]);
       printf(" %d", dest);
   }
}


int main()
{
   int n = 0;
   printf("size array for associative node\n");
   scanf("%d", &n);

   list<int> graph[MAX];

   while(n--)
   {
       int u = 0, v = 0;
       printf("write 2 id nodes with space between them.\n Exemple: 112 232\n");
       scanf("%d %d", &u, &v);

       /* Puisque c'est un graphe non orienté, il faut indiquer que ... */
       graph[u].push_front(v); // u est connecté à v ...
       graph[v].push_front(u); // et que v aussi est connecté à u

   }

   int src = 4;
   bfs(src, graph); // On fait le parcours en largeur

   /* Il ne nous reste plus qu'à afficher le chemin menant à chaque noeud */
   for(int i = 2; i <= N; ++i)
   {
       printf("Chemin de %d vers %d : ", src, i);
       print_path(src, i);
       printf("\n");
   }

   return 0;
}
