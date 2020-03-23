TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/test 
			${TRGDIR}/test latwy


${TRGDIR}/test: ${OBJ}/main.o ${OBJ}/Zespolona.o ${OBJ}/WyrazenieZespolone.o ${OBJ}/BazaTestu.o ${OBJ}/statystyka.o
	g++ -o ${TRGDIR}/test ${OBJ}/main.o ${OBJ}/Zespolona.o ${OBJ}/WyrazenieZespolone.o ${OBJ}/BazaTestu.o\
				${OBJ}/statystyka.o

${OBJ}/main.o: src/main.cpp inc/WyrazenieZespolone.hh inc/Zespolona.hh
		g++ -c ${FLAGS} -o ${OBJ}/main.o src/main.cpp

${OBJ}/Zespolona.o: src/Zespolona.cpp inc/Zespolona.hh
		g++ -c ${FLAGS} -o ${OBJ}/Zespolona.o src/Zespolona.cpp

${OBJ}/WyrazenieZespolone.o: src/WyrazenieZespolone.cpp inc/WyrazenieZespolone.hh inc/Zespolona.hh
		g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZespolone.o src/WyrazenieZespolone.cpp

${OBJ}/statystyka.o: src/statystyka.cpp inc/statystyka.hh	
		g++ -c ${FLAGS} -o ${OBJ}/statystyka.o src/statystyka.cpp

${OBJ}/BazaTestu.o: src/BazaTestu.cpp inc/BazaTestu.hh inc/WyrazenieZespolone.hh inc/Zespolona.hh inc/statystyka.hh
		g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o src/BazaTestu.cpp

