/*
Estructura de datos.
Estudiante: Edgar Antonio Reyes Ceron.
#Carnet: RC18050.

ejercicio de arboles implementado en clases. */

#include <iostream>

using namespace std;

typedef class Arbol_binario *ABB;

class Arbol_binario{
	private:
		int nro;
		class Arbol_binario *izq, *der;
	public:
		
ABB crearNodo(int x){
	ABB nuevoNodo = new (class Arbol_binario);
	nuevoNodo->nro=x;
	nuevoNodo->izq=NULL;
	nuevoNodo->der=NULL;
	
	return nuevoNodo;
}

void insertar(ABB &arbol, int x){
	if(arbol==NULL){
		arbol=crearNodo(x);
	}
	else if(x<arbol->nro){
		insertar(arbol->izq,x);
	}
	else if(x>arbol->nro){
		insertar(arbol->der,x);
	}
}

int addin(ABB arbol, int &add){
	if(arbol!=NULL){
		addin(arbol->izq,add);
		add = add + arbol->nro;
		addin(arbol->der,add);	
	}
	return add;
}

void preOrden(ABB arbol){
	if(arbol!=NULL){
		cout<<arbol->nro<<", ";
		preOrden(arbol->izq);
		preOrden(arbol->der);
	}
}

void inOrden(ABB arbol){
	if(arbol != NULL){        
		inOrden(arbol->izq);
		cout << arbol->nro << ", ";
		inOrden(arbol->der);
	}
}

void postOrden(ABB arbol){
	if(arbol != NULL){
		cout << arbol->nro << ", ";
		postOrden(arbol->izq);
		postOrden(arbol->der);
	}
}

void verArbol(ABB arbol, int n){
	if(arbol==NULL){
		return;
	}
	
	verArbol(arbol->der,n+1);
	for(int i=0; i<n; i++){
		cout<<" ";
	}
	
	cout<<arbol->nro<<endl;
	verArbol(arbol->izq,n+1);
}

};

void Menu(){
    cout<<"\t\tMENU"<<endl;
    cout<<"1.Insertar nodos"<<endl;
    cout<<"2.Mostrar arbol"<<endl;
    cout<<"3.Recorridos"<<endl;
    cout<<"4.Salir"<<endl;
    cout<<"INGRESE UNA OPCION: ";
}

void SubMenu(){
	cout<<"\t\tSUBMENU"<<endl;
    cout<<"1.Imprimir en pre-orden"<<endl;
    cout<<"2.Imprimir en in-orden"<<endl;
    cout<<"3.Imprimir en post-orden"<<endl;
    cout<<"4.Regresar al menu principal..."<<endl;
    cout<<"INGRESE UNA OPCION: ";
}

int main(){
	Arbol_binario *arbol = new Arbol_binario();
	int n;
	int x;
	int opc, opc2;
	int sc;
	
	do{
		cout<<"Cantidad actual de nodos: "<<n<<endl;
		cout<<endl;
		Menu();
		cin>>opc;
		system("cls");
		switch(opc){
			case 1:
				cout<<"Ingrese el numero de nodos del arbol"<<endl;
				cin>>n;
				
				for(int i=0; i<n; i++){
					cout<<"Ingrese el valor del nodo"<<endl;
					cin>>x;
					arbol->insertar(arbol,x);
				}
				system("pause");
				break;
			case 2:
				cout<<"Mostrando Arbol: "<<endl;
				arbol->verArbol(arbol,0);
				cout<<"Cantidad actual de nodos: "<<n<<endl;
				cout<<endl;
			
				cout<<"La suma de todas las claves es: "<<arbol->addin(arbol,sc)<<endl;
				cout<<endl;
				
				cout<<"La altura actual del arbol es: "<<n<<endl;
				cout<<endl;
				system("pause");
				break;
			case 3:
				do{
					cout<<"Cantidad actual de nodos: "<<n<<endl;
					cout<<endl;
					SubMenu();
					cin>>opc2;
					switch(opc2){
						case 1:
							cout<<"Mostrando el arbol en PRE-orden: "<<endl;
							arbol->preOrden(arbol);
							system("pause");
							break;
						case 2:
							cout<<"Mostrando el arbol en POST-orden: "<<endl;
							arbol->postOrden(arbol);
							system("pause");
							break;
						case 3:
							cout<<"Mostrando el arbol en IN-orden: " <<endl;
							arbol->inOrden(arbol);
							system("pause");
							break;
						case 4:
							break;
					}
					system("cls");
				}while(opc2!=4);
				break;
			case 4:
				cout<<"Cerrando aplicacion..."<<endl;
				cout<<endl;
				system("pause");
				break;
		}
		system("cls");
	}while(opc!=4);
	
	return 0;
}
