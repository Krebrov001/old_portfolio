# Makefile for Assignment 5
CXX = /usr/bin/g++
MAIN = assignment_5
H_FILES = bst_nodet.h bs_treet.h
CXXFLAGS = -Wall -Wextra -pedantic -g

# Type 'make' to create the executable
${MAIN}: ${MAIN}_unit_test.cpp ${H_FILES}
	${CXX} ${CXXFLAGS} ${MAIN}_unit_test.cpp -o $@
	@echo 'Use ./${MAIN} to run'

# Type 'make style' to check your code style
style: ../../helpful_files/cpplint.py ${FILE} 
	python $< --filter=-runtime/references,-legal/copyright,-readability/streams,-runtime/explicit,-build/header_guard,-build/include ${MAIN}_unit_test.cpp ${H_FILES}

# Type 'make clean' to remove the executable
clean:
	rm -rf ${MAIN}
