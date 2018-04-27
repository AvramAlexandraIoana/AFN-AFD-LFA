#include <cstring>
#include <iostream>
#include <fstream>
#include "C:\Users\Oana\CLionProjects\untitled16\Proiect.h"
#include <stdlib.h>

using namespace std;

ifstream f("C:\\Users\\Oana\\CLionProjects\\untitled16\\date.in");
ofstream g("C:\\Users\\Oana\\CLionProjects\\untitled16\\date.out");

Proiect::Proiect() {
    n = 0;
    a = NULL;
    final = NULL;
    m = 0;
    x = 0;
    in = NULL;
}

Proiect::Proiect(int num, int a1, char a2, int a3) {
    x = num;
    n = a1;
    a = (int ***) malloc(n * sizeof(int **));
    for (int i = 0; i < n; i++) {
        a[i] = (int **) malloc(n * sizeof(int *));
        for (int j = 0; j < n; j++) {
            a[i][j] = (int *) malloc(n * sizeof(int));
            for (int k = 0; k < n; k++)
                a[i][j][k] = 0;
        }
    }
    final = (int *) malloc(26 * sizeof(int));
    for (int i = 0; i < 26; i++)
        final[i] = 0;
    in = a2;
    m = a3;


}

void Proiect::marcare() {
    char y, z;
    int t, nr;
    int a1, a2, a4;
    char a3;
    f >> a1 >> a2 >> a3;
    f >> a4;
    for (int i = 0; i < x; i++) {
        f >> y >> z >> t;
        a[y - 'a'][z - 'a'][t] = 1;
    }
    f >> nr;
    for (int i = 0; i < nr; i++) {
        f >> y;
        final[y - 'a'] = 1;
    }
    g << nr;
}

/**
 *
 * @param start represent an integer, the initial form  of the AFN
 */

void Proiect::coada(char start) {
    char q[101][101], b[101][101];
    int st = 0, dr = 0, l = 0, linii = 0, noduri = -1, t = 0, nr = 0;
    int viz[101], finale[101];
    char *aux = NULL;
    q[0][0] = start;
    viz[0] = 0;
    if (final[start - 'a'])finale[t++] = 0;
    dr++;
    while (st <= dr) {
        int num = st;
        for (int d = num; d <= dr; d++)
            if (viz[d] == 1) st++;
            else break;
        aux = (char *) malloc(strlen(q[st]));
        strcpy(aux, q[st]);
        noduri++;
        for (int k = 0; k < m; k++) {
            nr = 0;
            int ok2 = 1;
            for (int j = 0; j < strlen(aux); j++)
                for (int i = 0; i < n; i++)
                    if (a[aux[j] - 'a'][i][k]) {
                        int ok = 1;
                        if (final[i] != 0) ok2 = 0;
                        for (int d = 0; d < nr; d++)
                            if (q[dr][d] == i + 'a')ok = 0;
                        if (ok == 1) {
                            q[dr][nr] = i + 'a';
                            nr++;
                        }
                    }
            if (nr) {
                for (int d = 0; d < strlen(q[dr]) - 1; d++)
                    for (int k = d + 1; k < strlen(q[dr]); k++)
                        if (q[dr][d] > q[dr][k]) {
                            char au = q[dr][d];
                            q[dr][d] = q[dr][k];
                            q[dr][k] = au;
                        }
                int ok1 = 1;
                for (int d = 0; d < dr; d++)
                    if (strcmp(q[dr], q[d]) == 0) {
                        ok1 = 0;
                        viz[dr] = 1;
                        break;
                    }
                linii++;
                b[st][dr] = k + 1;
                if (ok2 == 0) {
                    ok1 = 1;
                    for (int d = 0; d < t; d++)
                        if (strcmp(q[finale[d]], q[dr]) == 0) {
                            ok1 = 0;
                            break;
                        }
                    if (ok1 == 1)finale[t++] = dr;
                }
                dr++;
            }

        }
        st++;

    }
    g << linii << " " << noduri << " " << start << '\n';
    g << m << '\n';
    for (int i = 0; i < dr; i++)
        for (int j = 0; j < dr; j++)
            if (b[i][j])g << q[i] << " " << q[j] << " " << b[i][j] - 1 << '\n';
    g << t << '\n';
    for (int i = 0; i < t; i++)
        g << q[finale[i]] << " ";
}


Proiect::~Proiect() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            free(a[i][j]);
        free(a[i]);
    }
    a = NULL;
    n = 0;
    x = 0;
    m = 0;
    in = NULL;
    free(final);
}
