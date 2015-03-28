# include Makefile_tests

all:
	scons
	./build/main

# compile_main:
# 	scons main
include Makefile_tests

generate_tests:
	python generate_tests.py

generate_tests:
	python generate_tests.py

main:
	./build/main

clean:
	rm -rf build

graph_test2:
	scons build/graph_test2
	./build/graph_test2

graph_test3:
	scons build/graph_test3
	./build/graph_test3

.PHONY: all main money_test bimap_test graph_test
