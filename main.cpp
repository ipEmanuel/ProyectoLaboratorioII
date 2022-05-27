using namespace std;
#include <iostream>
#include "string.h"
#include "rlutil.h"
#include "Fecha.h"
#include "TipoArticuloMedicamento.h"
#include <wchar.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "");
    int opcion;
    char confirma;
    while (true) {
        rlutil::setColor(rlutil::LIGHTRED);
        rlutil::cls();
        cout << "Menú Principal" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Tipos de medicamentos" << endl;
        cout << "2 - Articulos de medicamentos" << endl;
        cout << "3 - Cliente" << endl;
        cout << "4 - Venta" << endl;
        cout << "5 - Reportes" << endl;
        cout << "6 - Configuracion"<<endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opción: ";
        cin >> opcion;

        rlutil::cls();

        switch (opcion) {
        case 1:
            menuTipoDeMedicamento();
        break;
        case 2:
            cout << "menuArticuloDeMedicamentos();";
            break;
        case 3:
            cout << "menuClientes();";
            break;
        case 4:
            cout << "menuVentas();";
            break;
        case 5:
            cout << "menuReportes();";
            break;
        case 6:
            cout << "menuConfiguracion();";
            break;
        case 0:
            cout << "¿Confirma salir? (S/N) ";
            cin >> confirma;
            if (tolower(confirma) == 's') {
                return 0;
            }
            break;
        }
        cin.ignore();
        rlutil::anykey();
    }
}
