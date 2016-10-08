#include <iostream>
#include <string>
#include <fstream>
 using namespace std;

void toFile(){
	ofstream outer;
	int max;
	string nombre;
	outer.open("interfaz.cpp");
	if(outer.is_open()){
		cout << "¿Cuál es el nombre de tu programa?" << endl;
		getline(cin, nombre);
		cout << "¿Cuántas opciones tiene tu programa? (sin contar salida)" << endl;
		cin >> max;
		string opciones [max];
		string instrucciones[max];
		for (int i=0;i<max;i++){
			cout << "¿Qué nombre tiene la opción " << i+1 << "?" << endl;
			getline(cin, opciones[i]);
			cout << "¿Qué instrucción hace la opción " << i+1 << "?" << endl;
			getline(cin, instrucciones[i]);
		}
		cout << "GENERANDO CÓDIGO..." << endl;
		outer << "//Código del Generador de Interfaces de StickBrush" << endl;
		outer << "void UI(){" << endl;
		outer << "int opcion" << endl;
		outer << "bool salir=false" << endl;
		outer << "cout << \"¡Bienvenido a " << nombre <<"! \" << endl;" << endl;
		outer << "while(!salir){" << endl;
		outer << "cout << \"¿Qué desea hacer?\" << endl;" << endl;
		for (int i=0;i<max;i++){
			outer<< "cout << \"" << i+1 <<") Ejecutar " << opciones[i] << "\" << endl;" << endl;
		}
		outer<< "cout << \"" << max+1 <<") Salir\" << endl;" << endl;
		outer << "cin >> opcion" << endl;
		outer << "switch(opcion){" << endl;
		for(int i=0;i<max;i++){
			outer << "case " << i+1 << ":" << endl;
			outer << instrucciones[i] << ";" << endl;
			outer << "break;" << endl;
		}
		outer << "case " << max+1 << ":" << endl;
		outer << "salir=true;" << endl;
		outer << "break;" << endl;
		outer << "default:" << endl;
		outer << "cout << \"ERROR. Número no reconocido\" << endl;" << endl;
		outer << "break;" << endl;
		outer << "}" << endl;
		outer << "}" << endl;
		outer << "}" << endl;
		cout << "¡Código generado!" << endl;
		
	}
	else
		cout << "ERROR" << endl;
}

void toScreen(){
	int max;
	string nombre;
	cout << "¿Cuál es el nombre de tu programa?" << endl;
		getline(cin, nombre);
		cout << "¿Cuántas opciones tiene tu programa? (sin contar salida)" << endl;
		cin >> max;
		string opciones [max];
		string instrucciones [max];
		for (int i=0;i<max;i++){
			cout << "¿Qué nombre tiene la opción " << i+1 << "?" << endl;
			getline(cin, opciones[i]);
			cout << "¿Qué instruccón hace la opción " << i+1 << "?" << endl;
			getline(cin, instrucciones[i]);
		}
		cout << "GENERANDO CÓDIGO..." << endl;
		cout << "////////////////////////" << endl;
		cout << "//Código del Generador de Interfaces de StickBrush" << endl;
		cout << "void UI(){" << endl;
		cout << "int opcion" << endl;
		cout << "bool salir=false" << endl;
		cout << "cout << \"¡Bienvenido a " << nombre <<"! \" << endl;" << endl;
		cout << "while(!salir){" << endl;
		cout << "cout << \"¿Qué desea hacer?\" << endl;" << endl;
		for (int i=0;i<max;i++){
			cout<< "cout << \"" << i+1 <<") Ejecutar " << opciones[i] << "\" << endl;" << endl;
		}
		cout<< "cout << \"" << max+1 <<") Salir\" << endl;" << endl;
		cout << "cin >> opcion" << endl;
		cout << "switch(opcion){" << endl;
		for(int i=0;i<max;i++){
			cout << "case " << i+1 << ":" << endl;
			cout << instrucciones[i] << ";" << endl;
			cout << "break;" << endl;
		}
		cout << "case " << max+1 << ":" << endl;
		cout << "salir=true;" << endl;
		cout << "break;" << endl;
		cout << "default:" << endl;
		cout << "cout << \"ERROR. Número no reconocido\" << endl;" << endl;
		cout << "break;" << endl;
		cout << "}" << endl;
		cout << "}" << endl;
		cout << "}" << endl;
}

int main{
	int opcion;
	bool salir=false;
	cout << "¡Bienvenido al generador de interfaces de C++ de StickBrush!" << endl;
	while(!salir){
	cout << "¿Cuál será la salida de tu programa?" << endl;
	cout << "1) Salida a archivo interfaz.cpp (en la carpeta del programa)" << endl;
	cout << "2) Salida por consola" << endl;
	cin >> opcion;
		switch(opcion){
			case 1:
			toFile();
			salir=true;
			break;
			case 2:
			toScreen();
			salir=true;
			break;
			default:
			cout << "ERROR. Número no reconocido" << endl;
			break;
		}
	}
}