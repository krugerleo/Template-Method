#ifndef EXTRAIR_ESTATISTICAS_HPP
#define EXTRAIR_ESTATISTICAS_HPP

#include <string>
#include <vector>
#include <fstream>
#include "Dado.hpp"
#include "DadosEstatisticos.hpp"
#include <stdexcept>

class ExtrairEstatisticas {
    public:
        DadosEstatisticos* obterDadosEstatisticos(const std::string& nomeArq) {
            if (!this->checarArquivo(nomeArq)) {
                throw std::runtime_error{"Arquivo não passou na checagem"};
            }

            std::ifstream arq{this->abrirArquivo(nomeArq)};

            std::vector<Dado*> dados{this->converterParaClasseDado(arq)};

            DadosEstatisticos* dadosEstatisticos{this->processarDados(dados)};

            this->fecharArquivo(arq);

            this->limparDados(dados);

            return dadosEstatisticos;
        }

    protected:
        virtual bool checarArquivo(const std::string& nomeArq) const { return true; }

        virtual std::ifstream abrirArquivo(const std::string& nomeArq) const {
            std::ifstream arq(nomeArq);

            return arq;
        }

        virtual std::vector<Dado*> converterParaClasseDado(std::ifstream& arq) const = 0;

        DadosEstatisticos* processarDados(const std::vector<Dado*>& dados) const {
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

        virtual void fecharArquivo(std::ifstream& arq) const {
            arq.close();
        }

        virtual void limparDados(std::vector<Dado*>& dados) const {
            std::vector<Dado*>::const_iterator it{dados.begin()};

            for(; it != dados.end(); it++)
                delete (*it);
        }
};

#endif
