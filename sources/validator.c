//
// Created by culbec on 3/12/23.
//

#include "../headers/domain.h"
#include "../headers/validator.h"
#include "../headers/repo.h"
#include <string.h>

int validare_obiect(Cheltuiala* ptr_cheltuiala, RepoCheltuieli* ptr_repo_cheltuieli) {
    /*
     * Valideaza o cheltuiala.
     * @ptr_cheltuiala: pointer spre o Cheltuiala
     * @ptr_repo_cheltuieli: pointer spre repo-ul de cheltuieli
     * @pre: - ptr_cheltuiala -> pointer spre o cheltuiala
     *       - ptr_repo_cheltuieli -> pointer spre un RepoCheltuieli
     * @post: - 0: obiect invalid;
     *        - 1: obiect valid;
     *        - 2: obiect se afla deja in lista de cheltuieli
     */
    const char* cheltuieli[][50] = { "mancare", "transport", "telefon&internet", "imbracaminte"
                              ,"altele" };

    if (ptr_cheltuiala->ziua <= 0 || ptr_cheltuiala->ziua > 31)
        return 0; // zi invalida
    if (ptr_cheltuiala->suma <= 0)
        return 0; // suma invalida

    int cheltuiala_ok = 0;
    for (int i = 0; i < 5 && cheltuiala_ok == 0; i++)
        if (strcmp(ptr_cheltuiala->tip, cheltuieli[0][i]) == 0)
            cheltuiala_ok = 1;
    if (cheltuiala_ok == 0)
        return 0; // tip invalid
    if (repo_cauta_cheltuiala(ptr_repo_cheltuieli, *ptr_cheltuiala) != -1)
        return 2; // obiectul deja exista

    return 1; // obiect valid
}
