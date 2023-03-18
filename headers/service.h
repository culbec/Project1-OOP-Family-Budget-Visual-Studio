//
// Created by culbec on 3/12/23.
//
#include "repo.h"

#ifndef LAB2_4_OOP_SERVICE_H
#define LAB2_4_OOP_SERVICE_H

typedef struct {
    Cheltuiala cheltuieli[CAP];
    unsigned int lungime;
}ListaCheltuieli;

typedef struct {
    RepoCheltuieli repoCheltuieli;
} ServiceCheltuieli;

//creeare lista cheltuieli
ListaCheltuieli creeaza_lista_cheltuieli();

//distrugere
void distruge_lista_cheltuieli(ListaCheltuieli*);

// getter lungimea listei de cheltuieli
unsigned int lista_get_lungime(ListaCheltuieli*);

// + settter lungime lista cheltuieli
void lista_set_lungime(ListaCheltuieli*, unsigned int);

//creeare service cheltuieli
ServiceCheltuieli creeaza_service_cheltuieli();

// distrugere
void distruge_service_cheltuieli(ServiceCheltuieli*);

// adaugare + modificare + stergere
int service_adauga_cheltuiala(ServiceCheltuieli*, int, double, char*);

int service_modifica_cheltuiala(ServiceCheltuieli*, int, double, char*, int, double, char*);

int service_sterge_cheltuiala(ServiceCheltuieli*, int, double, char*);

// cautare dupa zi / suma / tip

void filtrare_zi(ServiceCheltuieli*, ListaCheltuieli*, int);

void filtrare_suma(ServiceCheltuieli*, ListaCheltuieli*, double);

void filtrare_tip(ServiceCheltuieli*, ListaCheltuieli*, char*);

// ordonare dupa zi / tip (crescator / descrescator)
void ordonare(ServiceCheltuieli*, ListaCheltuieli*, int, int);

// functie de swap
void swap(Cheltuiala*, Cheltuiala*);

#endif //LAB2_4_OOP_SERVICE_H
