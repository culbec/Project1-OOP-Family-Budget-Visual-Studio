//
// Created by culbec on 3/12/23.
//

#ifndef LAB2_4_OOP_DOMAIN_H
#define LAB2_4_OOP_DOMAIN_H

typedef struct {
    int ziua; // ziua in care s-a facut cheltuiala
    double suma; // suma cheltuielii efectuate
    char tip[100]; // tipul unei cheltuieli: 
                   //mancare, transport, telefon&internet, imbracaminte, altele
}Cheltuiala;

// 'constructor' + 'destructor'
Cheltuiala creeaza_cheltuiala(int, double, char*);

void distruge_cheltuiala(Cheltuiala*);

// definim getters + setters

int get_ziua(Cheltuiala*);
void set_ziua(Cheltuiala*, int);

double get_suma(Cheltuiala*);
void set_suma(Cheltuiala*, double);

char* get_tip(Cheltuiala*);
void set_tip(Cheltuiala*, char*);

// functie pentru verificarea daca doua structuri sunt echivalente
int eq_cheltuieli(Cheltuiala, Cheltuiala);

#endif //LAB2_4_OOP_DOMAIN_H