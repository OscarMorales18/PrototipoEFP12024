
//  Creado por Oscar Emilio Morales Lemus 9959-23-3070

#include "menu.h"
#include "windows.h"
#include "empleados.h"
#include "bitacora.h"
#include "usuarios.h"
#include <iostream>

using namespace std;

menu::menu()
{
    //ctor
}

void menu::MenuGeneral()
{
    system("cls");
    int opc;

    do
    {
        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t Oscar Emilio Morales Lemus\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t9959-23-307\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\tMenu general\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t1) Catalogos\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t2) Informes \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t3) Seguridad \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    4) Salir del Programa\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;
        switch(opc)
        {
        case 1:
            system("cls");
            Catalogos();
            system("cls");
            break;
        case 2:
            system("cls");
            Informes();
            system("cls");
            break;
        case 3:
            system("cls");
            Seguridad();
            system("cls");
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=4);

}

void menu::Catalogos()
{
    system("cls");
    int opc;

    do
    {
        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t     Menu de Catalogos\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t1) Empleados\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t2) Usuarios\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    3) Regresar al Menu\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    4) Salir del Programa\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
        {
            empleados emplea;
            emplea.menu();
        }
            break;
        case 2:
        {
            usuarios usu;
            usu.menu();
        }
            break;
        case 3:
            MenuGeneral();
        case 4:
            exit(0);
            break;
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=3);
}

void menu::Informes()
{
    system("cls");
    Bitacora bitacora; // Creamos un objeto Bitacora

    int opcion;
    string usuario;

    do {

        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t     Menu de Reportes\t\t   |" << endl;;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t1) Generar reporte completo\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t2) Generar reporte por usuario \t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    3) Regresar al menu\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                bitacora.generarReporteCompleto();
                break;
            case 2:
                 system("cls");
                 cout << "\n" << endl;
                cout << "\tIngrese el nombre de usuario para generar el reporte: ";
                cin >> usuario;
                bitacora.generarReportePorUsuario(usuario);
                break;
            case 3:
                MenuGeneral();
            default:
                cout << "Opción no válida. Por favor, seleccione una opción válida." << endl;
                break;
        }
    } while (opcion != 3);
}

void menu::Seguridad()
{
    system("cls");
    int opc;

    do
    {
        system("cls");
        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t     Menu de Seguridad\t\t   |" << endl;;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t1) Bitacora \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    2) Regresar al menu\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
            {
                Bitacora bitacora;
                bitacora.mostrarBitacora();
                break;
            }
        case 2:
            MenuGeneral();
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=2);
}
