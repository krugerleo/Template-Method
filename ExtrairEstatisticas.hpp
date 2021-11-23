#ifndef EXTRAIR_ESTATISTICAS_HPP
#define EXTRAIR_ESTATISTICAS_HPP

#include <string>
#include <vector>
#include <fstream>
#include "Dado.hpp"
#include "DadosEstatisticos.hpp"

class ExtrairEstatisticas {
    public:
        /* Template method - Método Template*/
        DadosEstatisticos* obterDadosEstatisticos(const std::string& nomeArq) const;

    protected:
        /* Operação gancho (hook operation) */
        virtual bool checarArquivo(const std::string& nomeArq) const;

        /* Operação concreta */
        virtual std::ifstream abrirArquivo(const std::string& nomeArq) const;

        /* Operação abstrata ou operação primitiva */
        virtual std::vector<Dado*> converterParaClasseDado(std::ifstream& arq) const = 0;

        /* Operação concreta */
        DadosEstatisticos* processarDados(const std::vector<Dado*>& dados) const;

        /* Operação concreta */
        virtual void fecharArquivo(std::ifstream& arq) const;

        /* Operação concreta */
        void limparDados(std::vector<Dado*>& dados) const;
};

#endif
