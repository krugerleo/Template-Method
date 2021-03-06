#ifndef EXTRAIR_ESTATISTICAS_CSV_HPP
#define EXTRAIR_ESTATISTICAS_CSV_HPP

#include <vector>
#include <fstream>
#include "Dado.hpp"
#include "ExtrairEstatisticas.hpp"

class ExtrairEstatisticasCSV: public ExtrairEstatisticas {
    public:
        virtual ~ExtrairEstatisticasCSV() = default;

    protected:
        virtual std::vector<Dado*> converterParaClasseDado(std::ifstream& arq) const override;
};

#endif
