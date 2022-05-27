using namespace std;
#include<iostream>
#include<cstdlib>
//#include "ArticuloDeMedicamento.h"
#include "string.h"
#include "TipoArticuloMedicamento.h"
#include "rlutil.h"
#include "Funciones.h"
//METODOS GET
int	TipoArticuloMedicamento::getIdTipoArticuloMedicamento()
{
	return _idTipoArticuloMedicamento;
}
string TipoArticuloMedicamento::getNombre()
{
	string nombre;
	nombre = _nombre;
	return nombre;
}
bool TipoArticuloMedicamento::getEstado()
{
	return _estado;
}
bool TipoArticuloMedicamento::getEliminado(){
    return _eliminado;
}
//METODOS SET
void TipoArticuloMedicamento::setIdTipoArticuloMedicamento(int idTipoArticuloMedicamento)
{
	_idTipoArticuloMedicamento = idTipoArticuloMedicamento;
}
void TipoArticuloMedicamento::setNombre(string nombre)
{
	strcpy(_nombre, nombre.c_str());//_nombre lo comvierto a string
}
void TipoArticuloMedicamento::setEstado(bool estado)
{
	_estado = estado;
}
void TipoArticuloMedicamento::setEliminidado(bool eliminado){
    _eliminado=eliminado;
}

//OTROS METODOS DE CLASE
std::string TipoArticuloMedicamento::toString(){
    std::string cadena;
    if(_estado){
        cadena = std::to_string(_idTipoArticuloMedicamento) + ", "+_nombre+" - Disponible";
    }else{
        cadena = std::to_string(_idTipoArticuloMedicamento) + ", "+_nombre+" - No Disponible";
    }
    return cadena;
}
bool TipoArticuloMedicamento::leerDeDisco(int nroRegistro){
    FILE *p = fopen("tipoArticuloMedicamento.dat", "rb");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(TipoArticuloMedicamento), SEEK_SET);
    bool ok = fread(this, sizeof(TipoArticuloMedicamento), 1, p);
    fclose(p);
    return ok;
}
bool TipoArticuloMedicamento::guardarEnDisco(){
    FILE *p = fopen("tipoArticuloMedicamento.dat", "ab");
    if (p == NULL){
        return false;
    }
    bool guardo = fwrite(this, sizeof(TipoArticuloMedicamento), 1, p);
    fclose(p);
    return guardo;
}
bool TipoArticuloMedicamento::guardarEnDisco(int nroRegistro){
    FILE *p = fopen("tipoArticuloMedicamento.dat", "rb+");
    if (p == NULL){
        return false;
    }
    fseek(p, nroRegistro * sizeof(TipoArticuloMedicamento), SEEK_SET);
    bool guardo = fwrite(this, sizeof(TipoArticuloMedicamento), 1, p);
    fclose(p);
    return guardo;
}

//FUNCIONES GLOBALES PARA TIPOARTICULOMEDICAMENTO

bool nuevoTipoArticuloMedicamento()
{
    TipoArticuloMedicamento reg;
    reg = cargarTipoArticuloMedicamento();
    bool ok = reg.guardarEnDisco();
    return ok;
}
TipoArticuloMedicamento cargarTipoArticuloMedicamento()
{
    int id;
    string nombre;
    bool estado=true;

    id = cantidadRegistrosTipoArticuloMedicamento() + 1;
    cout << "Nombre: ";
    cin >> nombre;

    TipoArticuloMedicamento reg;
    reg.setIdTipoArticuloMedicamento(id);
    reg.setNombre(nombre);
    reg.setEstado(estado);
    reg.setEliminidado(false);

    return reg;
}
int cantidadRegistrosTipoArticuloMedicamento()
{
    FILE *p = fopen("tipoArticuloMedicamento.dat", "rb");
    if (p == NULL){
        return 0;
    }
    size_t bytes;
    int cant_reg;

    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    fclose(p);
    cant_reg = bytes / sizeof(TipoArticuloMedicamento);
    return cant_reg;
}
void listarTipoArticuloMedicamento()
{
    TipoArticuloMedicamento aux;
    int i = 0;
    int cantidad =0;
    int cantArtM = cantidadRegistrosTipoArticuloMedicamento();
    cout << "LISTADO DE TIPOS ARTICULOS DE MEDICAMENTOS" << endl;
    cout << "------------------------------------------" << endl;

    for(i=0; i<cantArtM; i++){
        aux.leerDeDisco(i);
        if(!aux.getEliminado()){
            cout << aux.toString() << endl;
            cantidad++;
        }
    }
    cout << "----------------------------------" << endl;
    cout << "Total: " << cantidad;
}



int buscarTipoArticuloMedicamento(int idTipoArticuloMedicamento)
{
    TipoArticuloMedicamento aux;
    int i = 0;
    int cantTAM = cantidadRegistrosTipoArticuloMedicamento();
    for(i=0; i<cantTAM; i++){
        aux.leerDeDisco(i);
        if(aux.getIdTipoArticuloMedicamento() == idTipoArticuloMedicamento){
            return i;
        }
    }
    return -1;
}
void buscarTipoArticuloMedicamentoPorID()
{
    int id, idTAM;
    cout << "ID del Tipo de Articulo: ";
    cin >> id;

    idTAM = buscarTipoArticuloMedicamento(id);
    if (idTAM >= 0){
        TipoArticuloMedicamento reg;
        reg.leerDeDisco(idTAM);
        cout << endl << reg.toString();
    }
    else{
        cout << endl << "No existe el articulo";
    }
}

bool editarTipoArticuloMedicamento(){

    int id, idTAM;
    string nombre;
    bool ok=false;
    cout<<"Ingrese ID del tipo de articulo de medicamento: ";
    cin>>id;

   idTAM=buscarTipoArticuloMedicamento(id);
    if(idTAM>=0){
        TipoArticuloMedicamento reg;
        reg.leerDeDisco(idTAM);
        cout<<endl<<reg.toString();
        cout<<endl<<endl;
        cout<<"Nombre Nuevo: ";
        cin>>nombre;
        reg.setNombre(nombre);
        ok=reg.guardarEnDisco(idTAM);
    }
    return ok;
}

bool eliminarTipoArticuloMedicamento(){
    int id, idTAM;
    bool ok=false;
    char confirmacion;

    cout<<"ID del Articulo a Eliminar ";
    cin>>id;

    idTAM=buscarTipoArticuloMedicamento(id);
    if(idTAM>=0){
        TipoArticuloMedicamento reg;
        reg.leerDeDisco(idTAM);
        cout<<endl<<reg.toString();
        cout<<endl<<endl;
        if(reg.getEliminado()){
            cout<<"El estudiante esta eliminado, desea restaurarlo? S/N ";
        }
        else{
            cout<<"Esta seguro de que quiere eliminarlo? S/N ";
        }

        cin>>confirmacion;

       if(confirmacion=='S' || confirmacion =='s'){
            reg.setEliminidado(!reg.getEliminado());
            ok=reg.guardarEnDisco(idTAM);
        }else{
            ok= true;
        }
    }
    else{
        cout<<"No existe articulo con ese id"<<endl;
    }
    return ok;
}

void menuTipoDeMedicamento(){
    int opcion;
    while(true){
        //rlutil::setColor(rlutil::LIGHTRED);
        rlutil::cls();
        cout << " Menú Tipo de Articulo de Medicamento" << endl;
        cout << "-------------------------------------" << endl;
        cout << "1 - Nuevo tipo de medicamento" << endl;
        cout << "2 - Editar tipo de medicamento" << endl;
        cout << "3 - Eliminar tipo de medicamento" << endl;
        cout << "4 - Listar tipos de medicamentos" << endl;
        cout << "5 - Buscar por ID" << endl;
        cout << "-------------------------------------" << endl;
        cout << "0 - Volver al menu principal" << endl << endl;

        cout << "Opción: ";
        cin >> opcion;

        rlutil::cls();

        switch(opcion){
            case 1:
                if (nuevoTipoArticuloMedicamento()){
                    mostrarMensaje("Tipo de medicamento creado correctamente");
                    rlutil::setColor(rlutil::LIGHTRED);
                }
                else{
                    mostrarMensaje("No se pudo crear el Tipo de medicamento", 4);
                    rlutil::setColor(rlutil::LIGHTRED);
                }
            break;
            case 2:
                editarTipoArticuloMedicamento();
            break;
            case 3:
                eliminarTipoArticuloMedicamento();
            break;
            case 4:
                listarTipoArticuloMedicamento();
            break;
            case 5:
               buscarTipoArticuloMedicamentoPorID();
            break;
            case 0:
                 return;
            break;
        }
        cin.ignore();
        rlutil::anykey();
    }


}




















