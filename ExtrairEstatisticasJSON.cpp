#include <stdexcept>
#include "ExtrairEstatisticasJSON.hpp"
#include "bibliotecas/json.hpp"

std::vector<Dado*> ExtrairEstatisticasJSON::converterParaClasseDado(std::ifstream& arq) const {
    std::vector<Dado*> dados;
    nlohmann::json arqJson;
    arq >> arqJson;
    nlohmann::json::iterator it{arqJson.begin()};

    for (; it != arqJson.end(); it++) {
        dados.push_back(new Dado{
                (*it)["nome"].get<std::string>(),
                (*it)["idade"].get<int>(),
                (*it)["altura"].get<float>(),
                (*it)["peso"].get<float>(),
                (*it)["sexo"].get<std::string>()[0]
                });
    }

    return dados;
}

bool ExtrairEstatisticasJSON::checarArquivo(const std::string& nomeArq) const {
    // checa extensão do arquivo
    if (nomeArq.substr(nomeArq.find_last_of(".") + 1) != "json") {
        throw std::runtime_error{"Arquivo com extensão diferente de json"};
    }

    return true;
}
