#include "persona.h"
#include <iostream>
#include<conio.h>
#include<fstream>
#include <iomanip>
//Destructor
persona::~persona(){

}

//Creacion del metodo que despliega el menu
void persona::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	std::cout<<"\t\t\t-------------------------------"<<std::endl;
	std::cout<<"\t\t\t |   SISTEMA GESTION PERSONAS  |"<<std::endl;
	std::cout<<"\t\t\t-------------------------------"<<std::endl;
	std::cout<<"\t\t\t 1. Ingreso Personas"<<std::endl;
	std::cout<<"\t\t\t 2. Despliegue Personas"<<std::endl;
	std::cout<<"\t\t\t 3. Modifica Personas"<<std::endl;
	std::cout<<"\t\t\t 4. Busca Personas"<<std::endl;
	std::cout<<"\t\t\t 5. Borra Personas"<<std::endl;
	std::cout<<"\t\t\t 6. Exit"<<std::endl;

	std::cout<<"\t\t\t-------------------------------"<<std::endl;
	std::cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5/6]"<<std::endl;
	std::cout<<"\t\t\t-------------------------------"<<std::endl;
	std::cout<<"Ingresa tu Opcion: ";
    std::cin>>choice;

    //Switch para leer la opcion del usuario y según eso ejecutar el metodo correspondiente
    switch(choice)
    {
    case 1:
    	do
    	{
    	    //Ejecucion del metodo insert que agrega personas a la base de datos
    		insert();
    		std::cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		std::cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		display();
		break;
	case 3:
		modify();
		break;
	case 4:
		search();
		break;
	case 5:
		delet();
		break;
	case 6:
		exit(0);
	default:
		std::cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 6);
}

//Creacion del metodo encargado de añadir informacion a la base de datos
void persona::insert()
{
	system("cls");
	std::fstream file;
	std::cout<<"\n------------------------------------------------------------------------------------------------------------------------";
	std::cout<<"\n-------------------------------------------------Agregar detalles Persona ---------------------------------------------"<<std::endl;
	std::cout<<"\t\t\tIngresa Id Persona         : ";
	std::cin>>id;
	std::cout<<"\t\t\tIngresa Nombre Persona     : ";
	std::cin>>name;
	std::cout<<"\t\t\tIngresa Telefono Persona   : ";
	std::cin>>phone;
	std::cout<<"\t\t\tIngresa Universidad Persona: ";
	std::cin>>college;
	std::cout<<"\t\t\tIngresa Direccion Persona  : ";
	std::cin>>address;
	file.open("ParticipantRecord.txt", ios::app | ios::out);
	//El "setw" nos permite definir el límite del tamaño para cada string ingresado
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
	file.close();
}

//Creacion del metodo encargado de mostrar a todos los usuarios que se encuentren registrados en la base de datos
void persona::display()
{
	system("cls");
	fstream file;
	int total=0;
	std::cout<<"\n-------------------------Tabla de Detalles de Personas -------------------------"<<std::endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		std::cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> name >> phone >> college >> address;
		while(!file.eof())
		{
			total++;
			std::cout<<"\n\n\t\t\t Id Persona: "<<id<<std::endl;
			std::cout<<"\t\t\t Nombre Persona: "<<name<<std::endl;
			std::cout<<"\t\t\t Telefono Persona: "<<phone<<std::endl;
			std::cout<<"\t\t\t Universidad Persona: "<<college<<std::endl;
			std::cout<<"\t\t\t Direccion Persona: "<<address<<std::endl;
			file >> id >> name >> phone >> college >> address;
		}
		if(total==0)
		{
			std::cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}

//Creacion del metodo encargado de modificar la informacion de un usuario previamente registrado
void persona::modify()
{
	system("cls");
	fstream file,file1;
	std::string participant_id;
	int found=0;
	std::cout<<"\n-------------------------Modificacion Detalles Persona-------------------------"<<std::endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		std::cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		std::cout<<"\n Ingrese Id de la personas que quiere modificar: ";
		std::cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> phone >> college >> address;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
			}
			else
			{
				std::cout<<"\t\t\tIngrese Id Persona: ";
				std::cin>>id;
				std::cout<<"\t\t\tIngrese Nombre Persona: ";
				std::cin>>name;
				std::cout<<"\t\t\tIngrese Telefono Persona: ";
				std::cin>>phone;
				std::cout<<"\t\t\tIngrese Universidad Persona: ";
				std::cin>>college;
				std::cout<<"\t\t\tIngrese Direccion Persona: ";
				std::cin>>address;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
				found++;
			}
			file >> id >> name >> phone >> college >> address;

		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}

//Metodo encargado de buscar usuarios en la base de datos segun su Id
void persona::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		std::cout<<"\n-------------------------Datos de la Persona buscada------------------------"<<std::endl;
		std::cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		std::string participant_id;
		std::cout<<"\n-------------------------Datos de Persona buscada------------------------"<<std::endl;
		std::cout<<"\nIngrese Id de la Persona que quiere buscar: ";
		std::cin>>participant_id;
		file >> id >> name >> phone >> college >> address;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				std::cout<<"\n\n\t\t\t Id Persona: "<<id<<std::endl;
				std::cout<<"\t\t\t Nombre Persona: "<<name<<std::endl;
				std::cout<<"\t\t\t Telefono Persona: "<<phone<<std::endl;
				std::cout<<"\t\t\t Universidad Persona: "<<college<<std::endl;
				std::cout<<"\t\t\t Direccion Persona: "<<address<<std::endl;
				found++;
			}
			file >> id >> name >> phone >> college >> address;
		}
		if(found==0)
		{
			std::cout<<"\n\t\t\t Persona no encontrada...";
		}
		file.close();
	}
}

//Metodo encargado de eliminar a cualquier usuario previamente registrado y su informacion de la base de datos
void persona::delet()
{
	system("cls");
	fstream file,file1;
	std::string participant_id;
	int found=0;
	std::cout<<"\n-------------------------Detalles Persona a Borrar-------------------------"<<std::endl;
	file.open("ParticipantRecord.txt",ios::in);
	if(!file)
	{
		std::cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		std::cout<<"\n Ingrese el Id de la Persona que quiere borrar: ";
		std::cin>>participant_id;
		file1.open("Record.txt",ios::app | ios::out);
		file >> id >> name >> phone >> college >> address;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< phone <<std::left<<std::setw(15)<< college <<std::left<<std::setw(15)<< address << "\n";
			}
			else
			{
				found++;
				std::cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> name >> phone >> college >> address;
		}
		if(found==0)
		{
			std::cout<<"\n\t\t\t Id Persona no encontrado...";
		}
		file1.close();
		file.close();
		remove("ParticipantRecord.txt");
		rename("Record.txt","ParticipantRecord.txt");
	}
}

