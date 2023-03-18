//
// Created by culbec on 3/12/23.
//

#include "tests.h"
#include "../headers/domain.h"
#include "../headers/repo.h"
#include "../headers/validator.h"
#include "../headers/service.h"
#include <string.h>
#include <assert.h>

void test_domain() {
    // cheltuiala pe care vom lucra
    Cheltuiala cheltuiala = creeaza_cheltuiala(13, 123.4, "mancare");

    // testam gettere pt aceasta cheltuiala
    assert(get_ziua(&cheltuiala) == 13);
    assert(get_suma(&cheltuiala) == 123.4);
    assert(strcmp(get_tip(&cheltuiala), "mancare") == 0);

    // setam parametrii la alte valori si dupa verificam cu gettere daca s-au setat
    set_ziua(&cheltuiala, 14);
    set_suma(&cheltuiala, 13.1);
    set_tip(&cheltuiala, "altele");

    assert(get_ziua(&cheltuiala) == 14);
    assert(get_suma(&cheltuiala) == 13.1);
    assert(strcmp(get_tip(&cheltuiala), "altele") == 0);

    // verificam daca 2 cheltuieli sunt echivalente
    Cheltuiala cheltuiala_echiv = creeaza_cheltuiala(14, 13.1, "altele");
    assert(eq_cheltuieli(cheltuiala, cheltuiala_echiv) == 1);

    // verificam si ca acest lucru nu este adevarat pentru o cheltuiala neechivalenta
    Cheltuiala cheltuiala_neechiv1 = creeaza_cheltuiala(13, 13.1, "altele");
    Cheltuiala cheltuiala_neechiv2 = creeaza_cheltuiala(14, 11.2, "altele");
    Cheltuiala cheltuiala_neechiv3 = creeaza_cheltuiala(14, 13.1, "mancare");
    Cheltuiala cheltuiala_neechiv4 = creeaza_cheltuiala(2, 0.5, "imbracaminte");

    assert(eq_cheltuieli(cheltuiala, cheltuiala_neechiv1) == 0);
    assert(eq_cheltuieli(cheltuiala, cheltuiala_neechiv2) == 0);
    assert(eq_cheltuieli(cheltuiala, cheltuiala_neechiv3) == 0);
    assert(eq_cheltuieli(cheltuiala, cheltuiala_neechiv4) == 0);

    // distrugem cheltuiala si verificam daca e distrusa
    distruge_cheltuiala(&cheltuiala);

    assert(get_ziua(&cheltuiala) == -1);
    assert(get_suma(&cheltuiala) == -1);
    assert(strcmp(get_tip(&cheltuiala), "") == 0);
}

void test_repo() {
    // repo-ul de cheltuieli
    RepoCheltuieli repoCheltuieli = creeaza_repo();
    assert(sizeof(repoCheltuieli) == sizeof(RepoCheltuieli));

    // initializam cateva cheltuieli
    Cheltuiala cheltuiala1, cheltuiala2, cheltuiala3;
    cheltuiala1 = creeaza_cheltuiala(16, 23.5, "mancare");
    cheltuiala2 = creeaza_cheltuiala(2, 167.8, "altele");
    cheltuiala3 = creeaza_cheltuiala(31, 123.2, "imbracaminte");

    // verificam daca s-a initializat corect repo-ul
    assert(get_lungime(&repoCheltuieli) == 0);

    // adaugam cheltuielile pe parcurs si  verificam daca se actualizeaza lungimea
    repo_adaugare_cheltuiala(&repoCheltuieli, cheltuiala1);
    assert(get_lungime(&repoCheltuieli) == 1);

    repo_adaugare_cheltuiala(&repoCheltuieli, cheltuiala2);
    repo_adaugare_cheltuiala(&repoCheltuieli, cheltuiala3);
    assert(get_lungime(&repoCheltuieli) == 3);

    // cautam o cheltuiala
    assert(repo_cauta_cheltuiala(&repoCheltuieli, cheltuiala1) == 0);
    assert(repo_cauta_cheltuiala(&repoCheltuieli, cheltuiala2) == 1);

    // cream o cheltuiala de modificat
    Cheltuiala cheltuiala_modif = creeaza_cheltuiala(6, 56.78, "transport");
    assert(repo_cauta_cheltuiala(&repoCheltuieli, cheltuiala_modif) == -1);

    repo_modifica_cheltuiala(&repoCheltuieli, 0, cheltuiala_modif);
    assert(eq_cheltuieli(repoCheltuieli.cheltuieli[0], cheltuiala_modif) == 1);

    // verificam getter-ul pentru lista de cheltuieli
    assert(get_cheltuieli(&repoCheltuieli) == repoCheltuieli.cheltuieli);

    // stergem o cheltuiala
    unsigned int lungime = get_lungime(&repoCheltuieli);
    repo_sterge_cheltuiala(&repoCheltuieli, 1);
    assert(lungime == get_lungime(&repoCheltuieli) + 1);

    // distrugem repo-ul si verificam daca s-a distrus
    distruge_repo(&repoCheltuieli);
    assert(get_lungime(&repoCheltuieli) == 0);
}

void test_validator() {
    // cream niste cheltuieli pentru a le putea valida
    Cheltuiala cheltuiala_valida, cheltuiala_invalida1, cheltuiala_invalida2,
        cheltuiala_invalida3, cheltuiala_invalida4;
    cheltuiala_valida = creeaza_cheltuiala(13, 15.6, "mancare");
    cheltuiala_invalida1 = creeaza_cheltuiala(-1, 15.4, "altele");
    cheltuiala_invalida2 = creeaza_cheltuiala(32, 16.7, "imbracaminte");
    cheltuiala_invalida3 = creeaza_cheltuiala(16, -1.35, "int");
    cheltuiala_invalida4 = creeaza_cheltuiala(27, 27.1, "telf");

    // initializem un repo de cheltuieli
    RepoCheltuieli repoCheltuieli = creeaza_repo();

    // validam cheltuielile
    assert(validare_obiect(&cheltuiala_valida, &repoCheltuieli) == 1);
    assert(validare_obiect(&cheltuiala_invalida1, &repoCheltuieli) == 0);
    assert(validare_obiect(&cheltuiala_invalida2, &repoCheltuieli) == 0);
    assert(validare_obiect(&cheltuiala_invalida3, &repoCheltuieli) == 0);
    assert(validare_obiect(&cheltuiala_invalida4, &repoCheltuieli) == 0);

    // adaugam cheltuiala valida pentru a valida si cautarea
    repo_adaugare_cheltuiala(&repoCheltuieli, cheltuiala_valida);
    // verificam daca functioneaza cautarea
    assert(validare_obiect(&cheltuiala_valida, &repoCheltuieli) == 2);
}

void test_service() {
    // initializam service-ul + repo-ul
    ServiceCheltuieli serviceCheltuieli = creeaza_service_cheltuieli();
    assert(sizeof(serviceCheltuieli) == sizeof(ServiceCheltuieli));

    // verificam daca s-a creat repo-ul
    assert(get_lungime(&serviceCheltuieli.repoCheltuieli) == 0);

    // incercam sa adaugam din cheltuieli + verificam daca cheltuielile eronate nu se adauga
    assert(service_adauga_cheltuiala(&serviceCheltuieli, 13, 13.4, "mancare") == 1);
    assert(service_adauga_cheltuiala(&serviceCheltuieli, -1, -1, "internet") == 0);
    assert(service_adauga_cheltuiala(&serviceCheltuieli, 14, -12.1, "altele") == 0);
    assert(service_adauga_cheltuiala(&serviceCheltuieli, 28, 14.5, "manca") == 0);
    assert(service_adauga_cheltuiala(&serviceCheltuieli, 16, 16.7, "imbracaminte") == 1);
    assert(service_adauga_cheltuiala(&serviceCheltuieli, 13, 13.4, "mancare") == 2);

    // verificam daca se modifica cheltuieli
    assert(service_modifica_cheltuiala(&serviceCheltuieli, 13, 13.4, "mancare", 2, 22.3, "altele") == 1);
    assert(service_modifica_cheltuiala(&serviceCheltuieli, 13, 13.4, "mancare", -1, 22.1, "manca") == 0);

    // verificam daca se sterg cheltuieli
    assert(service_sterge_cheltuiala(&serviceCheltuieli, 2, 22.3, "altele") == 1);
    assert(service_sterge_cheltuiala(&serviceCheltuieli, 13, 13.4, "mancare") == 0);

    // initializam o lista de cheltuieli
    ListaCheltuieli listaCheltuieli = creeaza_lista_cheltuieli();

    // filtram dupa zi
    filtrare_zi(&serviceCheltuieli, &listaCheltuieli, 16);
    assert(lista_get_lungime(&listaCheltuieli) == 1);

    // filtram dupa suma
    lista_set_lungime(&listaCheltuieli, 0);
    filtrare_suma(&serviceCheltuieli, &listaCheltuieli, 16.7);
    assert(lista_get_lungime(&listaCheltuieli) == 1);

    // filtram dupa tip
    lista_set_lungime(&listaCheltuieli, 0);
    service_adauga_cheltuiala(&serviceCheltuieli, 13, 13.4, "imbracaminte");
    filtrare_tip(&serviceCheltuieli, &listaCheltuieli, "imbracaminte");
    assert(lista_get_lungime(&listaCheltuieli) == 2);

    // TESTE SORTARE

    // alta verificare pt. ordonare
    serviceCheltuieli = creeaza_service_cheltuieli();
    Cheltuiala chelt1, chelt2, chelt3, chelt4;
    chelt1 = creeaza_cheltuiala(2, 15.6, "imbracaminte");
    chelt2 = creeaza_cheltuiala(16, 200.3, "altele");
    chelt3 = creeaza_cheltuiala(30, 1000.4, "telefon&internet");
    chelt4 = creeaza_cheltuiala(1, 2.3, "mancare");
    service_adauga_cheltuiala(&serviceCheltuieli, 2, 15.6, "imbracaminte");
    service_adauga_cheltuiala(&serviceCheltuieli, 16, 200.3, "altele");
    service_adauga_cheltuiala(&serviceCheltuieli, 30, 1000.4, "telefon&internet");
    service_adauga_cheltuiala(&serviceCheltuieli, 1, 2.3, "mancare");

    // ordonare dupa zi crescator
    lista_set_lungime(&listaCheltuieli, 0);
    ordonare(&serviceCheltuieli, &listaCheltuieli, 1, 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[0], chelt4) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[1], chelt1) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[2], chelt2) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[3], chelt3) == 1);

    // ordonare dupa zi descrescator
    lista_set_lungime(&listaCheltuieli, 0);
    ordonare(&serviceCheltuieli, &listaCheltuieli, 1, 2);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[0], chelt3) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[1], chelt2) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[2], chelt1) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[3], chelt4) == 1);

    // ordonare dupa tip crescator
    lista_set_lungime(&listaCheltuieli, 0);
    ordonare(&serviceCheltuieli, &listaCheltuieli, 2, 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[0], chelt2) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[1], chelt1) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[2], chelt4) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[3], chelt3) == 1);

    // ordonare dupa tip descrescator
    lista_set_lungime(&listaCheltuieli, 0);
    ordonare(&serviceCheltuieli, &listaCheltuieli, 2, 2);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[0], chelt3) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[1], chelt4) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[2], chelt1) == 1);
    assert(eq_cheltuieli(listaCheltuieli.cheltuieli[3], chelt2) == 1);

    // distrugem service-ul si verificam daca s-a distrus
    distruge_service_cheltuieli(&serviceCheltuieli);
    assert(get_lungime(&serviceCheltuieli.repoCheltuieli) == 0);

    // verificam functia de swap
    Cheltuiala chelt_swp1, chelt_swp2;
    chelt_swp1 = creeaza_cheltuiala(5, 14.3, "mancare");
    chelt_swp2 = creeaza_cheltuiala(7, 199.3, "altele");

    Cheltuiala chelt_swp1_cp = chelt_swp1, chelt_swp2_cp = chelt_swp2;
    swap(&chelt_swp1, &chelt_swp2);
    assert(eq_cheltuieli(chelt_swp1, chelt_swp2_cp) == 1 && eq_cheltuieli(chelt_swp2, chelt_swp1_cp) == 1);

    // verificam daca se distruge lista de cheltuieli
    distruge_lista_cheltuieli(&listaCheltuieli);
    assert(lista_get_lungime(&listaCheltuieli) == 0);
}