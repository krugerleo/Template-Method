#include "Dado.hpp"

Dado::Dado(
    const std::string& nome,
    const float idade,
    const float altura,
    const float peso,
    const char sexo
    )
    :nome{nome}, idade{idade}, altura{altura}, peso{peso}, sexo{sexo} {
}

std::string Dado::getNome() const {
    return this->nome;
}

float Dado::getIdade() const {
    return this->idade;
}

float Dado::getAltura() const {
    return this->altura;
}

float Dado::getPeso() const {
    return this->peso;
}

char Dado::getSexo() const {
    return this->sexo;
}
