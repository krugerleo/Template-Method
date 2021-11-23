#include <iostream>
#include "LeitorDadosEstatisticosArq.hpp"
#include "ExtrairEstatisticas.hpp"
#include "ExtrairEstatisticasCSV.hpp"
#include "ExtrairEstatisticasJSON.hpp"
#include "DadosEstatisticos.hpp"

int main() {
    ExtrairEstatisticasCSV eeCSV;
    DadosEstatisticos* deCSV;
    deCSV = eeCSV.obterDadosEstatisticos("dados/dados.csv");

    std::cout
        << "Numero Total de Dados = " << deCSV->getNumTotalDados() << std::endl
        << "Media Idade = " << deCSV->getMediaIdade() << std::endl
        << "Media Altura = " << deCSV->getMediaAltura() << std::endl
        << "Media Peso = " << deCSV->getMediaPesoa() << std::endl
        << "Porcentagem Sexo M = " << deCSV->getPorcentagemSexoM() << std::endl
        << "Porncetagem Sexo F = " << deCSV->getPorcentagemSexoF() << std::endl
        << std::endl;


    ExtrairEstatisticasJSON eeJSON;
    DadosEstatisticos* deJSON;
    deJSON = eeJSON.obterDadosEstatisticos("dados/dados.json");
    std::cout
        << "Numero Total de Dados = " << deJSON->getNumTotalDados() << std::endl
        << "Media Idade = " << deJSON->getMediaIdade() << std::endl
        << "Media Altura = " << deJSON->getMediaAltura() << std::endl
        << "Media Peso = " << deJSON->getMediaPesoa() << std::endl
        << "Porcentagem Sexo M = " << deJSON->getPorcentagemSexoM() << std::endl
        << "Porncetagem Sexo F = " << deJSON->getPorcentagemSexoF() << std::endl
        << std::endl;


    LeitorDadosEstatisticosArq leCSV{&eeCSV};
    leCSV.imprimirDadosEstatisticos("dados/dados.csv");

    LeitorDadosEstatisticosArq leJSON{&eeJSON};
    leJSON.imprimirDadosEstatisticos("dados/dados.json");

    delete deCSV;
    delete deJSON;

    return 0;
}
