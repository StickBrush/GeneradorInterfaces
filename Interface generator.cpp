#include <iostream>
#include <string>
#include <fstream>
 using namespace std;

void toFile(){
	ofstream outer;
	int max;
	string nombre;
	outer.open("interface.cpp");
	if(outer.is_open()){
		cout << "What's your program name?" << endl;
		getline(cin, name);
		cout << "How many options does your program have? (apart from exit)" << endl;
		cin >> max;
		string options [max];
		string instructions[max];
		for (int i=0;i<max;i++){
			cout << "What's the name of the " << i+1 << "th option?" << endl;
			getline(cin, options[i]);
			cout << "What code does the " << i+1 << "th option execute?" << endl;
			getline(cin, instructions[i]);
		}
		cout << "GENERATING CODE..." << endl;
		outer << "//Code from StickBrush's Interface Generator" << endl;
		outer << "void UI(){" << endl;
		outer << "int option" << endl;
		outer << "bool exit=false" << endl;
		outer << "cout << \"Welcome to " << name <<"! \" << endl;" << endl;
		outer << "while(!exit){" << endl;
		outer << "cout << \"What do you want to do?\" << endl;" << endl;
		for (int i=0;i<max;i++){
			outer<< "cout << \"" << i+1 <<") Execute " << options[i] << "\" << endl;" << endl;
		}
		outer<< "cout << \"" << max+1 <<") Exit\" << endl;" << endl;
		outer << "cin >> option" << endl;
		outer << "switch(option){" << endl;
		for(int i=0;i<max;i++){
			outer << "case " << i+1 << ":" << endl;
			outer << instructions[i] << ";" << endl;
			outer << "break;" << endl;
		}
		outer << "case " << max+1 << ":" << endl;
		outer << "exit=true;" << endl;
		outer << "break;" << endl;
		outer << "default:" << endl;
		outer << "cout << \"ERROR. Number not recognized\" << endl;" << endl;
		outer << "break;" << endl;
		outer << "}" << endl;
		outer << "}" << endl;
		outer << "}" << endl;
		cout << "Code generated!" << endl;
		
	}
	else
		cout << "ERROR" << endl;
}

void toScreen(){
	int max;
	string nombre;
	cout << "What's your program name?" << endl;
		getline(cin, name);
		cout << "How many options does your program have? (apart from exit)" << endl;
		cin >> max;
		string options [max];
		string instructions[max];
		for (int i=0;i<max;i++){
			cout << "What's the name of the " << i+1 << "th option?" << endl;
			getline(cin, options[i]);
			cout << "What code does the " << i+1 << "th option execute?" << endl;
			getline(cin, instructions[i]);
		}
		cout << "GENERATING CODE..." << endl;
		cout << "//Code from StickBrush's Interface Generator" << endl;
		cout << "void UI(){" << endl;
		cout << "int option" << endl;
		cout << "bool exit=false" << endl;
		cout << "cout << \"Welcome to " << name <<"! \" << endl;" << endl;
		cout << "while(!exit){" << endl;
		cout << "cout << \"What do you want to do?\" << endl;" << endl;
		for (int i=0;i<max;i++){
			outer<< "cout << \"" << i+1 <<") Execute " << options[i] << "\" << endl;" << endl;
		}
		cout<< "cout << \"" << max+1 <<") Exit\" << endl;" << endl;
		cout << "cin >> option" << endl;
		cout << "switch(option){" << endl;
		for(int i=0;i<max;i++){
			cout << "case " << i+1 << ":" << endl;
			cout << instructions[i] << ";" << endl;
			cout << "break;" << endl;
		}
		cout << "case " << max+1 << ":" << endl;
		cout << "exit=true;" << endl;
		cout << "break;" << endl;
		cout << "default:" << endl;
		cout << "cout << \"ERROR. Number not recognized\" << endl;" << endl;
		cout << "break;" << endl;
		cout << "}" << endl;
		cout << "}" << endl;
		cout << "}" << endl;
		cout << "//////////////////////////////////" << endl;
		cout << "Code generated!" << endl;
		
	}
	else
		cout << "ERROR" << endl;
}

int main{
	int opcion;
	bool salir=false;
	cout << "Welcome to StickBrush's C++ interface generator!" << endl;
	while(!salir){
	cout << "Which will be the output?" << endl;
	cout << "1) interface.cpp file (inside this program's folder)" << endl;
	cout << "2) On-screen output" << endl;
	cin >> option;
		switch(option){
			case 1:
			toFile();
			salir=true;
			break;
			case 2:
			toScreen();
			salir=true;
			break;
			default:
			cout << "ERROR. Number not recognized" << endl;
			break;
		}
	}
}