#pragma once
#include <string>
class TipoArticuloMedicamento
{
	private:
		int _idTipoArticuloMedicamento;
		char _nombre[50];
		bool _estado;
        bool _eliminado;
	public:
		//METODOS GET
		int	getIdTipoArticuloMedicamento();
		string getNombre();
		bool getEstado();
		bool getEliminado();

		//METODOS SET
		void setIdTipoArticuloMedicamento(int idTipoArticuloMedicamento);
		void setNombre(string nombre);
		void setEstado(bool estado);
		void setEliminidado(bool eliminado);

        std::string toString();
        bool leerDeDisco(int nroRegistro);
        bool guardarEnDisco();
        bool guardarEnDisco(int nroRegistro);

};

bool nuevoTipoArticuloMedicamento();
TipoArticuloMedicamento cargarTipoArticuloMedicamento();
int cantidadRegistrosTipoArticuloMedicamento();
void listarTipoArticuloMedicamento();
int buscarTipoArticuloMedicamento(int idTipoArticuloMedicamento);
void buscarTipoArticuloMedicamentoPorID();
bool editarTipoArticuloMedicamento();
bool eliminarTipoArticuloMedicamento();
void menuTipoDeMedicamento();
