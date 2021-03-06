#ifndef EXTRAIR_ESTATISTICAS_JSON_HPP
#define EXTRAIR_ESTATISTICAS_JSON_HPP

#include <string>
#include <fstream>
#include <vector>
#include "Dado.hpp"
#include "ExtrairEstatisticas.hpp"

class ExtrairEstatisticasJSON: public ExtrairEstatisticas {
    public:
        virtual ~ExtrairEstatisticasJSON() = default;

    protected:
        virtual std::vector<Dado*> converterParaClasseDado(std::ifstream& arq) const override;
        virtual bool checarArquivo(const std::string& nomeArq) const override;
};

#endif
