#include <string>
#include<iostream>
#include "validaCpf.h"

using namespace std;

int validaCpf::valorDigito(int somatoria) {
    int digito = 0;

    if (somatoria <= 1) {// se for 1 ou 0 ...
        digito = 0;
    } else { // se for 2, 3, 4, 5, 6, 7, 8, 9 ou 10
        digito = 11 - somatoria;
    }

    return digito;
}

bool validaCpf::validar(string *cpf) {// 052 658 683 48
    int multiplicador = 10; // Multiplicador de algarismos
    int digitoJ = -1; // Variavel para guardar o digito verificador J ao final
    int digitoK = -1; // Variavel para guardar o digito verificador J ao final
    int somatoriaJ = 0; // Variavel para guardar a soma para verificar o J
    int somatoriaK = 0; // Variavel para guardar a soma para verificar o K
    for (char &ch: *cpf) {
        if (int(ch) == 46 || int(ch) == 45) {
            ; // Se for . ou - não fazer nada
        }else {
            if (multiplicador >= 2) { // O multiplicador irá até o 2 para achar o digito J primeiro
                somatoriaJ += multiplicador * ((int) ch - 48);
                somatoriaK += (multiplicador + 1) * ((int) ch - 48);
                multiplicador--;
            }else {
                if (digitoJ == -1) { // Setar primeiro o J, quando tiver com valor irá para o digito K
                    somatoriaJ = somatoriaJ % 11;
                    digitoJ = validaCpf::valorDigito(somatoriaJ);
                    somatoriaK += (multiplicador + 1) * digitoJ; // quando obtiver o valor do digito J, termine a mult.
                }else {
                    somatoriaK = somatoriaK % 11;
                    digitoK = validaCpf::valorDigito(somatoriaK);
                }
            }
        }
    }

    string digitosVerif = cpf->substr(cpf->length() - 2); // Pega os 2 ultimos numeros da string
    if ((int(digitosVerif[0]) - 48) == digitoJ && (int(digitosVerif[1]) - 48) == digitoK) {
        return true;
    } else {
        return false;
    }
}


