#include <stdio.h>
#include "Fraction.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream & flux, Fraction const & f)
{
    f.affiche(flux);
    return flux;
}

int main(int argc, char **argv)
{
    Fraction a(1,2), b(12,50), c(-12,50), d(6,-3), e(-1,-2), f;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
    cout << e << endl;
    f = a+b;
    cout << f << endl;
    a += b;
    cout << a << endl;
    cout << a.nombreReel() << endl;
	printf("hello world\n");
	return 0;
}
