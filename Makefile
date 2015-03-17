all:
	scons
	./build/main

# compile_main:
# 	scons main

clean:
	rm -rf build

main:
	./build/main

money_test:
	scons build/money_test
	./build/money_test

bimap_test:
	scons build/bimap_test
	./build/bimap_test

graph_test:
	scons build/graph_test
	./build/graph_test

.PHONY: all main money_test bimap_test graph_test
