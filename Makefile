TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

${TRGDIR}/test: ${OBJ}/main.o ${OBJ}/Zespolona.o ${OBJ}/WyrazenieZespolone.o
	g++ -o ${TRGDIR}/test.exe ${OBJ}/main.o ${OBJ}/Zespolona.o\
						 ${OBJ}/WyrazenieZespolone.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: main.cpp WyrazenieZespolone.hh Zespolona.hh
		g++ -c ${FLAGS} -o ${OBJ}/main.o main.cpp

${OBJ}/Zespolona.o: Zespolona.cpp Zespolona.hh
		g++ -c ${FLAGS} -o ${OBJ}/Zespolona.o Zespolona.cpp

${OBJ}/WyrazenieZespolone.o: WyrazenieZespolone.cpp WyrazenieZespolone.hh Zespolona/hh
		g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZespolone.o WyrazenieZespolone.cpp