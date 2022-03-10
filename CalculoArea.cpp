#include <iostream>
#include <cmath>
using namespace std;

void areaDelCirculo(void);
void areaDelCuadrado(void);
void areaDelRectangulo(void);
void areaDelTriangulo(void);
void mostrarArea(float area);

const float Pi = 3.14154;

int main(){
 char opcion;
 cout<<"Selecciona el area que deseas calcular"<<endl;
 cout<<" a) Circulo\n b) Cuadrado\n c) Rectangulo\n d) Triangulo\n"; cin>>opcion;
 switch(opcion){
  case 'a': areaDelCirculo(); break;
  case 'b': areaDelCuadrado(); break;
  case 'c': areaDelRectangulo(); break;
  case 'd': areaDelTriangulo(); break;
 }
 return 0;
}

void mostrarArea(float area){   cout<<"El area es: "<<area<<endl; return;  }
/*
void areaDelCirculo(void){
 float radio, area = 0;
 cout<<"Ingresa el radio: "; cin>>radio;
 area = pow(radio,2) * Pi;
 mostrarArea(area);
 return;
}

void areaDelCuadrado(void){
 float lado, area = 0;
 cout<<"Ingresa un lado: "; cin>>lado;
 area = pow(lado,2);
 mostrarArea(area);
 return;
}*/

void areaDelRectangulo(void){
 float base, altura, area = 0;
 cout<<"Ingresa la base: "; cin>>base;
 cout<<"Ingresa la altura: "; cin>>altura;
 area = base * altura;
 mostrarArea(area);
 return;
}
/*
void areaDelTriangulo(void){
 float base, altura, area = 0;
 cout<<"Ingresa la base: "; cin>>base;
 cout<<"Ingresa la altura: "; cin>>altura;
 area = (base * altura) / 2;
 mostrarArea(area);
 return;
}*/
