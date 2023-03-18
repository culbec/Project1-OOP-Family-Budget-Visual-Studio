//
// Created by culbec on 3/12/23.
//
#include "./domain.h"

#define CAP 100

#ifndef LAB2_4_OOP_REPO_H
#define LAB2_4_OOP_REPO_H

typedef struct {
    unsigned int lungime;
    Cheltuiala cheltuieli[CAP];
}RepoCheltuieli;

// 'constructor' + 'destructor'
RepoCheltuieli creeaza_repo();
void distruge_repo(RepoCheltuieli*);

// adaugare + modificare + stergere cheltuiala

void repo_adaugare_cheltuiala(RepoCheltuieli*, Cheltuiala);

void repo_modifica_cheltuiala(RepoCheltuieli*, int, Cheltuiala);

void repo_sterge_cheltuiala(RepoCheltuieli*, int);

// functie pentru cautarea unei cheltuieli
int repo_cauta_cheltuiala(RepoCheltuieli*, Cheltuiala);

// getter lista de cheltuieli
Cheltuiala* get_cheltuieli(RepoCheltuieli*);

// getter lungime lista de cheltuieli
unsigned int get_lungime(RepoCheltuieli*);

#endif //LAB2_4_OOP_REPO_H
