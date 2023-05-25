#include <iostream>
#include <iomanip>
#include <cstring>
#include "Person.h"
#include "arbol.h"

using std::cout;
using std::endl;


int main()
{

    ArbolB<Student> Miarbol;
    Student *people[MAX] { };  // will be initialized to nullptrs
    people[0] = new Student("Juan", "Sun", 'R', "MSc.", 3.8, "C++", "UMD8567");
    people[1] = new Student("Zack", "Moon", 'R', "Dr.", 3.8, "C++", "UMD1234");  // derived instances
    people[2] = new Student("Gabby", "Doone", 'A', "Dr.", 3.9, "C++", "GWU4321");
    people[3] = new Student("Jo", "Li", 'H', "Ms.", 3.7, "C++", "UD1234");
    people[4] = new Student("Sam", "Lo", 'A', "Mr.", 3.5, "C++", "UD2245");
    people[5] = new Student("Ren", "Ze", 'A', "Dr.", 3.8, "C++", "BU5563");

    for (int i = 0; i < MAX; i++)
    {
       people[i]->IsA();
       cout << "  ";
       people[i]->Print();
    }

    for (int i = 0; i < MAX; i++)
        Miarbol.inserta(*people[i]);

    if(Miarbol.localiza(*people[3])!=nullptr){
            cout<<" \n Esta en la lista: \n"<<endl;
            people[3]->Print();
    }
     Miarbol.elimina(Miarbol.localiza(*people[3]));

    if(Miarbol.localiza(*people[3])!=nullptr){
            cout<<" \n Esta en la lista: \n"<<endl;
            people[3]->Print();
    }
    else{
        cout<<" \n No se encuentra ya en la lista: \n"<<endl;
    }


    // Older style looping for comparison with preferred loop style, just above
     for (int i = 0; i < MAX; i++)
       delete people[i];   // engage virtual dest. sequence

    return 0;
}
