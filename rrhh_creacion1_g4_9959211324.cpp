#include <iostream>
using namespace std;

class Persona{
public:
    string Nombre, Direccion, Empresa;
    int ID, Edad, Telefono;
  Persona(string iNombre, int iID, int iEdad, int iTelefono, string iDireccion, string iEmpresa){
    Nombre = iNombre;
    ID = iID;
    Edad = iEdad;
    Telefono = iTelefono;
    Direccion = iDireccion;
    Empresa = iEmpresa;
  };
  void Obtener_Edad(){
    cout<<"Estas en el metodo Obtener Edad"<<endl;
  };
 void Registrar(){
    cout<<"Estas en el metodo Registrar"<<endl;
  };
  void Modificar(){
    cout<<"Estas en el metodo Modificar"<<endl;
  };
  void Eliminar(){
    cout<<"Estas en el metodo Eliminar"<<endl;
  };
  void Consultar(){
    cout<<"Estas en el metodo Consultar"<<endl;
  };

private:

};

class Empleados : public Persona{
    public:
        Empleados(string iNombre, int iID, int iEdad, int iTelefono, string iDireccion, string iEmpresa):Persona(iNombre, iID, iEdad, iTelefono, iDireccion, iEmpresa){
            Nombre = iNombre;
            ID = iID;
            Edad = iEdad;
            Telefono = iTelefono;
            Direccion = iDireccion;
            Empresa = iEmpresa;
    };
};

class Gerencia : public Persona{
public:
    Gerencia(string iNombre, int iID, int iEdad, int iTelefono, string iDireccion, string iEmpresa):Persona(iNombre, iID, iEdad, iTelefono, iDireccion, iEmpresa){
    Nombre = iNombre;
    ID = iID;
    Edad = iEdad;
    Telefono = iTelefono;
    Direccion = iDireccion;
    Empresa = iEmpresa;
    };
};

class Administradores : public Persona{
public:
    Administradores(string iNombre, int iID, int iEdad, int iTelefono, string iDireccion, string iEmpresa):Persona(iNombre, iID, iEdad, iTelefono, iDireccion, iEmpresa){
    Nombre = iNombre;
    ID = iID;
    Edad = iEdad;
    Telefono = iTelefono;
    Direccion = iDireccion;
    Empresa = iEmpresa;
    };
};

class Reclutadores : public Persona{
public:
    Reclutadores(string iNombre, int iID, int iEdad, int iTelefono, string iDireccion, string iEmpresa):Persona(iNombre, iID, iEdad, iTelefono, iDireccion, iEmpresa){
    Nombre = iNombre;
    ID = iID;
    Edad = iEdad;
    Telefono = iTelefono;
    Direccion = iDireccion;
    Empresa = iEmpresa;
    };
};

class Supervisores : public Persona{
public:
    Supervisores(string iNombre, int iID, int iEdad, int iTelefono, string iDireccion, string iEmpresa):Persona(iNombre, iID, iEdad, iTelefono, iDireccion, iEmpresa){
    Nombre = iNombre;
    ID = iID;
    Edad = iEdad;
    Telefono = iTelefono;
    Direccion = iDireccion;
    Empresa = iEmpresa;
    };
};

int main(){
    Empleados Juan ("Juan",45568,20,54895874,"10 av, Casa 5, Zona 16","Apple" );
    Gerencia Alberto("Alberto",46587,35,45968745,"Apto. 18, Edificio Las Rosas, Zona 14","Samsung");

    Juan.Obtener_Edad();
    Juan.Registrar();
    Juan.Modificar();
    Juan.Eliminar();
    Juan.Consultar();

    Alberto.Obtener_Edad();
    Alberto.Registrar();
    Alberto.Modificar();
    Alberto.Eliminar();
    Alberto.Consultar();
return 0;
};
