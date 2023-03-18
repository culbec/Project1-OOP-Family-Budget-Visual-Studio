//
// Created by culbec on 3/12/23.
//

#include <string.h>
#include "../headers/domain.h"

// implementarile functiilor ce apartin domeniului

Cheltuiala creeaza_cheltuiala(int ziua, double suma, char* tip) {
    /*
     * Creeaza o cheltuiala si o returneaza
     * @param ziua: ziua cheltuielii
     * @param suma: suma cheltuielii
     * @param tip: tipul cheltuielii
     * @pre: -
     * @post: cheltuiala.ziua = ziua; cheltuiala.suma = suma; cheltuiala.tip = tip
     */
    Cheltuiala cheltuiala;
    cheltuiala.ziua = ziua;
    cheltuiala.suma = suma;
    strcpy_s(cheltuiala.tip, 51, tip);
    return cheltuiala;
}

void distruge_cheltuiala(Cheltuiala* ptr_cheltuiala) {
    /*
     * 'Distruge' cheltuiala
     * @pre: ptr_cheltuiala -> pointer spre o cheltuiala
     * @post: se distruge cheltuiala
     */
    ptr_cheltuiala->ziua = -1;
    ptr_cheltuiala->suma = -1;
    strcpy_s(ptr_cheltuiala->tip, 51, "");
}

int get_ziua(Cheltuiala* ptr_cheltuiala) {
    /*
     * Returneaza ziua in care s-a efectuat Cheltuiala
     *
     * @pre: parametru primit - de tip Cheltuiala*
     * @post: - (nu se modifica cheltuiala)
     * @return: ziua in care s-a efectuat cheltuiala
    */
    return ptr_cheltuiala->ziua;
}

void set_ziua(Cheltuiala* ptr_cheltuiala, int new_ziua) {
    /*
     * Seteaza ziua cheltuielii pointuita de pointer-ul 'ptr_cheltuiala' la new_ziua
     * @pre: ptr_cheltuiala - pointer catre o Cheltuiala; new_ziua - intreg fara semn
     * @post: ziua cheltuielii = new_ziua
     * @return: -
     */
    ptr_cheltuiala->ziua = new_ziua;
}

double get_suma(Cheltuiala* ptr_cheltuiala) {
    /*
     * Returneaza suma unei cheltuieli
     * @pre: cheltuiala = Cheltuiala
     * @post: -
     * @return: suma cheltuielii
     */
    return ptr_cheltuiala->suma;
}

void set_suma(Cheltuiala* ptr_cheltuiala, double new_suma) {
    /*
     * Seteaza suma cheltuielii la new_suma
     * @pre: ptr_cheltuiala = pointer spre o Cheltuiala; new_suma = suma reala > 0
     * @post: suma cheltuielii = new_suma
     * @return: -
     */
    ptr_cheltuiala->suma = new_suma;
}

char* get_tip(Cheltuiala* cheltuiala) {
    /*
     * Returneaza tipul unei cheltuieli
     * @pre: cheltuiala = Cheltuiala
     * @post: -
     * @return: tipul cheltuielii
     */
     //    char* tip = cheltuiala.tip;
     //    return tip;
    return cheltuiala->tip;
}

void set_tip(Cheltuiala* ptr_cheltuiala, char* new_tip) {
    /*
     * Seteaza tipul cheltuielii la new_tip
     * @pre: ptr_cheltuiala = pointer spre Cheltuiala; new_tip: sir de caractere ce contine tipul cheltuielii
     * @post: tipul cheltuielii = new_tip
     * @return: -
     */
    strcpy_s(ptr_cheltuiala->tip, 51, new_tip);
}

int eq_cheltuieli(Cheltuiala this, Cheltuiala other) {
    /*
     * Verifica daca doua cheltuieli sunt echivalente
     * @pre: this, other = Cheltuiala
     * @post: 1 - cheltuielile sunt echivalente, 0 - altfel
     */
    if (this.ziua != other.ziua)
        return 0;
    if (this.suma != other.suma)
        return 0;
    if (strcmp(this.tip, other.tip) != 0)
        return 0;
    return 1;
}