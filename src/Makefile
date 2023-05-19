CC=gcc
CFLAG=-c 
CFLAGS=-Wall -Werror -Wextra -std=c11
SRC_DIR=backend
BACK_SRC=$(SRC_DIR)/*.c
STACS_SRC=$(SRC_DIR)/stacks/*.c
TEST=test/unit_test.c
OS := $(shell uname)

ifeq ($(OS),Linux)
TEST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
else
TEST_LIBS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
endif

all: clean install open

install: clean
	@cp resources/fonts/PetMe.ttf ~/Library/Fonts
	@cd front && cmake CMakeLists.txt && make && rm Makefile && mv calc.app ~/Desktop

uninstall:
	rm -rf ~/Desktop/calc.app

open:
	@open -n ~/Desktop/calc.app --args -AppCommandLineArg

dvi:
	@open README.pdf

test: clean
	$(CC) $(CFLAGS) $(TEST) $(BACK_SRC) $(STACS_SRC) $(TEST_LIBS) -o unit_test
	./unit_test

gcov_report:
	$(CC) $(CFLAGS) --coverage $(TEST) $(BACK_SRC) $(STACS_SRC) $(NAME) $(TEST_LIBS) -o gcov_test
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

valgrind: test
	valgrind --vgdb=no --leak-check=full --log-file="logs" --track-origins=yes --verbose ./unit_test

dist:
	rm -rf Archive_calc/
	mkdir Archive_calc/
	mv calc.app Archive_calc
	tar -cvzf Archive_calc.tar.gz Archive_calc

format:
	@cp ../materials/linters/.clang-format ./
	clang-format -i */*.c */*/*.c */*.h */*/*.h */*.cpp
	@rm .clang-format

check: 
	@cp ../materials/linters/.clang-format ./
	clang-format -n */*.c */*/*.c */*.h */*/*.h */*.cpp
	@rm .clang-format

clean:
	@rm -rf *.o
	@rm -rf *.gcda *.gcno *.info
	@rm -rf gcov_report
	@rm -rf gcov_test
	@rm -rf report
	@rm -rf unit_test
	@rm -rf build/
	@rm -rf front/calc.app
	@rm -rf front/calc_autogen
	@rm -rf front/CMakeFiles
	@rm -rf front/CMakeCache.txt
	@rm -rf front/cmake_install.cmake
	@rm -rf Archive_calc
	@rm -rf dist-newstyle/


.PHONY: all install uninstall open dvi test gcov_report valgrind dist format check clean