#include <iostream>
using namespace std;

class Persona
{
    public:
        int Edad, Id, Direccion, telefono;
        Persona ( int iEdad, int iId, int iDireccion, int itelefono)

        {
            Edad= iEdad ;
            Id = iId;
            Direccion = iDireccion;
            telefono = itelefono;


        }
    void Mostrar()
    {
        cout<<"Estás en el método de Obtener Edad: " <<Edad<< endl;
        cout<<"Estas en el metodo de registrar id: " <<Id<< endl;
        cout<<"Estas en el metodo de modificar Direccion: " <<Direccion<< endl;
        cout<<"Estas en el metodo de eliminar: " <<telefono<< endl;
    }

private:


};
class empleado : public Persona
{
public:
    empleado (int iEdad, int iId,int iDireccion,int itelefono) : Persona( iEdad, iId, iDireccion, itelefono)
    {
            Edad= iEdad + 5;
            Id = iId;
            Direccion = iDireccion;
            telefono = itelefono;

    }
private:

};

int main ()
{
    Persona Juanito( 18, 9959-21, 307, 4147222);
    empleado Carlos( 18, 9959-21, 307, 4147222);
    Juanito.Mostrar();
    Carlos.Mostrar();
    return 0;
}









