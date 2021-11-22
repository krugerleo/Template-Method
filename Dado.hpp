#ifndef DADO_HPP
#define DADO_HPP

#include <string>

class Dado {
    public:
        Dado(
            const std::string& nome,
            const float idade,
            const float altura,
            const float peso,
            const char sexo
        );

        std::string getNome() const;
        float getIdade() const;
        float getAltura() const;
        float getPeso() const;
        char getSexo() const;

    private:
        std::string nome;
        float idade;
        float altura;
        float peso;
        char sexo;
};

#endif
