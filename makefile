wg++ = g++ -g -fno-elide-constructors -std=c++11 -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors -Wunused -Wuninitialized --param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 --param large-function-growth=10000000 -fPIC


a.out: main.o
	clear
	$(wg++) main.o
	clear
main.o: main.cpp task.h
	clear
	$(wg++) -c main.cpp
	clear

run: a.out
	clear
	@./a.out
check: a.out
	clear
	@#--leak-check=full --show-leak-kinds=all
	@valgrind --leak-check=full --track-origins=yes ./a.out
clean:
	clear
	@rm -f *.o a.out vgcore.*