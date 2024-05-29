#ifndef EMPLEADOS_H
#define EMPLEADOS_H
#include <iostream>

using namespace std;

class empleados
{
    public:

        empleados() {}
        empleados(string id, string nom, string codpue, string codepa, string sueldo, string status);

        string setid(string id);
        string getid();

        string setnom(string nom);
        string getnom();

        string setcodpue(string codpue);
        string getcodpue();

        string setcodepa(string codepa);
        string getcodepa();

        string setsueldo(string sueldo);
        string getsueldo();

        string setstatus(string status);
        string getstatus();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void borrar();

        struct Empleados
        {
            char id[20];
            char nom[45];
            char codpue[20];
            char codepa[20];
            char sueldo[20];
            char status[45];
        };

    protected:

    private:
        string id, nom, codpue, codepa, sueldo, status;
};

#endif // EMPLEADOS_H
