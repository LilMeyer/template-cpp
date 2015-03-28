all:
	scons
	./build/main

include Makefile_tests

generate_tests:
	python generate_tests.py

main:
	scons main
	./build/main

clean:
	rm -rf build

.PHONY: all main money_test bimap_test graph_test
