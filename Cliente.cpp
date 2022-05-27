using namespace std;
#include<iostream>
#include<cstdlib>
#include "string.h"
#include "Cliente.h"
//METODOS GET
int Cliente::getIdCliente()
{
    return _idCliente;
}

string Cliente::getApellido()
{
    string apellido;
    apellido = _apellido;
    return apellido;
}

string Cliente::getNombre()
{
    string nombre;
    nombre = _nombre;
    return nombre;
}

int Cliente::getDni()
{
    return _dni;
}

Fecha Cliente::getPrimeraCompra()
{
    return _primeraCompra;
}

bool Cliente::getEstado()
{
    return _estado;
}

//METODOS SET
void Cliente::setIdCliente(int idCliente)
{
    _idCliente = idCliente;
}

void Cliente::setApellido(string apellido)
{
    strcpy(_apellido, apellido.c_str());//_nombre lo comvierto a string
}

void Cliente::setNombre(string nombre)
{
    strcpy(_nombre, nombre.c_str());//_nombre lo comvierto a string
}

void Cliente::setDni(int dni)
{
    _dni = dni;
}

void Cliente::setPrimeraCompra(Fecha primeraCompra)
{
    _primeraCompra = primeraCompra;
}

void Cliente::setEstado(bool estado)
{
    _estado = estado;
}

