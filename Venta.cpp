using namespace std;
#include<iostream>
#include<cstdlib>
#include "Venta.h"
#include "Fecha.h"

//METODOS GET
int Venta::getidVenta() 
{
	return _idVenta;
}
int	Venta::getidMedicamento() 
{
	return _idMedicamento;
}
int Venta::getidTipoMedicamento() 
{
	return _idTipoMedicamento;
}
int	Venta::getidCliente() 
{
	return _idCliente;
}
Fecha Venta::getFechaVenta() 
{
	return _fechaVenta;
}
int	Venta::getCantidad() 
{
	return _cantidad;
}
float Venta::getImporte() 
{
	return _importe;
}
int Venta::getNumeroSucursal() 
{
	return _numeroSucursal;
}
bool Venta::getEstado() 
{
	return _estado;
}

//METODOS SET
void Venta::setIdVenta(int idVenta) 
{
	_idVenta = idVenta;
}
void Venta::setIdMedicamento(int idMedicamento) 
{
	_idMedicamento = idMedicamento;
}
void Venta::setidTipoMedicamento(int idTipoMedicamneto) 
{
	_idTipoMedicamento = idTipoMedicamneto;
}
void Venta::setIdCliente(int idCliente) 
{
	_idCliente = idCliente;
}
void Venta::setFechaVenta(Fecha fechaVenta) 
{
	_fechaVenta = fechaVenta;
}
void Venta::setCantidad(int cantidad) 
{
	_cantidad = cantidad;
}
void Venta::setImporte(float importe) 
{
	_importe = importe;
}
void Venta::setNumeroSucursal(int numerosucursal) 
{
	_numeroSucursal = numerosucursal;
}
void Venta::setEstado(bool estado) 
{
	_estado = estado;
}
