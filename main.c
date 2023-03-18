#include "./tests/tests.h"
#include "./headers/ui.h"

int main() {
    test_domain();
    test_repo();
    test_validator();
    test_service();
    printf("Test ok!\n");

    show_ui();

    return 0;
}
