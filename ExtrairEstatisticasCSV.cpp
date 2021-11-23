#include "ExtrairEstatisticasCSV.hpp"
#include "bibliotecas/csv.hpp"

std::vector<Dado*> ExtrairEstatisticasCSV::converterParaClasseDado(std::ifstream& arq) const {
    std::vector<Dado*> dados;

    csv::CSVReader reader(arq);
    csv::CSVRow row;

    while (reader.read_row(row)) {
        dados.push_back(new Dado{
                row["nome"].get<std::string>(),
                row["idade"].get<int>(),
                row["altura"].get<float>(),
                row["peso"].get<float>(),
                row["sexo"].get<std::string>()[0]
                });
    }

    return dados;
}
