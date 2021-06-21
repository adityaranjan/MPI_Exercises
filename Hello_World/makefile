EXECS = helloworld
MPICPP?=mpic++

all: ${EXECS}

helloworld: helloworld.cpp
	${MPICPP} -o helloworld helloworld.cpp

clean:
	rm ${EXECS}