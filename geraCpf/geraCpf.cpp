#include "geraCpf.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void geraCpf::connect(IvalidaCpf *componente) { // Função de Acoplamento com o comp. valida
    this->valida = componente;
}

void geraCpf::gerar_cpf() { // Gera um CPF e usa o componente valida para validar
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
            cout << "O CPF GERADO " << cpf << " É VALIDO" << " ";
        } else {
            cout << " O CPF GERADO "<< cpf << " É INVALIDO" << " ";
        }
    }else{
        cout << "Interface do Componente validaCpf não está conectada!" << "\n";
    }
}

