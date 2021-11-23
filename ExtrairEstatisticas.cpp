#include "ExtrairEstatisticas.hpp"
#include "bibliotecas/json.hpp"
#include <stdexcept>

DadosEstatisticos* ExtrairEstatisticas::obterDadosEstatisticos(const std::string& nomeArq) const {
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

bool ExtrairEstatisticas::checarArquivo(const std::string& nomeArq) const { return true; }

std::ifstream ExtrairEstatisticas::abrirArquivo(const std::string& nomeArq) const {
    std::ifstream arq(nomeArq);

    return arq;
}

DadosEstatisticos* ExtrairEstatisticas::processarDados(const std::vector<Dado*>& dados) const {
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

void ExtrairEstatisticas::fecharArquivo(std::ifstream& arq) const {
    arq.close();
}

void ExtrairEstatisticas::limparDados(std::vector<Dado*>& dados) const {
    std::vector<Dado*>::const_iterator it{dados.begin()};

    for(; it != dados.end(); it++)
        delete (*it);
}
