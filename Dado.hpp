#ifndef DADO_HPP
#define DADO_HPP

#include <string>

class Dado {
    public:
        Dado(
            const std::string& nome,
            const int idade,
            const float altura,
            const float peso,
            const char sexo
        );
        virtual ~Dado() = default;

        std::string getNome() const;
        int getIdade() const;
        float getAltura() const;
        float getPeso() const;
        char getSexo() const;

    private:
        std::string nome;
        int idade;
        float altura;
        float peso;
        char sexo;
};

#endif
