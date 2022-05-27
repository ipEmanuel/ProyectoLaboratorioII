#pragma once
#include <string>
using namespace std;

class Fecha
{
    private:
        int _dia;
        int _mes;
        int _anio;

    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        Fecha(string fecha);

        //METODOS SET
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        //METODOS GET
        int getDia();
        int getMes();
        int getAnio();

        string toString();
        void mostrar();
};

