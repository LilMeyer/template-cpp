all:
	scons
	./build/main

include Makefile_tests

generate_tests:
	python generate_tests.py

main:
	scons main
	./main

test: all_tests

travis:
	scons mode=debug && make generate_tests && make test

clean:
	rm -f main
	rm -f *_test
	rm -rf build

.PHONY: all main money_test bimap_test graph_test
