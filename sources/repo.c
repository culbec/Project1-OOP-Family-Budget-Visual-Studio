//
// Created by culbec on 3/12/23.
//

#include "../headers/repo.h"

RepoCheltuieli creeaza_repo() {
    /*
     * Creeaza un repo de lungime 0
     * @pre: -
     * @post: repo de lungime 0
     */
    RepoCheltuieli repo_cheltuieli;
    repo_cheltuieli.lungime = 0;
    return repo_cheltuieli;
}

void distruge_repo(RepoCheltuieli* ptr_repo_cheltuieli) {
    /*
     * Distruge repo-ul
     * @pre: ptr_repo_cheltuieli = pointer spre un repo_cheltuieli
     * @post: lungimea repo-ului = 0
     */
    ptr_repo_cheltuieli->lungime = 0;
}

void repo_adaugare_cheltuiala(RepoCheltuieli* ptr_repo_cheltuieli, Cheltuiala cheltuiala) {
    /*
     * Adauga cheltuiala in lista repo-ului de cheltuieli
     * @pre: ptr_repo_cheltuieli = pointer spre repo_cheltuieli; cheltuiala = Cheltuiala
     * @post: cheltuiala este adaugata in lista de cheltuieli
     */
    ptr_repo_cheltuieli->cheltuieli[ptr_repo_cheltuieli->lungime++] = cheltuiala;
}

void repo_modifica_cheltuiala(RepoCheltuieli* ptr_repo_cheltuieli, int index, Cheltuiala cheltuiala) {
    /*
     * Modifica cheltuiala de pe pozitia 'index' cu o alta cheltuiala
     * @pre: ptr_repo_cheltuieli = pointer spre repo_cheltuieli; cheltuiala = Cheltuiala;
     *       index = pozitia cheltuielii de modificat
     * @post: cheltuiala de pe pozitia index = cheltuiala noua
     */
    ptr_repo_cheltuieli->cheltuieli[index] = cheltuiala;
}

void repo_sterge_cheltuiala(RepoCheltuieli* ptr_repo_cheltuieli, int index) {
    /*
     * Sterge cheltuiala de pe pozitia index
     * @pre: ptr_repo_cheltuieli = pointer spre repo_cheltuieli; index = pozitia cheltuielii de sters
     * @post: cheltuiala de pe pozitia index este stearsa; lungime' = lungime - 1
     */
    for (int i = index; i < ptr_repo_cheltuieli->lungime - 1; i++)
        ptr_repo_cheltuieli->cheltuieli[i] = ptr_repo_cheltuieli->cheltuieli[i + 1];
    ptr_repo_cheltuieli->lungime--;
}

int repo_cauta_cheltuiala(RepoCheltuieli* ptr_repo_cheltuieli, Cheltuiala cheltuiala) {
    /*
     * Cauta o cheltuiala in lista de cheltuieli
     * @pre: ptr_repo_cheltuieli = pointer spre un RepoCheltuieli; cheltuiala = Cheltuiala
     * @post: index-ul in lista de cheltuieli a cheltuielii 'cheltuiala'
     */
    for (int i = 0; i < ptr_repo_cheltuieli->lungime; i++)
        if (eq_cheltuieli(ptr_repo_cheltuieli->cheltuieli[i], cheltuiala) == 1)
            return i;
    return -1;
}


Cheltuiala* get_cheltuieli(RepoCheltuieli* ptr_repo_cheltuieli) {
    /*
     * Returneaza cheltuielile unui repo
     * @pre: ptr_repo_cheltuieli = pointer catre RepoCheltuieli
     * @post: cheltuielile acelui repo
     */
    return ptr_repo_cheltuieli->cheltuieli;
}

unsigned int get_lungime(RepoCheltuieli* ptr_repo_cheltuieli) {
    /*
     * Returneaza lungimea listei de cheltuieli a unui repo
     * @pre: ptr_repo_cheltuieli = pointer catre RepoCheltuieli
     * @post: lungimea cheltuielilor aceului repo
     */
    return ptr_repo_cheltuieli->lungime;
}

