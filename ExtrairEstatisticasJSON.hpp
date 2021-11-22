#ifndef EXTRAIR_ESTATISTICAS_JSON_HPP
#define EXTRAIR_ESTATISTICAS_JSON_HPP

#include <string>
#include <fstream>
#include <vector>
#include "bibliotecas/json.hpp"
#include "Dado.hpp"
#include "ExtrairEstatisticas.hpp"
#include <iostream>

class ExtrairEstatisticasJSON: public ExtrairEstatisticas {
    protected:
        std::vector<Dado*> converterParaClasseDado(std::ifstream& arq) const override {
            std::vector<Dado*> dados;
            nlohmann::json arqJson;
            arq >> arqJson;
            nlohmann::json::iterator it{arqJson.begin()};

            for (; it != arqJson.end(); it++) {
                dados.push_back(new Dado{
                        (*it)["nome"].get<std::string>(),
                        (*it)["idade"].get<float>(),
                        (*it)["altura"].get<float>(),
                        (*it)["peso"].get<float>(),
                        (*it)["sexo"].get<std::string>()[0]
                        });
            }

            return dados;
        }

        bool checarArquivo(const std::string& nomeArq) const override {
            // checa extensão do arquivo
            if (nomeArq.substr(nomeArq.find_last_of(".") + 1) != "json") {
                throw std::runtime_error{"Arquivo com extensão diferente de json"};
            }

            return true;
        }
};

#endif
