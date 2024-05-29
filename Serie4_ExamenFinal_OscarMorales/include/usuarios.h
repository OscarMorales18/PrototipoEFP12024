#ifndef USUARIOS_H
#define USUARIOS_H
#include <iostream>

using namespace std;

struct Usuarios {
    char nombre[80]; // Almacena el nombre de usuario.
    char contra[80]; // Almacena la contraseña del usuario.
};

// Declaración de la clase usuarios para gestionar usuarios en el sistema.
class usuarios {
//Atributos privados
private:
    string nombre, contra; // Nombre y contraseña del usuario.
//Atributos publicos
public:
    // Constructores
    usuarios(){} // Constructor predeterminado
    usuarios(string nombre, string contra); // Constructor con parámetros

    string setnombre(string nombre);
    string getnombre();

    string setcontra(string contra);
    string getcontra();

    void menu(); // Menú de opciones para la gestión de usuarios
    void pideDatos(); // Método para solicitar datos de usuario
    void muestraDatos(); // Método para mostrar datos de usuario
    void editaDatos(); // Método para editar datos de usuario
    void borraDatos(); // Método para eliminar datos de usuario
};

#endif // USUARIOS_H
