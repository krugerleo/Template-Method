#ifndef EXTRAIR_ESTATISTICAS_CSV_HPP
#define EXTRAIR_ESTATISTICAS_CSV_HPP

#include <string>
#include <vector>
#include <vector>
#include "bibliotecas/json.hpp"
#include "Dado.hpp"
#include "ExtrairEstatisticas.hpp"

class ExtrairEstatisticasCSV: public ExtrairEstatisticas {
    protected:
        std::vector<Dado*> converterParaClasseDado(const std::string& nomeArq) const override {
            std::vector<Dado*> dados;
            std::ifstream i(nomeArq);
            json j;
            i >> j;

            return dados;
        }

        bool checarFormatoSuportado(const std::string& nomeArq) const override {
            return nomeArq.substr(nomeArq.find_last_of(".") + 1) == "json";
        }
};

#endif
