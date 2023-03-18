//
// Created by culbec on 3/12/23.
//
#include "service.h"

#ifndef LAB2_4_OOP_UI_H
#define LAB2_4_OOP_UI_H

typedef struct {
	ServiceCheltuieli serviceCheltuieli;
}UI;

// constructor + destructor
UI creeaza_ui();
void distruge_ui(UI*);

// afisare cheltuieli
void ui_afiseaza_cheltuieli(UI*);

// adaugare + modificare + stergere
void ui_adaugare_cheltuiala(UI*);
void ui_modificare_cheltuiala(UI*);
void ui_sterge_cheltuiala(UI*);

// filtrarile + ordonare;
void ui_filtrare(UI*);
void ui_ordonare(UI*);

void show_ui();

#endif //LAB2_4_OOP_UI_H
