#include <string>

using namespace std;

#ifndef COMPONENTES_VALIDACPF_H
#define COMPONENTES_VALIDACPF_H

class IvalidaCpf{
public:
    virtual bool validar(string *cpf)=0;
};

class validaCpf: public IvalidaCpf {
public:
    bool validar(string *cpf) override;
    static int valorDigito(int somatoria);
};

#endif