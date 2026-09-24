#include "Persona.hpp"
#include <cstdlib>
#include <iostream>

Persona::Persona(int edad){
    this->edad = edad;
    this->genero = rand() % 2;
    this->generarDNI();
}
int Persona::getEdad(){
    return this->edad;
}

bool Persona::esMujer() {
    return this->genero;
}

void Persona::setEdad(int edad){
    this->edad = edad;
}


Persona::~Persona()
{
}

void Persona::generarDNI() {
    int num = 0;
    for (int i = 0; i < 8; ++i) {
        int digito = rand() % 10;
        this->DNI[i] = '0' + digito;
        num = num * 10 + digito;
    }
    const char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
    this->DNI[8] = letras[num % 23];
    this->DNI[9] = '\0';
}

void Persona::mostrar() {
    std::cout << "Edad: " << this->edad
              << " | DNI: " << this->DNI
              << " | Genero: " << (this->genero ? "Mujer" : "Hombre")
              << std::endl;
}

