#ifndef EXTRAIR_ESTATISTICAS_CSV_HPP
#define EXTRAIR_ESTATISTICAS_CSV_HPP

#include <string>
#include <vector>
#include <fstream>
#include "bibliotecas/csv.hpp"
#include "Dado.hpp"
#include "ExtrairEstatisticas.hpp"

class ExtrairEstatisticasCSV: public ExtrairEstatisticas {
    protected:
        std::vector<Dado*> converterParaClasseDado(std::ifstream& arq) const override {
            std::vector<Dado*> dados;

            csv::CSVReader reader(arq);
            csv::CSVRow row;

            while (reader.read_row(row)) {
                dados.push_back(new Dado{
                        row["nome"].get<std::string>(),
                        row["idade"].get<float>(),
                        row["altura"].get<float>(),
                        row["peso"].get<float>(),
                        row["sexo"].get<std::string>()[0]
                        });
            }

            return dados;
        }
};

#endif
