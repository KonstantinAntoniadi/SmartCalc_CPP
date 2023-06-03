CC = g++
CFLAG = -c 
CFLAGS = -Wall -Werror -Wextra -std=c++17
TEST =t est/*.cc
GTEST_DIR = test
EXPRESSION = model/expression.cc
CREDITCALCULATOR = model/creditcalculator.cc
OS := $(shell uname)

ifeq ($(OS),Linux)
TESTFLAGS = -lgtest -lpthread 
else
TESTFLAGS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
endif

all: clean install open

.PHONY: expression.a creditcalculator.a

install: clean
	@cp resources/fonts/PetMe.ttf ~/Library/Fonts 2>/dev/null
	@ cmake CMakeLists.txt && make && rm Makefile && mv calc.app ~/Desktop

uninstall:
	rm -rf ~/Desktop/calc.app

open:
	@open -n ~/Desktop/calc.app --args -AppCommandLineArg

dvi:
	@open README.pdf

expression.o: $(EXPRESSION)
	@$(CC) $(CFLAGS) -c $(EXPRESSION) -o expression.o

creditcalculator.o: $(CREDITCALCULATOR)
	@$(CC) $(CFLAGS) -c $(CREDITCALCULATOR) -o creditcalculator.o

expression.a: expression.o
	@ar rcs expression.a expression.o

creditcalculator.a: creditcalculator.o
	@ar rcs creditcalculator.a creditcalculator.o

test: clean expression.a creditcalculator.a
	@$(CC) $(CFLAGS) $(TEST) creditcalculator.a expression.a -o unit_test -lgtest -lpthread
	@./unit_test


gcov_report: clean expression.o creditcalculator.o
	$(CC) $(CFLAGS) $(CREDITCALCULATOR) $(EXPRESSION) --coverage $(TEST) -o gcov_test $(TESTFLAGS)
	chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

dist:
	mkdir SmartCalc-2.0/
	mkdir SmartCalc-2.0/src
	cp -r controller model resources test view Makefile CMakeLists.txt calc_en_US.ts README.pdf SmartCalc-2.0/src
	tar -cvzf SmartCalc-2.0.tar.gz SmartCalc-2.0
	rm -rf SmartCalc-2.0

format:
	clang-format -style=Google -i */*.cc  */*.h  */*.cpp

check: 
	clang-format -style=Google -n */*.cc  */*.h  */*.cpp --verbose

clean:
	@rm -rf *.o *.a
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