#pragma once
#include "Fecha.h"
class Venta
{
	private:
		int _idVenta;
		int _idMedicamento;
		int _idTipoMedicamento;
		int _idCliente;
		Fecha _fechaVenta;
		int _cantidad;
		float _importe;
		int _numeroSucursal;
		bool _estado;

	public:
		//METODOS GET
		int getidVenta();
		int	getidMedicamento();
		int getidTipoMedicamento();
		int	getidCliente();
		Fecha getFechaVenta();
		int	getCantidad();
		float getImporte();
		int getNumeroSucursal();
		bool getEstado();
			
		//METODOS SET
		void setIdVenta(int idVenta);
		void setIdMedicamento(int idMedicamento);
		void setidTipoMedicamento(int idTipoMedicamneto);
		void setIdCliente(int idCliente);
		void setFechaVenta(Fecha fechaVenta);
		void setCantidad(int cantidad);
		void setImporte(float importe);
		void setNumeroSucursal(int numerosucursal);
		void setEstado(bool estado);
};

