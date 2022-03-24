#include "geraCpf.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void geraCpf::connect(IvalidaCpf *componente) {
    this->valida = componente;
}

void geraCpf::gerar_cpf() {
    string cpf;

    srand(time(0));  // Initialize random number generator.
    for(int i=0;i<14;i++) {
        if (i == 3 || i == 7) {
            cpf += ".";
        }else {
            if (i == 11) {
                cpf += "-";
            }else{
                cpf += to_string(rand() % 10);
            }
        }
    }
    cout << "UM CPF FOI GERADO: " << cpf << "\n";

    if(this->valida != nullptr) {
        if (this->valida->validar(&cpf)) {
            cout << "O CPF GERADO " << cpf << " EH VALIDO" << " ";
        } else {
            cout << "CPF "<< cpf << " EH INVALIDO" << " ";
        }
    }else{
        cout << "Interface do Componente de validacao nao conectada!" << "\n";
    }
}

