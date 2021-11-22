#ifndef EXTRAIR_ESTATISTICAS_HPP
#define EXTRAIR_ESTATISTICAS_HPP

#include <string>
#include <vector>
#include "Dado.hpp"
#include "DadosEstatisticos.hpp"
#include <stdexcept>

class ExtrairEstatisticas {
    public:
        DadosEstatisticos* obterDadosEstatisticos(const std::string& nomeArq) {
            if (!this->checarFormatoSuportado(nomeArq)) {
                throw std::invalid_argument{"Formato não suportado."};
            }

            std::vector<Dado*> dados{this->converterParaClasseDado(nomeArq)};

            DadosEstatisticos* dadosEstatisticos{this->processarDados(dados)};

            return dadosEstatisticos;
        }

    protected:
        virtual bool checarFormatoSuportado(const std::string& nomeArq) const = 0;

        virtual std::vector<Dado*> converterParaClasseDado(const std::string& nomeArq) const = 0;

        DadosEstatisticos* processarDados(const std::vector<Dado*>& dados) {
            float somaIdade{0.0};
            float somaAltura{0.0};
            float somaPeso{0.0};
            float somaSexoM{0.0};
            float somaSexoF{0.0};
            int numTotalDados{(int) dados.size()};

            std::vector<Dado*>::const_iterator it;
            it = dados.begin();

            for(; it != dados.end(); it++) {
                somaIdade += (*it)->getIdade();
                somaAltura += (*it)->getAltura();
                somaPeso += (*it)->getPeso();

                if ((*it)->getSexo() == 'm')
                    somaSexoM += 1;
                else
                    somaSexoF += 1;
            }

            DadosEstatisticos* dadosEstatisticos{new DadosEstatisticos(
                    numTotalDados,
                    somaIdade/numTotalDados,
                    somaAltura/numTotalDados,
                    somaPeso/numTotalDados,
                    100*somaSexoM/numTotalDados,
                    100*somaSexoF/numTotalDados
                    )};

            return dadosEstatisticos;
        }
};

#endif
