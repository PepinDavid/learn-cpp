#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/******************

83% de réussite, pas fini
***************/

//structure position des maisons
struct home{
    int x;
    int y;
};
//calcule de la moyenne des points sur Y
double getAvgY(home * h, int& N){
    double avgY = 0.0;
    for (int i = 0; i < N; i++) {
        avgY += h[i].y;
    }
    cerr << "avgY " << avgY << endl;
    cerr << "avgY/N " << avgY/N << endl;
    return avgY/N;
}
long bestLengthY(home * h, int& N, double& avg){
    long lengthMin = 0;
    long lengthMax = 0;
    long lengthMid = 0;
    for (int i = 0; i < N; i++) {
        lengthMin += abs(h[i].y - (avg-1));
        lengthMid += abs(h[i].y - avg);
        lengthMax += abs(h[i].y - (avg+1));
    }
    cerr << "lengthMin " << lengthMin << endl;
    cerr << "lengthMid " << lengthMid << endl;
    cerr << "lengthMax " << lengthMax << endl;
    return  min(min(lengthMax, lengthMin),lengthMid);
}
int main()
{
    int N;
    int total = 0;
    cin >> N; cin.ignore();
    home * h = new home[N];
    for (int i = 0; i < N; i++) {
        int X;
        int Y;
        cin >> X >> Y; cin.ignore();
        h[i].x = X;
        h[i].y = Y;
    }
    //recherche du max et min X pour la difference pour la distance
    //du cable sur l'axe X
    int minX = h[0].x;
    int maxX = h[0].x;
    for(int i = 1; i < N ; i++){
        if(minX > h[i].x)
            minX = h[i].x;
        if(maxX < h[i].x)
            maxX = h[i].x;
    }
    cerr << minX << endl;
    cerr << maxX << endl;
    //calcule de la moyenne des cables sur Y
    double avg = floor(getAvgY(h, N));
    cerr << avg << endl;
    //calcule de plusieurs longueur possible
    //le nombre en sorti devant etre un entier
    //et la moyenne est un double on prend donc
    //plusieurs possibilité a +/- 1
    long lengthMin = bestLengthY(h, N, avg);
    cout << (maxX-minX)+lengthMin << endl;
}