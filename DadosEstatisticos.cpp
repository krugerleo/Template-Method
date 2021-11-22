#include "DadosEstatisticos.hpp"

DadosEstatisticos::DadosEstatisticos(
            const int numTotalDados,
            const float mediaIdade,
            const float mediaAltura,
            const float mediaPeso,
            const float porcentagemSexoM,
            const float porcentagemSexoF
        )
        :numTotalDados{numTotalDados},
        mediaIdade{mediaIdade},
        mediaAltura{mediaAltura},
        mediaPeso{mediaPeso},
        porcentagemSexoM{porcentagemSexoM},
        porcentagemSexoF{porcentagemSexoF}{
}

float DadosEstatisticos::getNumTotalDados() const{
    return this->numTotalDados;
}

float DadosEstatisticos::getMediaIdade() const{
    return this->mediaIdade;
}

float DadosEstatisticos::getMediaAltura() const{
    return this->mediaAltura;
}

float DadosEstatisticos::getMediaPesoa() const{
    return this->mediaPeso;
}

float DadosEstatisticos::getPorcentagemSexoM() const{
    return this->porcentagemSexoM;
}

float DadosEstatisticos::getPorcentagemSexoF() const{
    return this->porcentagemSexoF;
}
