parametrosCompilacao=-Wall -lpthread
nomeAula=templateMethod

all: $(nomeAula)

$(nomeAula): main.o Dado.o DadosEstatisticos.o ExtrairEstatisticas.o  ExtrairEstatisticasCSV.o ExtrairEstatisticasJSON.o LeitorDadosEstatisticosArq.o
	g++ -o $(nomeAula) main.o Dado.o DadosEstatisticos.o ExtrairEstatisticas.o ExtrairEstatisticasCSV.o ExtrairEstatisticasJSON.o LeitorDadosEstatisticosArq.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Dado.o: Dado.hpp Dado.cpp
	g++ -c Dado.cpp $(parametrosCompilacao)

DadosEstatisticos.o: DadosEstatisticos.hpp DadosEstatisticos.cpp
	g++ -c DadosEstatisticos.cpp $(parametrosCompilacao)

ExtrairEstatisticasJSON.o: ExtrairEstatisticasCSV.hpp ExtrairEstatisticasCSV.cpp
	g++ -c ExtrairEstatisticasJSON.cpp $(parametrosCompilacao)

ExtrairEstatisticasCSV.o: ExtrairEstatisticasCSV.hpp ExtrairEstatisticasCSV.cpp
	g++ -c ExtrairEstatisticasCSV.cpp $(parametrosCompilacao)

LeitorDadosEstatisticosArq.o: LeitorDadosEstatisticosArq.hpp LeitorDadosEstatisticosArq.cpp
	g++ -c LeitorDadosEstatisticosArq.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomeAula)
