#include <iostream>
#include "ExtrairEstatisticasCSV.hpp"
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

    return 0;
}
