all: tester

tester: tester.cpp
	g++ -std=c++14 -g -Wall -Werror -Wextra -DTESTING tester.cpp display.cpp design.cpp countdown_timer.cpp -o "tester"

.PHONY: clean
clean:
	rm -rf tester;
