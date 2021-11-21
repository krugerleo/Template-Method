parametrosCompilacao=-Wall #-Wshadow
nomeAula=methodTemplate

all: $(nomeAula)

$(nomeAula): main.o ConcreteClassUm.o ConcreteClassDois.o Dados.o DadosEstatisticos.o
	g++ -o $(nomeAula) main.o ConcreteClassUm.o ConcreteClassDois.o Dados.o DadosEstatisticos.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

ConcreteClassUm.o: ConcreteClassUm.hpp ConcreteClassUm.cpp
	g++ -c ConcreteClassUm.cpp $(parametrosCompilacao)

ConcreteClassDois.o: ConcreteClassDois.hpp ConcreteClassDois.cpp
	g++ -c ConcreteClassDois.cpp $(parametrosCompilacao)

Dados.o: Dados.hpp Dados.cpp
	g++ -c Dados.cpp $(parametrosCompilacao)

DadosEstatisticos.o: DadosEstatisticos.hpp DadosEstatisticos.cpp
	g++ -c DadosEstatisticos.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomeAula)
