#include <cstring>
#include "Bitacora.h"
#include "Login.h"

void Bitacora::ingresoBitacora(const string& usuario, const string& codigoPrograma, const string& tipoIngreso) {

    ofstream archivo("Bitacora.dat", ios::binary | ios::app);

    if (archivo.is_open()) {

        RegistroBitacora registro;

        strncpy(registro.nombre, usuario.c_str(), sizeof(registro.nombre) - 1);
        registro.nombre[sizeof(registro.nombre) - 1] = '\0';

        strncpy(registro.aplicacion, codigoPrograma.c_str(), sizeof(registro.aplicacion) - 1);
        registro.aplicacion[sizeof(registro.aplicacion) - 1] = '\0';

        strncpy(registro.accion, tipoIngreso.c_str(), sizeof(registro.accion) - 1);
        registro.accion[sizeof(registro.accion) - 1] = '\0';

        time_t now = time(0);
        tm *ltm = localtime(&now);
        string fechaHora = to_string(ltm->tm_year + 1900) + "-" + to_string(ltm->tm_mon + 1) + "-" + to_string(ltm->tm_mday) + " " +
                           to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
        strncpy(registro.fechaHora, fechaHora.c_str(), sizeof(registro.fechaHora) - 1);
        registro.fechaHora[sizeof(registro.fechaHora) - 1] = '\0';

        archivo.write(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora));

        archivo.close();
    } else {
        cout << "\n" << endl;
        cout << "No se pudo abrir el archivo de bit�cora." << endl;
        cout << "\n" << endl;
    }
}

void Bitacora::mostrarBitacora() {

    string usuarioActual = Login::getUsuarioActual();
    Bitacora bitacora;
    bitacora.ingresoBitacora(usuarioActual, "2000", "BIT");

    system("cls");

    ifstream archivo("Bitacora.dat", ios::binary | ios::in);

    if (!archivo) {

        cout << "\n" << endl;
        cout << "No hay informaci�n registrada en la bit�cora." << endl;
        cout << "\n" << endl;
        return;
    }

    RegistroBitacora registro;
    cout << "+---------------------------------------------------------------------------------------------------+" << endl;
    cout << "       Usuario               Aplicacion                Accion                     Fecha y Hora" << endl;
    cout << "+---------------------------------------------------------------------------------------------------+" << endl;
    while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora))) {
        cout << "  \t" << registro.nombre << "\t\t\t" << registro.aplicacion << "\t\t\t" << registro.accion << "\t\t\t" << registro.fechaHora << endl;
    }
    archivo.close();

    cout << "Presione Enter para continuar";
    cin.ignore();
    cin.get();
}
void Bitacora::generarReporteCompleto() {
    system("cls");
    ifstream archivo("Bitacora.dat", ios::binary | ios::in);

    if (!archivo) {
        cout << "\n" << endl;
        cout << "\tNo hay informaci�n registrada en la bit�cora." << endl;
        cout << "\n" << endl;
        return;
    }

    ofstream reporte("ReporteCompleto.txt");
    if (!reporte) {
        cout << "\n" << endl;
        cout << "\tNo se pudo crear el archivo de reporte." << endl;
        cout << "\n" << endl;
        return;
    }

    RegistroBitacora registro;
    reporte << "+---------------------------------------------------------------------------------------------------+" << endl;
    reporte << "       Usuario               Aplicacion                Accion                     Fecha y Hora" << endl;
    reporte << "+---------------------------------------------------------------------------------------------------+" << endl;
    while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora))) {
        reporte << "  \t" << registro.nombre << "\t\t\t" << registro.aplicacion << "\t\t\t" << registro.accion << "\t\t\t" << registro.fechaHora << endl;
    }
    archivo.close();
    reporte.close();

    cout << "\n" << endl;
    cout << "\tSe ha generado el reporte completo en el archivo ReporteCompleto.txt." << endl;
    cout << "\n" << endl;
    system("pause");
    system("cls");
}

void Bitacora::generarReportePorUsuario(const string& nombreUsuario) {
    system("cls");
    ifstream archivo("Bitacora.dat", ios::binary | ios::in);

    if (!archivo) {
        cout << "\n" << endl;
        cout << "No hay informaci�n registrada en la bit�cora." << endl;
        cout << "\n" << endl;
        return;
    }

    ofstream reporte("ReportePorUsuario_" + nombreUsuario + ".txt");
    if (!reporte) {
        cout << "\n" << endl;
        cout << "No se pudo crear el archivo de reporte." << endl;
        cout << "\n" << endl;
        return;
    }

    RegistroBitacora registro;
    reporte << "+---------------------------------------------------------------------------------------------------+" << endl;
    reporte << "       Usuario               Aplicacion                Accion                     Fecha y Hora" << endl;
    reporte << "+---------------------------------------------------------------------------------------------------+" << endl;
    while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(RegistroBitacora))) {
        if (nombreUsuario == registro.nombre) {
            reporte << "  \t" << registro.nombre << "\t\t\t" << registro.aplicacion << "\t\t\t" << registro.accion << "\t\t\t" << registro.fechaHora << endl;
        }
    }
    archivo.close();
    reporte.close();
    system("cls");
    cout << "\n" << endl;
    cout << "\tSe ha generado el reporte para el usuario " << nombreUsuario << " en el archivo ReportePorUsuario_" << nombreUsuario << ".txt." << endl;
    cout << "\n" << endl;
    system("pause");
    system("cls");
}
