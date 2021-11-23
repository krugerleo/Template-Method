#ifndef EXTRAIR_ESTATISTICAS_JSON_HPP
#define EXTRAIR_ESTATISTICAS_JSON_HPP

#include <string>
#include <fstream>
#include <vector>
#include "bibliotecas/json.hpp"
#include "Dado.hpp"
#include "ExtrairEstatisticas.hpp"

class ExtrairEstatisticasJSON: public ExtrairEstatisticas {
    protected:
        std::vector<Dado*> converterParaClasseDado(std::ifstream& arq) const override;
        bool checarArquivo(const std::string& nomeArq) const override;
};

#endif
