#ifndef DADOS_ESTATISTICOS_HPP
#define DADOS_ESTATISTICOS_HPP

class DadosEstatisticos {
    public:
        DadosEstatisticos(
            const int numTotalDados,
            const float mediaIdade,
            const float mediaAltura,
            const float mediaPeso,
            const float porcentagemSexoM,
            const float porcentagemSexoF
        );

        float getNumTotalDados() const;
        float getMediaIdade() const;
        float getMediaAltura() const;
        float getMediaPeso() const;
        float getPorcentagemSexoM() const;
        float getPorcentagemSexoF() const;

    private:
        int numTotalDados;
        float mediaIdade;
        float mediaAltura;
        float mediaPeso;
        float porcentagemSexoM;
        float porcentagemSexoF;
};

#endif
