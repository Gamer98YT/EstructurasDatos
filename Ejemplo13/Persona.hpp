#ifndef PERSONA_HPP
#define PERSONA_HPP
#include <iostream>


class Persona
{
public:
    Persona(int edad);
    int getEdad();
    bool esMujer();
    void setEdad(int edad);
    void mostrar();
    ~Persona();
    
    
private:
    bool genero; //T = Mujer, F = Hombre
    int edad;
    char DNI[10];
    void generarDNI();
    

};

#endif // PERSONA_HPP
