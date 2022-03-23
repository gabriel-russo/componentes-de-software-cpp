#include "../validaCpf/validaCpf.h"
#include <string>

using namespace std;

#ifndef COMPONENTES_GERACPF_H // Evitar redefinição de classe
#define COMPONENTES_GERACPF_H

class IRgeraCpf{
public:
    virtual void connect(IvalidaCpf *valida)=0;
    virtual void gerar_cpf()=0;
};

class geraCpf: public IRgeraCpf{
private:
    IvalidaCpf *valida = nullptr;
public:
    void connect(IvalidaCpf *componente) override;
    void gerar_cpf() override;
};

#endif //COMPONENTES_GERACPF_H