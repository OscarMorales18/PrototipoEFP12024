#include <iostream>
#include "menu.h"
#include "Login.h"

using namespace std;

int main()
{
    Login login;

    if (login.validacion()) {
        menu general;
        general.MenuGeneral();
    } else
    {
    cout<<"       -> Intentelo Nuevamente...";
    }

    system("cls");
}
