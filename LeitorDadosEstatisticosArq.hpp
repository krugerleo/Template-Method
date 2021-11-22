#ifndef IMPRIMIR_DADOS_ESTATISTICOS_ARQ
#define IMPRIMIR_DADOS_ESTATISTICOS_ARQ

#include <iostream>
#include <string>
#include "ExtrairEstatisticas.hpp"
#include "DadosEstatisticos.hpp"

class LeitorDadosEstatisticosArq {
    public:
        LeitorDadosEstatisticosArq(ExtrairEstatisticas* ee)
            :ee(ee){}

        void imprimirDadosEstatisticos(const std::string nomeArq) {

            DadosEstatisticos* de{ee->obterDadosEstatisticos(nomeArq)};

            std::cout
                << "Numero Total de Dados = " << de->getNumTotalDados() << std::endl
                << "Media Idade = " << de->getMediaIdade() << std::endl
                << "Media Altura = " << de->getMediaAltura() << std::endl
                << "Media Peso = " << de->getMediaPesoa() << std::endl
                << "Porcentagem Sexo M = " << de->getPorcentagemSexoM() << std::endl
                << "Porncetagem Sexo F = " << de->getPorcentagemSexoF() << std::endl
                << std::endl;

            delete de;
        }
    private:
        ExtrairEstatisticas* ee;
};

#endif
