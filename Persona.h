#include<iostream>
#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

class persona
{

        public:

            void menu();

                    void insert();
                    void display();
                    void modify();
                    void search();
                    void delet();

            persona();
            virtual ~persona();

    protected:
        private:
            std :: string id,name,phone,college,address;


};

#endif // PERSONA_H
