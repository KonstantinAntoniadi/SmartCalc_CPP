CC = g++
CFLAGS = -Wall -Werror -Wextra -std=c++17
TEST = test/*.cc
GTEST_DIR = test
EXPRESSION = model/expression.cc
CREDITCALCULATOR = model/creditcalculator.cc
OS := $(shell uname)

ifeq ($(OS),Darwin)
TESTLIBS = -lm -lpthread -fprofile-arcs -ftest-coverage
else
TESTLIBS = -lgtest -lpthread -lm  -lrt -lsubunit -fprofile-arcs -ftest-coverage
endif

all: clean install open


install: clean
	mkdir build && cd build && cmake ../CMakeLists.txt && make && rm Makefile
ifeq ($(OS),Darwin)
	cp resources/fonts/PetMe.ttf ~/Library/Fonts
	mv build/calc.app ~/Desktop
else
	mv build/calc ~/Desktop
endif
	rm -rf build/


uninstall:
ifeq ($(OS),Darwin)
	rm -rf ~/Desktop/calc.app
else
	rm -rf ~/Desktop/calc
endif
	

open:
ifeq ($(OS),Darwin)
	open -n ~/Desktop/calc.app --args -AppCommandLineArg
else
	~/Desktop/calc
endif
	

dvi:
ifeq ($(OS),Darwin)
	@open README.pdf
else
	@xdg-open README.pdf
endif
	

calculator.o: $(EXPRESSION) $(CREDITCALCULATOR)
	@$(CC) $(CFLAGS) -c $(EXPRESSION) $(CREDITCALCULATOR)

calculator.a: calculator.o
	@ar rcs calculator.a *.o

test: clean calculator.a 
	@$(CC) $(CFLAGS) $(TEST) calculator.a -o unit_test -lgtest -lpthread
	@./unit_test

gcov_report: clean calculator.o
ifeq ($(OS),Darwin)
	$(CC) $(CFLAGS) $(CREDITCALCULATOR) $(EXPRESSION) $(TEST) -lgtest -o $(TESTLIBS) gcov_test  
else
	$(CC) $(CFLAGS) $(CREDITCALCULATOR) $(EXPRESSION) $(TEST) -o gcov_test $(TESTLIBS)
endif
	@chmod +x *
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info --no-external -c -d .
	genhtml -o report/ gcov_test.info
ifeq ($(OS),Darwin)
	open ./report/index.html
else
	xdg-open ./report/index.html
endif
	

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
	@rm -rf *.o *.a *.cmake CMakeCache.txt
	@rm -rf *.gcda *.gcno *.info
	@rm -rf gcov_report
	@rm -rf gcov_test
	@rm -rf report
	@rm -rf unit_test
	@rm -rf build/
	@rm -rf Archive_calc
	@rm -rf dist-newstyle/


.PHONY: all install expression.a creditcalculator.a uninstall open dvi test gcov_report valgrind dist format check clean