#pragma once
#include "Fecha.h"
#include "string.h"

class Cliente
{
	private:
		int _idCliente;
		char _apellido[50];
		char _nombre[50];
		int _dni;
		Fecha _primeraCompra;
		bool _estado;
	public:
		//METODOS GET
		int	getIdCliente();
		string getApellido();
		string getNombre();
		int getDni();
		Fecha getPrimeraCompra();
		bool getEstado();

		//METODOS SET
		void setIdCliente(int idCliente);
		void setApellido(string apellido);
		void setNombre(string nombre);
		void setDni(int dni);
		void setPrimeraCompra(Fecha primerCompra);
		void setEstado(bool estado);
};

