#include<iostream>
#include<cstdlib>
using namespace std;
#include "rlutil.h"

void mostrarMensaje(string mensaje, int color, int x, int y)
{
    rlutil::locate(x, y);
    rlutil::setColor(color);
    cout << mensaje;
    rlutil::resetColor();
}
