#include <string>
#include<iostream>
#include "validaCpf.h"

using namespace std;

bool validaCpf::validar(string *cpf){
    int k=11; // Multiplicação para achar o K
    int j=10; // Multiplicação para achar o J
    int digitoJ = -1; // Variavel para guardar o digito verificador J
    int digitoK = -1; // Variavel para guardar o digito verificador J
    int somatoriaJ = 0; // Variavel para guardar a soma para verificar o J
    int somatoriaK = 0; // Variavel para guardar a soma para verificar o K
    for (int x = 0; x <2;x++) {
        for (char &ch: *cpf) {
            if (int(ch) == 46 || int(ch) == 45) {
                ; // Se for . ou - não fazer nada
            } else {
                if (j >= 2) { // Achar digito verificador J
                    somatoriaJ += j * ((int) ch - 48); // faz a multiplicação em todas os digitos
                    j--; // OBS: (int) ch - 48 é para achar o digito exato na tabela ascii
                } else { // quando acabar de multiplicar
                    if (digitoJ == -1) { // se não tiver digito J com valor
                        somatoriaJ = somatoriaJ % 11;
                        if (somatoriaJ <= 1) {// se for 1 ou 0 ...
                            digitoJ = 0;
                        } else { // se for 2, 3, 4, 5, 6, 7, 8, 9 ou 10
                            digitoJ = 11 - somatoriaJ;
                        }
                    }
                }
                if(k>=2){ // digito K ...
                    somatoriaK += k * ((int) ch - 48);
                    k--;
                }else {
                    if (digitoK == -1) {
                        somatoriaK = somatoriaK % 11;
                        if (somatoriaK <= 1) {
                            digitoK = 0;
                        } else {
                            digitoK = 11 - somatoriaK;
                        }
                    }
                }
            }
        }
    }
    string digitosVerificadores = cpf->substr(cpf->length() - 2); // Pega os 2 ultimos numeros da string
    if((int(digitosVerificadores[0]) - 48) == digitoJ && (int(digitosVerificadores[1]) - 48) == digitoK){
        return true;
    }else{
        return false;
    }
}


