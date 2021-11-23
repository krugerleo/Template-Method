#ifndef EXTRAIR_ESTATISTICAS_HPP
#define EXTRAIR_ESTATISTICAS_HPP

#include <string>
#include <vector>
#include <fstream>
#include "Dado.hpp"
#include "DadosEstatisticos.hpp"

class ExtrairEstatisticas {
    public:
        DadosEstatisticos* obterDadosEstatisticos(const std::string& nomeArq) const;

    protected:
        virtual bool checarArquivo(const std::string& nomeArq) const;

        virtual std::ifstream abrirArquivo(const std::string& nomeArq) const;

        virtual std::vector<Dado*> converterParaClasseDado(std::ifstream& arq) const = 0;

        DadosEstatisticos* processarDados(const std::vector<Dado*>& dados) const;

        virtual void fecharArquivo(std::ifstream& arq) const;

        void limparDados(std::vector<Dado*>& dados) const;
};

#endif
