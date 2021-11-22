#ifndef EXTRAIR_ESTATISTICAS_CSV_HPP
#define EXTRAIR_ESTATISTICAS_CSV_HPP

#include <string>
#include <vector>
#include <vector>
#include "bibliotecas/csv.hpp"
#include "Dado.hpp"
#include "ExtrairEstatisticas.hpp"

class ExtrairEstatisticasCSV: public ExtrairEstatisticas {
    protected:
        std::vector<Dado*> converterParaClasseDado(const std::string& nomeArq) const override {
            std::vector<Dado*> dados;

            csv::CSVFormat format;
            format.header_row(0);

            csv::CSVReader reader(nomeArq, format);
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

        bool checarFormatoSuportado(const std::string& nomeArq) const override {
            return nomeArq.substr(nomeArq.find_last_of(".") + 1) == "csv";
        }
};

#endif
