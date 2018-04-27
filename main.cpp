#include <iostream>
#include "C:\Users\Oana\CLionProjects\untitled16\Proiect.h"
#include <fstream>
using namespace std;

int tranzitii, numar, nr;
char start;

int main() {
    ifstream f("C:\\Users\\Oana\\CLionProjects\\untitled16\\date.in");
    ofstream g("C:\\Users\\Oana\\CLionProjects\\untitled16\\date.out");
    f >> tranzitii >> numar >> start;
    f >> nr;
    Proiect o1(tranzitii, numar, start, nr);
    o1.marcare();
    o1.coada(start);
    return 0;
}
