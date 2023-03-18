//
// Created by culbec on 3/12/23.
//

#include "../headers/service.h"
#include "../headers/validator.h"
#include <string.h>

ListaCheltuieli creeaza_lista_cheltuieli() {
    /*
     * Creeaza o lista de cheltuieli
     * @pre: -
     * @post: o lista de cheltuieli goala
     */
    ListaCheltuieli listaCheltuieli;
    listaCheltuieli.lungime = 0;
    return listaCheltuieli;
}

void distruge_lista_cheltuieli(ListaCheltuieli* ptr_lista_cheltuieli) {
    /*
     * Distruge lista de cheltuieli
     * @pre: ptr_lista_cheltuieli -> pointer spre lista de cheltuieli
     * @post: lista de cheltuieli este 'distrusa'
     */
    ptr_lista_cheltuieli->lungime = 0;
}

unsigned int lista_get_lungime(ListaCheltuieli* ptr_lista_cheltuieli) {
    /*
     * Returneaza lungimea unei liste de cheltuieli
     * @pre: ptr_lista_cheltuieli -> pointer spre o lista de cheltuieli
     * @post: lungimea listei de cheltuieli
     */
    return ptr_lista_cheltuieli->lungime;
}

void lista_set_lungime(ListaCheltuieli* ptr_lista_cheltuieli, unsigned int new_lungime) {
    /*
     * Seteaza lungimea listei de cheltuieli la new_lungime
     * @pre ptr_lista_cheltuieli -> pointer spre ListaCheltuieli, new_lungime -> lungimea noua(intreg fara semn)
     * @post: ptr_lista_cheltuieli.lungime = new_lungime
     */
    ptr_lista_cheltuieli->lungime = new_lungime;
}

ServiceCheltuieli creeaza_service_cheltuieli() {
    /*
     * Creeaza un service de cheltuieli
     * @pre: -
     * @post: un service de cheltuieli
     */
    ServiceCheltuieli serviceCheltuieli;
    serviceCheltuieli.repoCheltuieli = creeaza_repo();
    return serviceCheltuieli;
}

void distruge_service_cheltuieli(ServiceCheltuieli* ptr_service_cheltuieli) {
    /*
     * Distruge service-ul de cheltuieli
     * @pre: ptr_service_cheltuieli -> pointer spre service cheltuieli
     * @post: service cheltuieli este distrus
     */
    distruge_repo(&ptr_service_cheltuieli->repoCheltuieli);
}

int service_adauga_cheltuiala(ServiceCheltuieli* ptr_service_chetuieli, int ziua, double suma, char* tip) {
    /*
     * Incearca sa adauge cheltuiala cu proprietatile 'ziua', 'suma', 'tip'
     * @ziua: ziua unei cheltuieli
     * @suma: suma unei cheltuieli
     * @tip: tipul unei cheltuieli
     * @pre: -
     * @post: adaugarea(sau nu) a cheltuielii:
     *        - 0: nu s-a adaugat;
     *        - 1: s-a adaugat;
     *        - 2: exista deja
     */
    Cheltuiala cheltuiala;
    cheltuiala.ziua = ziua;
    cheltuiala.suma = suma;
    strcpy_s(cheltuiala.tip, 51, tip);

    if (validare_obiect(&cheltuiala, &ptr_service_chetuieli->repoCheltuieli) == 0)
        return 0;
    if (validare_obiect(&cheltuiala, &ptr_service_chetuieli->repoCheltuieli) == 2)
        return 2;

    repo_adaugare_cheltuiala(&ptr_service_chetuieli->repoCheltuieli, cheltuiala);
    return 1;
}

int service_modifica_cheltuiala(ServiceCheltuieli* ptr_service_cheltuieli, int ziua, double suma, char* tip,
    int new_ziua, double new_suma, char* new_tip) {
    /*
     * Incearca sa modifice o cheltuiala primita ca parametru
     * @cheltuiala -> cheltuiala de modificat
     * @new_ziua -> ziua noua
     * @new_suma -> suma noua
     * @new_tip -> tipul nou
     * @pre: cheltuiala -> o Cheltuiala valida
     * @post: - 0: cheltuiala nu s-a modificat
     *        - 1: cheltuiala s-a modificat
     */
    Cheltuiala cheltuiala;
    cheltuiala.ziua = ziua; cheltuiala.suma = suma; strcpy_s(cheltuiala.tip, 51, tip);
    int index = repo_cauta_cheltuiala(&ptr_service_cheltuieli->repoCheltuieli, cheltuiala);
    if (index == -1)
        return 0;

    Cheltuiala new_cheltuiala;
    new_cheltuiala.ziua = new_ziua;
    new_cheltuiala.suma = new_suma;
    strcpy_s(new_cheltuiala.tip, 51, new_tip);
    validare_obiect(&cheltuiala, &ptr_service_cheltuieli->repoCheltuieli);

    repo_modifica_cheltuiala(&ptr_service_cheltuieli->repoCheltuieli, index, new_cheltuiala);
    return 1;
}

int service_sterge_cheltuiala(ServiceCheltuieli* ptr_service_cheltuieli, int ziua, double suma, char* tip) {
    /*
     * Incearca sa stearga o cheltuiala primita ca parametru
     * @cheltuiala -> cheltuiala de modificat
     * @pre: cheltuiala -> o Cheltuiala valida
     * @post: - 0: cheltuiala nu s-a sters
     *        - 1: cheltuiala nu s-a sters
     */
    Cheltuiala cheltuiala;
    cheltuiala.ziua = ziua; cheltuiala.suma = suma; strcpy_s(cheltuiala.tip, 51, tip);
    int index = repo_cauta_cheltuiala(&ptr_service_cheltuieli->repoCheltuieli, cheltuiala);
    if (index == -1)
        return 0;

    repo_sterge_cheltuiala(&ptr_service_cheltuieli->repoCheltuieli, index);
    return 1;
}

void filtrare_zi(ServiceCheltuieli* ptr_service_cheltuieli, ListaCheltuieli* listaCheltuieli, int ziua) {
    /*
     * Returneaza un pointer spre lista de cheltuieli filtrata dupa ziua 'ziua'
     * @pre: ziua: o zi valida;
     * @post: lista cu aceste cheltuieli
     */
    for (int i = 0; i < ptr_service_cheltuieli->repoCheltuieli.lungime; i++)
        if (ptr_service_cheltuieli->repoCheltuieli.cheltuieli[i].ziua == ziua)
            listaCheltuieli->cheltuieli[listaCheltuieli->lungime++] =
            ptr_service_cheltuieli->repoCheltuieli.cheltuieli[i];
}

void filtrare_suma(ServiceCheltuieli* ptr_service_cheltuieli, ListaCheltuieli* listaCheltuieli, double suma) {
    /*
     * Returneaza un pointer spre lista de cheltuieli filtrata dupa suma 'suma'
     * @pre: suma: o suma valida;
     * @post: lista cu aceste cheltuieli
     */
    for (int i = 0; i < ptr_service_cheltuieli->repoCheltuieli.lungime; i++)
        if (ptr_service_cheltuieli->repoCheltuieli.cheltuieli[i].suma == suma)
            listaCheltuieli->cheltuieli[listaCheltuieli->lungime++] =
            ptr_service_cheltuieli->repoCheltuieli.cheltuieli[i];
}

void filtrare_tip(ServiceCheltuieli* ptr_service_cheltuieli, ListaCheltuieli* listaCheltuieli, char* tip) {
    /*
     * Returneaza un pointer spre lista de cheltuieli filtrata dupa tipul 'tip'
     * @pre: ziua: o zi valida;
     * @post: lista cu acele cheltuieli
     */
    for (int i = 0; i < ptr_service_cheltuieli->repoCheltuieli.lungime; i++)
        if (strcmp(ptr_service_cheltuieli->repoCheltuieli.cheltuieli[i].tip, tip) == 0)
            listaCheltuieli->cheltuieli[listaCheltuieli->lungime++] =
            ptr_service_cheltuieli->repoCheltuieli.cheltuieli[i];
}

void swap(Cheltuiala* this, Cheltuiala* other) {
    /*
     * Interschimba 2 cheltuieli
     * @pre: this, other -> pointer catre cheltuieli
     * @post: this = other && other = this
     */
    Cheltuiala temp = *this;
    *this = *other;
    *other = temp;
}

void ordonare(ServiceCheltuieli* ptr_service_cheltuieli, ListaCheltuieli* ptr_lista_cheltuieli, int opt_sort,
    int optiune) {
    /*
     * Sorteaza lista crescator/descrescator dupa optiune
     * @pre: ptr_service_cheltuieli -> ServiceCheltuieli; opt_sort = 1 - zi; 2 - tip
     *       optiune: 1 - crescator, 2 - descrescator
     * @post: lista de cheltuieli ordonate dupa zi
     */
    for (int i = 0; i < ptr_service_cheltuieli->repoCheltuieli.lungime; i++)
        ptr_lista_cheltuieli->cheltuieli[ptr_lista_cheltuieli->lungime++] =
        ptr_service_cheltuieli->repoCheltuieli.cheltuieli[i];
    if (opt_sort == 1) {
        if (optiune == 1) {
            for (int i = 0; i < ptr_lista_cheltuieli->lungime - 1; i++)
                for (int j = i + 1; j < ptr_lista_cheltuieli->lungime; j++)
                    if (ptr_lista_cheltuieli->cheltuieli[i].ziua > ptr_lista_cheltuieli->cheltuieli[j].ziua)
                        swap(&ptr_lista_cheltuieli->cheltuieli[i], &ptr_lista_cheltuieli->cheltuieli[j]);
        }
        else {
            for (int i = 0; i < ptr_lista_cheltuieli->lungime - 1; i++)
                for (int j = i + 1; j < ptr_lista_cheltuieli->lungime; j++)
                    if (ptr_lista_cheltuieli->cheltuieli[i].ziua < ptr_lista_cheltuieli->cheltuieli[j].ziua)
                        swap(&ptr_lista_cheltuieli->cheltuieli[i], &ptr_lista_cheltuieli->cheltuieli[j]);
        }
    }
    else {
        if (optiune == 1) {
            for (int i = 0; i < ptr_lista_cheltuieli->lungime - 1; i++)
                for (int j = i + 1; j < ptr_lista_cheltuieli->lungime; j++)
                    if (strcmp(ptr_lista_cheltuieli->cheltuieli[i].tip, ptr_lista_cheltuieli->cheltuieli[j].tip) > 0)
                        swap(&ptr_lista_cheltuieli->cheltuieli[i], &ptr_lista_cheltuieli->cheltuieli[j]);
        }
        else {
            for (int i = 0; i < ptr_lista_cheltuieli->lungime - 1; i++)
                for (int j = i + 1; j < ptr_lista_cheltuieli->lungime; j++)
                    if (strcmp(ptr_lista_cheltuieli->cheltuieli[i].tip, ptr_lista_cheltuieli->cheltuieli[j].tip) < 0)
                        swap(&ptr_lista_cheltuieli->cheltuieli[i], &ptr_lista_cheltuieli->cheltuieli[j]);
        }
    }
}