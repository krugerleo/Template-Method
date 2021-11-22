parametrosCompilacao=-Wall -lpthread
nomeAula=templateMethod

all: $(nomeAula)

$(nomeAula): main.o Dado.o DadosEstatisticos.o ExtrairEstatisticasCSV.hpp ExtrairEstatisticasJSON.hpp
	g++ -o $(nomeAula) main.o Dado.o DadosEstatisticos.o ExtrairEstatisticasCSV.hpp ExtrairEstatisticasJSON.hpp $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Dado.o: Dado.hpp Dado.cpp
	g++ -c Dado.cpp $(parametrosCompilacao)

DadosEstatisticos.o: DadosEstatisticos.hpp DadosEstatisticos.cpp
	g++ -c DadosEstatisticos.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomeAula)
