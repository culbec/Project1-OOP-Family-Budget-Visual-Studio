#include <stdio.h>
#include "./tests/tests.h"
#include "./headers/ui.h"

//#define _CRTDBG_MAP_ALLOC

int main() {
    test_domain();
    test_validator();
    test_repo();
    test_service();

    printf("Test ok!\n");

    //showUi();
    //_CrtDumpMemoryLeaks();

    return 0;
}
