#include "validaCpf/validaCpf.h"
#include "geraCpf/geraCpf.h"

#include <string>

using namespace std;

int main() {
    IvalidaCpf *verificar_cpf = new validaCpf();

    IRgeraCpf *gerar_cpf = new geraCpf();

    string meu_cpf;

    gerar_cpf->connect(verificar_cpf);

    gerar_cpf->gerar_cpf();

    return 0;
}
