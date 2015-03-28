all:
	scons
	./build/main

include Makefile_tests

generate_tests:
	python generate_tests.py

main:
	scons main
	./build/main

test: generate_tests all_tests

clean:
	rm -f main
	rm -f *_test
	rm -rf build

.PHONY: all main money_test bimap_test graph_test
