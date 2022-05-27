#pragma once
#include <string>
class ArticuloDeMedicamento
{
    private:
        int _idArticuloMediamento;
        int _idTipoArticuloMedicamento;
        char _nombre[50];
        float _precio;
        int _stock;
        bool _estado;

    public:
        //METODOS GET
        int getIdArticuloMedicamento();
        int getIdTipoArticuloMedicamento();
        string getNombre();
        float getPrecio();
        int getStock();
        bool getEstado();

        //METODOS SET
        void setIdArticuloMedicamento(int idArticuloMedicamento);
        void setIdTipoArticuloMedicamento(int idTipoArticuloMedicamento);
        void setNombre(string nombre);
        void setPrecio(float precio);
        void setStock(int stock);
        void setEstado(bool estado);
};

