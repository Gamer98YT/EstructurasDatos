#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Persona.hpp"

int main() {
    srand(time(NULL));

    for (int edad = 18; edad <= 27; edad++) {
        Persona p(edad);
        p.mostrar();
    }

    return 0;
}