#include "validaCpf/validaCpf.h"
#include "geraCpf/geraCpf.h"
#include <string>

using namespace std;

int main() {
    IvalidaCpf *verificar_cpf = new validaCpf();

    IgeraCpf *gerar_cpf = new geraCpf();

    gerar_cpf->connect(verificar_cpf);

    gerar_cpf->gerar_cpf();

    return 0;
}
