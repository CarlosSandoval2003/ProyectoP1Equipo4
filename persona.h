#ifndef PERSONA_H
#define PERSONA_H
#include<iostream>

using namespace std;

class persona
{
    public:
        persona();
		void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
    private:
        std :: string id,name,phone,college,address;
};

#endif // PERSONA_H
