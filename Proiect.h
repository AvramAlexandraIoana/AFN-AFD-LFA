//
// Created by Oana on 4/26/2018.
//

#ifndef UNTITLED16_PROIECT_H
#define UNTITLED16_PROIECT_H

class Proiect {
    int ***a;
    int n;
    int m;
    int x;
    int *final;
    char in;
public:
    Proiect();

    Proiect(int, int, char, int);

    void marcare();

    void coada(char);

    virtual ~Proiect();

protected:
private:
};

#endif //UNTITLED16_PROIECT_H
