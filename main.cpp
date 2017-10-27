#include "lista.h"


int main(int argc, char *argv[])
{

    ListaSimple * l = new ListaSimple();

    l->insertarAlInicio(40);
    l->insertarAlInicio(30);
    l->insertarAlInicio(20);
    l->insertarAlInicio(10);

    l->imprimir();
    l->primerNodo->siguiente->dato++;
    cout << l->primerNodo->dato<< endl;
    cout << l->primerNodo->siguiente->siguiente->dato<< endl;
    l->imprimir();
    Nodo * b = l->borrarAlInicio();
    cout << "Se elimino el "<< b->dato<<endl;
    l->imprimir();
    
 system("PAUSE");
    return EXIT_SUCCESS; 


}

