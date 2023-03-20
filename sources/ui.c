////
//// Created by culbec on 3/12/23.
////
//
//#include <stdio.h>
//#include "../headers/ui.h"
//
//UI creeaza_ui() {
//    UI ui;
//    ui.serviceCheltuieli = creeaza_service_cheltuieli();
//    return ui;
//}
//
//void distruge_ui(UI* ptr_ui) {
//    // distruge ui-ul
//    distruge_service_cheltuieli(&ptr_ui->serviceCheltuieli);
//}
//
//void ui_afiseaza_cheltuieli(UI* ptr_ui) {
//    // afiseaza cheltuielile curente
//    if (get_lungime(&ptr_ui->serviceCheltuieli.repoCheltuieli) == 0)
//        printf("Nu exista cheltuieli!");
//    else {
//        Cheltuiala* cheltuieli;
//        cheltuieli = get_cheltuieli(&ptr_ui->serviceCheltuieli.repoCheltuieli);
//        printf("Cheltuielile sunt: \n");
//        for (int i = 0; i < get_lungime(&ptr_ui->serviceCheltuieli.repoCheltuieli); i++)
//            printf("Ziua: %d | Suma: %lf | Tipul: %s\n", cheltuieli[i].ziua, cheltuieli[i].suma,
//                cheltuieli[i].tip);
//    }
//}
//
//void ui_adaugare_cheltuiala(UI* ptr_ui) {
//    // incearca sa adauge o cheltuiala la lista de cheltuieli
//    int ziua; double suma; char tip[51];
//
//    printf("Ziua cheltuielii: ");
//    scanf_s("%d", &ziua);
//
//    printf("Suma cheltuielii: ");
//    scanf_s("%lf", &suma);
//
//    printf("Tipul cheltuielii: ");
//    scanf_s("%s", tip, 51);
//
//    int result = service_adauga_cheltuiala(&ptr_ui->serviceCheltuieli, ziua, suma, tip);
//    if (result == 0)
//        printf("Parametrii invalizi!\n");
//    else if (result == 2)
//        printf("Cheltuiala deja exista!\n");
//    else
//        printf("Cheltuiala adaugata cu succes!\n");
//}
//
//void ui_modificare_cheltuiala(UI* ptr_ui) {
//    // incearca sa modifice o cheltuiala;
//    int ziua; double suma; char tip[51];
//    int new_ziua; double new_suma; char new_tip[51];
//
//    printf("Ziua cheltuielii de modificat: ");
//    scanf_s("%d", &ziua);
//
//    printf("Suma cheltuielii de modificat: ");
//    scanf_s("%lf", &suma);
//
//    printf("Tipul cheltuielii de modificat: ");
//    scanf_s("%s", tip, 51);
//
//    printf("Ziua noua: ");
//    scanf_s("%d", &new_ziua);
//
//    printf("Suma noua: ");
//    scanf_s("%lf", &new_suma);
//
//    printf("Tipul nou: ");
//    scanf_s("%s", new_tip, 51);
//
//    int result = service_modifica_cheltuiala(&ptr_ui->serviceCheltuieli, ziua, suma, tip, new_ziua, new_suma, new_tip);
//    if (result == 0)
//        printf("Cheltuiala nu exista sau parametrii de modificare invalizi!\n");
//    else
//        printf("Cheltuiala modificata cu succes!\n");
//}
//
//void ui_sterge_cheltuiala(UI* ptr_ui) {
//    // sterge o cheltuiala
//    int ziua; double suma; char tip[51];
//
//    printf("Ziua cheltuielii: ");
//    scanf_s("%d", &ziua);
//
//    printf("Suma cheltuielii: ");
//    scanf_s("%lf", &suma);
//
//    printf("Tipul cheltuielii: ");
//    scanf_s("%s", tip);
//
//    int result = service_sterge_cheltuiala(&ptr_ui->serviceCheltuieli, ziua, suma, tip);
//    if (result == 0)
//        printf("Nu exista cheltuiala!\n");
//    else
//        printf("Stergere cu succes!\n");
//}
//
//void ui_filtrare(UI* ptr_ui) {
//    ListaCheltuieli listaCheltuieli = creeaza_lista_cheltuieli();
//    while (1) {
//        printf("\nOptiuni filtrare: \n 1. Dupa zi \n 2. Dupa suma \n 3. Dupa tip \n 4. Iesire \n");
//        int optiune_filtrare;
//        printf("Optiune: ");
//        scanf_s("%d", &optiune_filtrare);
//        switch (optiune_filtrare) {
//        case 1: {
//            int ziua;
//            printf("Ziua dupa care se filtreaza: ");
//            scanf_s("%d", &ziua);
//            filtrare_zi(&ptr_ui->serviceCheltuieli, &listaCheltuieli, ziua);
//
//            if (listaCheltuieli.lungime == 0) {
//                printf("Lista de cheltuieli goala!");
//                return;
//            }
//
//            printf("Cheltuieli filtrate:\n");
//            for (int i = 0; i < listaCheltuieli.lungime; i++)
//                printf("Ziua: %d | Suma: %lf | Tip: %s\n", listaCheltuieli.cheltuieli[i].ziua,
//                    listaCheltuieli.cheltuieli[i].suma, listaCheltuieli.cheltuieli[i].tip);
//            distruge_lista_cheltuieli(&listaCheltuieli);
//            return;
//        }
//        case 2: {
//            double suma;
//            printf("Suma dupa care se filtreaza: ");
//            scanf_s("%lf", &suma);
//            filtrare_suma(&ptr_ui->serviceCheltuieli, &listaCheltuieli, suma);
//
//            if (listaCheltuieli.lungime == 0) {
//                printf("Lista de cheltuieli goala!");
//                return;
//            }
//
//            printf("Cheltuieli filtrate:\n");
//            for (int i = 0; i < listaCheltuieli.lungime; i++)
//                printf("Ziua: %d | Suma: %lf | Tip: %s\n", listaCheltuieli.cheltuieli[i].ziua,
//                    listaCheltuieli.cheltuieli[i].suma, listaCheltuieli.cheltuieli[i].tip);
//            distruge_lista_cheltuieli(&listaCheltuieli);
//            return;
//        }
//        case 3: {
//            char tip[51];
//            printf("Tipul dupa care se filtreaza: ");
//            scanf_s("%s", tip);
//            filtrare_tip(&ptr_ui->serviceCheltuieli, &listaCheltuieli, tip);
//
//            if (listaCheltuieli.lungime == 0) {
//                printf("Lista de cheltuieli goala!");
//                return;
//            }
//
//            printf("Cheltuieli filtrate:\n");
//            for (int i = 0; i < listaCheltuieli.lungime; i++)
//                printf("Ziua: %d | Suma: %lf | Tip: %s\n", listaCheltuieli.cheltuieli[i].ziua,
//                    listaCheltuieli.cheltuieli[i].suma, listaCheltuieli.cheltuieli[i].tip);
//            distruge_lista_cheltuieli(&listaCheltuieli);
//            return;
//        }
//        case 4: {
//            printf("Iesire!\n");
//            distruge_lista_cheltuieli(&listaCheltuieli);
//            return;
//        }
//        default:
//            printf("Optiune invalida!\n");
//        }
//    }
//}
//
//void ui_ordonare(UI* ptr_ui) {
//    ListaCheltuieli listaCheltuieli = creeaza_lista_cheltuieli();
//    while (1) {
//        printf("\nOptiuni ordonare: \n 1. Crescator \n 2. Descrescator \n");
//        int optiune_ordonare;
//        printf("Optiune: ");
//        scanf_s("%d", &optiune_ordonare);
//
//        printf("\n Dupa ce sortezi? \n 1. Zi \n 2. Tip \n");
//        int optiune;
//        printf("Optiune: ");
//        scanf_s("%d", &optiune);
//
//        if (optiune_ordonare < 1 || optiune_ordonare > 2 || optiune < 1 || optiune > 2) {
//            printf("Optiune invalida! Iesire! \n");
//            distruge_lista_cheltuieli(&listaCheltuieli);
//            return;
//        }
//        else {
//            ordonare(&ptr_ui->serviceCheltuieli, &listaCheltuieli, optiune_ordonare, optiune);
//            printf("Cheltuielile sortate: \n");
//            for (int i = 0; i < listaCheltuieli.lungime; i++)
//                printf("Ziua: %d | Suma: %lf | Tip: %s\n", listaCheltuieli.cheltuieli[i].ziua,
//                    listaCheltuieli.cheltuieli[i].suma, listaCheltuieli.cheltuieli[i].tip);
//            distruge_lista_cheltuieli(&listaCheltuieli);
//            return;
//        }
//    }
//}
//
//void show_ui() {
//    UI ui = creeaza_ui();
//    while (1) {
//        printf("\nOptiuni: \n 0. Afiseaza cheltuieli \n 1. Adauga cheltuiala \n 2. Modifica cheltuiala \n 3. Sterge cheltuiala \n "
//            "4. Filtrare cheltuiala \n 5. Sortare cheltuieli \n 6. Iesire");
//        int optiune;
//        printf("\nOptiune: ");
//        scanf_s("%d", &optiune);
//        if (optiune == 6) {
//            printf("Bye!");
//            distruge_ui(&ui);
//            break;
//        }
//        else if (optiune == 0)
//            ui_afiseaza_cheltuieli(&ui);
//        else if (optiune == 1)
//            ui_adaugare_cheltuiala(&ui);
//        else if (optiune == 2)
//            ui_modificare_cheltuiala(&ui);
//        else if (optiune == 3)
//            ui_sterge_cheltuiala(&ui);
//        else if (optiune == 4)
//            ui_filtrare(&ui);
//        else if (optiune == 5)
//            ui_ordonare(&ui);
//        else
//            printf("Optiune invalida!\n");
//    }
//    distruge_ui(&ui);
//}
