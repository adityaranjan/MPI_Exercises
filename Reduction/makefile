EXECS = reduction
MPICPP?=mpic++

all: ${EXECS}

reduction: reduction.cpp
	${MPICPP} -o reduction reduction.cpp

clean:
	rm ${EXECS}
