using namespace std;
#include<iostream>
#include<cstdlib>
#include "string.h"
#include "ArticuloDeMedicamento.h"

//METODOS GET
int ArticuloDeMedicamento::getIdArticuloMedicamento()
{
    return _idArticuloMediamento;
}
int ArticuloDeMedicamento::getIdTipoArticuloMedicamento()
{
    return _idTipoArticuloMedicamento;
}
string ArticuloDeMedicamento::getNombre()
{
    string nombre;
    nombre = _nombre;
    return nombre;
}
float ArticuloDeMedicamento::getPrecio()
{
    return _precio;
}
int ArticuloDeMedicamento::getStock()
{
    return _stock;
}
bool ArticuloDeMedicamento::getEstado()
{
    return _estado;
}


//METODOS SET
void ArticuloDeMedicamento::setIdArticuloMedicamento(int idArticuloMedicamento)
{
    _idArticuloMediamento = idArticuloMedicamento;
}
void ArticuloDeMedicamento::setIdTipoArticuloMedicamento(int idTipoArticuloMedicamento)
{
    _idTipoArticuloMedicamento = idTipoArticuloMedicamento;
}
void ArticuloDeMedicamento::setNombre(string nombre)
{
    strcpy(_nombre, nombre.c_str());//_nombre lo comvierto a string
}
void ArticuloDeMedicamento::setPrecio(float precio)
{
    _precio = precio;
}
void ArticuloDeMedicamento::setStock(int stock)
{
    _stock = stock;
}
void ArticuloDeMedicamento::setEstado(bool estado)
{
    _estado = estado;
}
