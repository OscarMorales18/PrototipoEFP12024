#include "empleados.h"
#include "login.h"
#include "bitacora.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

empleados::empleados(string id, string nom, string codpue, string codepa, string sueldo, string status)
{
    this->id = id;
    this->nom = nom;
    this->codpue = codpue;
    this->codepa = codepa;
    this->sueldo = sueldo;
    this->status = status;
}

string empleados::setid(string id)
{
    this->id = id;
    return id;
}

string empleados::getid()
{
    return id;
}

string empleados::setnom(string nom)
{
    this->nom = nom;
    return nom;
}

string empleados::getnom()
{
    return nom;
}

string empleados::setcodpue(string codpue)
{
    this->codpue = codpue;
    return codpue;
}

string empleados::getcodpue()
{
    return codpue;
}

string empleados::setcodepa(string codepa)
{
    this->codepa = codepa;
    return codepa;
}

string empleados::getcodepa()
{
    return codepa;
}

string empleados::setsueldo(string sueldo)
{
    this->sueldo = sueldo;
    return sueldo;
}

string empleados::getsueldo()
{
    return sueldo;
}

string empleados::setstatus(string status)
{
    this->status = status;
    return status;
}

string empleados::getstatus()
{
    return status;
}

void empleados::menu()
{
    system("cls");
    int opc;
    char continuar;

    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2003", "EMPLE");

    do
    {
        cout << "\n";
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t     Catalogo de Empleados\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t1) Insertar\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t2) Desplegar \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t3) Modificar \t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t\t4) Borrar\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    5) Salir del programa\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t|\t    6) Regresar al menu\t\t   |" << endl;
        cout << "\t|\t\t            \t\t   |" << endl;
        cout << "\t+------------------------------------------+" << endl;
        cout << "\n" << endl;
        cout << "\t\tIngrese el numero de opcion: ";
        cin >> opc;

        switch(opc)
        {
        case 1:
            system("cls");
            do
				{
					insertar();
					cout<<" -> Deseas ingresar a otro empleado? (S/N): ";
					cin>>continuar;
				}while(continuar=='S' || continuar=='s');
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            desplegar();
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            modificar();
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            borrar();
            system("pause");
            system("cls");
            break;
        case 5:
            exit(0);
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "\n\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
            system("cls");
        }
    } while (opc!=6);
}

void empleados::insertar()
{

    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2004", "EMPLEI");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|        Agregar detalles del Empleado\t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    srand(time(NULL));
    Empleados empleados;
    int numAleatorio = (rand() % 9998) + 1;

    string idString = "emple-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        empleados.id[i] = idString[i];
    }
    empleados.id[idString.length()] = '\0';

    cout<<"        -> Generando codigo del empleados: " << empleados.id<<endl;
    cin.ignore();

    cout<<"        -> Ingrese el nombre del empleados: ";
    cin.getline(empleados.nom, 45);

    cout<<"        -> Ingrese el codigo del puesto: ";
    cin.getline(empleados.codpue, 20);

    cout<<"        -> Ingrese el codigo del departamento: ";
    cin.getline(empleados.codepa, 20);

    cout<<"        -> Ingrese el sueldo del empleados: ";
    cin.getline(empleados.sueldo, 20);

    cout<<"        -> Ingrese el estatus del empleados: ";
    cin.getline(empleados.status, 45);

    cout << "\n";
    cout<<"+---------------------------------------------------------+"<< endl;
    cout << "\n";

    ofstream archivo("Empleados.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&empleados), sizeof(empleados));
    archivo.close();

}

void empleados::desplegar()
{

    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2005", "EMPLED");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|           Ver detalles del Empleado\t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Empleados.dat", ios::binary | ios::in);
    if(!archivo)
    {
        cout << "No hay informacion registrada...";
        cout << "\n";
        return;
    }
        Empleados empleados;

        while (archivo.read(reinterpret_cast<char*>(&empleados), sizeof(Empleados)))
        {
            cout<<"       -> Codigo del empleado: "<< empleados.id << endl;
            cout<<"       -> Nombre del empleado: "<< empleados.nom << endl;
            cout<<"       -> Codigo de puesto: "<< empleados.codpue << endl;
            cout<<"       -> Codigo de departamento: "<< empleados.codepa << endl;
            cout<<"       -> Sueldo del empleado: "<< empleados.sueldo << endl;
            cout<<"       -> Estatus del empleado: "<< empleados.status << endl;
            cout << "     +-----------------------------------------------+" << endl;
            cout << "\n";
        }

        archivo.close();

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void empleados::modificar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2006", "EMPLEM");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|        Modificar detalles del Empleado\t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    fstream archivo;
    string idemple;
    bool encontrado = false;

    archivo.open("Empleados.dat", ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "       -> Error, no se encuentra informacion...";
        cout << "\n";
        return;
    }
    cout << "       -> Ingrese el codigo del empleado: ";
    cin >> idemple;

    Empleados empleados;

    while (archivo.read(reinterpret_cast<char*>(&empleados), sizeof(Empleados))) {
        if (empleados.id == idemple) {
            encontrado = true;

            cout << "\n" << endl;
            cout << "           Empleado encontrado con exito!" << endl;
            cout << "\n" << endl;

            cout<<"        -> Ingrese el codigo del empleados: ";
            cin>>empleados.id;

            cout<<"        -> Ingrese el nombre del empleados: ";
            cin>>empleados.nom;

            cout<<"        -> Ingrese el codigo del puesto: ";
            cin>>empleados.codpue;

            cout<<"        -> Ingrese el codigo del departamento: ";
            cin>>empleados.codepa;

            cout<<"        -> Ingrese el sueldo del empleados: ";
            cin>>empleados.sueldo;

            cout<<"        -> Ingrese el estatus del empleados: ";
            cin >> empleados.status;

            cout << "\n" << endl;

            archivo.seekp(-static_cast<int>(sizeof(Empleados)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&empleados), sizeof(Empleados));
            break;
        }
    }

    archivo.close();

    if (!encontrado) {
        cout << "       -> No se encontró un empleado con el ID proporcionado." << endl;
        cout << "\n" << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

void empleados::borrar()
{
    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2007", "EMPLEB");

    cout << "\n";
    cout << "\t+------------------------------------------+" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t|        Eliminar detalles del Empleado\t   |" << endl;
    cout << "\t|\t\t            \t\t   |" << endl;
    cout << "\t+------------------------------------------+" << endl;
    cout << "\n";

    ifstream archivo("Empleados.dat", ios::binary);
    string idemple;

	if(!archivo)
	{
		cout<<"       -> Error, no se encuentra informacion...";
		cout << "\n";
		return;
	}

	ofstream archivo2("empleados2.dat", ios::binary);

	Empleados empleados;

    cout<<"       -> Ingrese el codigo del empleado: ";
    cin>>idemple;

    bool resta = false;

		while(archivo.read(reinterpret_cast<char*>(&empleados), sizeof(Empleados)))
		{
			if(empleados.id != idemple)
			{
				archivo2.write(reinterpret_cast<const char*>(&empleados), sizeof(Empleados));
			}
			else
			{
			    resta = true;
			}

		}
		archivo.close();
		archivo2.close();

		remove("Empleados.dat");

		rename("empleados2.dat","Empleados.dat");

		if (resta)
        {
        cout << "\n" << endl;
        cout << "       -> Empleado eliminado con exito." << endl;
        cout << "\n";
        }
        else
        {
        cout << "\n" << endl;
        cout << "       -> No se a podido encontrar al empleado" << endl;
        cout << "\n";
        }
}
