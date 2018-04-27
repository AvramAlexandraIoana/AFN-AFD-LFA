#include <fstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

ifstream f("C:\\Users\\Oana\\CLionProjects\\untitled20\\date.in");
ofstream g("C:\\Users\\Oana\\CLionProjects\\untitled20\\date.out");

int x, n, t, a[101][101][101], nr, amax, viz[101], m, final[101], b[101][101], finale[101];
/**
 *
 * @param start represent an integer, the initial form  of the AFN
 */
char y, z, in, q[101][101];

void coada(char start) {
    int st = 0, dr = 0, l = 0, linii = 0, noduri = -1;
    char *aux = NULL;
    q[0][0] = start;
    viz[0] = 0;
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

int main() {
    f >> x >> n >> in;
    f >> m;
    for (int i = 0; i < x; i++) {
        f >> y >> z >> t;
        a[y - 'a'][z - 'a'][t] = 1;
    }
    f >> nr;
    for (int i = 0; i < nr; i++) {
        f >> y;
        final[y - 'a'] = 1;
    }
    coada(in);

    return 0;
}
