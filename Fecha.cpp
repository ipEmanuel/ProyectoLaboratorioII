#include "Fecha.h"
#include<iostream>
#include<cstdlib>
#include <ctime>
#include "string.h"
using namespace std;
#include "Fecha.h"

Fecha::Fecha()
{
    time_t t;
    struct tm* f;
    time(&t);
    f = localtime(&t);
    _dia = f->tm_mday;
    _mes = f->tm_mon + 1;
    _anio = f->tm_year + 1900;
}
Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

string Fecha::toString() {
    string fecha;
    fecha = to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
    return fecha;
}
Fecha::Fecha(string fecha)
{
    string dia, mes, anio;
    int d, m, a;

    dia = fecha.substr(0, 2);
    mes = fecha.substr(3, 2);
    anio = fecha.substr(6, 4);

    d = stoi(dia, 0);
    m = stoi(mes, 0);
    a = stoi(anio, 0);

    _dia = d;
    _mes = m;
    _anio = a;
}

//METODOS SET
void Fecha::setDia(int dia) {
    _dia = dia;
}
void Fecha::setMes(int mes) {
    _mes = mes;
}
void Fecha::setAnio(int anio) {
    _anio = anio;
}

//METODOS GET
int Fecha::getDia() {
    return _dia;
}
int Fecha::getMes() {
    return _mes;
}
int Fecha::getAnio() {
    return _anio;
}

//METODOS
void Fecha::mostrar() {
    if (_dia < 10 && _mes < 10) {
        cout << "0" << _dia << "/0" << _mes << "/" << _anio << endl;
    }
    else {
        if (_dia < 10 && _mes>9) {
            cout << "0" << _dia << "/" << _mes << "/" << _anio << endl;
        }
        else {
            if (_dia > 9 && _mes < 10) {
                cout << _dia << "/0" << _mes << "/" << _anio << endl;
            }
            else {
                cout << _dia << "/" << _mes << "/" << _anio << endl;
            }
        }
    }
}
