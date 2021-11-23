
# 1. Template Method
### 1.1 O que é?
Template Method é um padrão para design de projeto onde utiliza-se de um Classe como esqueleto de operações e deixa os detalhes para serem implementados pelas Classes filhas. E a estrutura geral e a sequência das operações são preservadas pela Classe pai.
### 1.3 Estrutura
A classe abstrata declara operações que serão as etapas necessarias para execução. As operações podem ser Abstratas ou ter codigo padrão utilizado em todas as Classes filho.

As Classes concretas podem sobreescrever as etapas, porém o metodo é preservado.

A etapa três (hook) pode ser necessaria em caso de outras Classes filho que precisem de outra operação sobreescrita.

![Diagrama estrutura do Template Method](/diagrama/Estrutura.jpg)

### 1.3 Exemplificando
Para um algoritmo de ordenação ascendente e decrescente é muito similar,

# 2. Projeto
### 2.1 Base
**Descrição:** Durante a primeira cinematica do jogo já percebi que era impossivel pular as cinematicas do jogo.
**Diretriz(es) Violada(s):** 3. Liberdade e controle do usuário.
**Grau de severidade:** 2 - “problema pequeno – baixa prioridade na correção”.
**Sugestão de solução:** Adicinar a opção ao jogador de pular ou rever cinematicas do jogo.
FOTO #1

# 3. Apreciação geral do metodo.
O jogo “Retro Machina: Nucleonics” me causou uma primeira impressão ruim pela dificuldade que tive em utilizar o controle e descobrir as teclas para jogar pelo teclado.A historia é interessante e intriga sobre que acontecimentos levaram o planeta a ficar daquele jeito que acaba prendendo o jogador em prestar atenção nas informações encontradas e no jogo além de possuir diversos cenarios bonitos em que eu fiquei alguns segundos admirando os detalhes (foto abaixo), a mecanica e a historia deixam espaço pra introduzir diversos tipos de robôs e possibilidades para novos desafios evitando a monotonia.
O jogo poderia ser mais amigavel a novos jogadores com a escolhe de dificuldade e mais tutoriais porém para o geral dos jogadores ele oferece um produto com qualidade e poucos problemas.
FOTO GIGANTE
## 3.1 Utilizações
## 3.2 Prós e contras.

# Apresentação e conteudo elaborado por:
 Leonardo Bueno Nogueira Kruger                 
 Nicolas Tamalu
# Referencias
https://refactoring.guru/pt-br/design-patterns/template-method
https://sourcemaking.com/design_patterns/template_method
