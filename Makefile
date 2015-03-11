all:
	scons
	./main

main:
	./main

money_test:
	scons money_test
	./money_test

.PHONY: all main money_test
