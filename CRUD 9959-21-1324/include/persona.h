#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

//Declaracion de la clase persona con sus atributos y sus metodos
class persona
{
	private:
		std::string id,name,phone,college,address;
	public:
		void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
		~persona();
};


#endif // PERSONA_H
