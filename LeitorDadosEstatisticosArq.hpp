#ifndef IMPRIMIR_DADOS_ESTATISTICOS_ARQ
#define IMPRIMIR_DADOS_ESTATISTICOS_ARQ

#include <iostream>
#include <string>
#include "ExtrairEstatisticas.hpp"
#include "DadosEstatisticos.hpp"

class LeitorDadosEstatisticosArq {
    public:
        LeitorDadosEstatisticosArq(ExtrairEstatisticas* ee);

        void imprimirDadosEstatisticos(const std::string nomeArq) const;
    private:
        ExtrairEstatisticas* ee;
};

#endif
