all:
	scons
	./build/main

include Makefile_tests

generate_tests:
	python generate_tests.py

main:
	scons main
	./main

make_all:
	scons

test: all_tests

travis:
	scons mode=debug && make generate_tests && make run_all

clean:
	rm -f main
	rm -f *_test
	rm -rf build
	find . -name '*.o' -delete

.PHONY: all main money_test bimap_test graph_test


# Compilation d'un fichier :
# g++ -o graph_test2 src/core/graph_test2.o -lcppunit -lboost_system
