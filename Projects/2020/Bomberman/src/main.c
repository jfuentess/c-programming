#include <stdlib.h>

int init(); // definido en utils
void mainloop(); // definido en gamelogic
void cleanup(); // definido en utils

int main(int argc, char *argv[]) {
    
    if (init() == EXIT_FAILURE)
        return EXIT_FAILURE;
    mainloop();
    cleanup();
    return EXIT_SUCCESS;
}
