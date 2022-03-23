#include <string>
#include<iostream>
#include "validaCpf.h"

using namespace std;

bool validaCpf::validar(string *cpf){
    int k=11; // Multiplicação para achar o K
    int j=10; // Multiplicação para achar o J
    int digitoJ = 0; // Variavel para guardar o digito verificador J
    int digitoK = 0; // Variavel para guardar o digito verificador J
    int somatoriaJ = 0; // Variavel para guardar a soma para verificar o J
    int somatoriaK = 0; // Variavel para guardar a soma para verificar o K
    for (int x = 0; x <2;x++) {
        for (char &ch: *cpf) {
            if (int(ch) == 46 || int(ch) == 45) {
                ;
            } else {
                if (j >= 2) { // Achar digito verificador J
                    somatoriaJ += j * ((int) ch - 48);
                    j--;
                } else {
                    if (digitoJ == 0) {
                        somatoriaJ = somatoriaJ % 11;
                        if (somatoriaJ <= 1) {
                            digitoJ = 0;
                        } else {
                            digitoJ = 11 - somatoriaJ;
                        }
                    }
                }
                if(k>=2){
                    somatoriaK += k * ((int) ch - 48);
                    k--;
                }else {
                    if (digitoK == 0) {
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
    string digitosVerificadores = cpf->substr(cpf->length() - 2);
    if((int(digitosVerificadores[0]) - 48) == digitoJ && (int(digitosVerificadores[1]) - 48) == digitoK){
        return true;
    }else{
        return false;
    }
}


