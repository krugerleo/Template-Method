#include "LeitorDadosEstatisticosArq.hpp"

LeitorDadosEstatisticosArq::LeitorDadosEstatisticosArq(ExtrairEstatisticas* ee)
    :ee(ee){
}

void LeitorDadosEstatisticosArq::imprimirDadosEstatisticos(const std::string nomeArq) const {
    DadosEstatisticos* de{ee->obterDadosEstatisticos(nomeArq)};

    std::cout
        << "Numero Total de Dados = " << de->getNumTotalDados() << std::endl
        << "Media Idade = " << de->getMediaIdade() << std::endl
        << "Media Altura = " << de->getMediaAltura() << std::endl
        << "Media Peso = " << de->getMediaPesoa() << std::endl
        << "Porcentagem Sexo M = " << de->getPorcentagemSexoM() << std::endl
        << "Porncetagem Sexo F = " << de->getPorcentagemSexoF() << std::endl
        << std::endl;

    delete de;
}
