APP = build/Viewer.app
CC=					gcc 
CFLAGS=				-Wall -Werror -Wextra -std=c11 -pedantic
GCOVFLAGS=			-fprofile-arcs -ftest-coverage
SOURSES_GET_DATA=	s21_get_d*.c
OBJECT_GET_DATA=	$(patsubst %*.c, %*.o, $(SOURSES_GET_DATA))
SOURSES_MATRIX=		s21_m*.c
OBJECT_MATRIX=		$(patsubst %*.c, %*.o, $(SOURSES_MATRIX))
SOURSES_TEST=		test_*.c
OS=					$(shell uname -s)

ifeq ($(OS), Linux)
  CFLAGS+=		-D OS_LINUX
  CHECKFLAGS=	-lpthread -lcheck -pthread -lrt -lm -lsubunit
endif
ifeq ($(OS), Darwin)
  CFLAGS+=		-D OS_MAC
  CHECKFLAGS=	-lcheck
endif

all: build

check:
	cp ../materials/linters/.clang-format ./
	clang-format -n *.c
	clang-format -n *.h
	clang-format -n Viewer/*.cpp
	clang-format -n Viewer/*.h
	rm -rf .clang-format

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

build:
	mkdir build
	cd ./build/ && qmake ../Viewer/ && make

s21_matrix.a: $(SOURSES_MATRIX)
	$(CC) $(CFLAGS) -c $(SOURSES_MATRIX)
	@ar rcs s21_matrix.a $(OBJECT_MATRIX)
	@rm -rf ./*.o

s21_get_data_viewer.a: rebuild_lib_matrix $(SOURSES_GET_DATA)
	$(CC) $(CFLAGS) -c $(SOURSES_GET_DATA)
	@ar rcs s21_get_data_viewer.a $(OBJECT_GET_DATA)
	@rm -rf ./*.o

tests: rebuild_lib_matrix rebuild_lib_get_data $(SOURSES_TEST)
	$(CC) $(CFLAGS) $(SOURSES_TEST) s21_matrix.a s21_get_data_viewer.a $(CHECKFLAGS) -o test
	./test

gcov_report: rebuild_lib_matrix rebuild_lib_get_data
	@gcc $(GCOVFLAGS) $(SOURSES_TEST) $(SOURSES_MATRIX) $(SOURSES_GET_DATA) $(CHECKFLAGS) -o GcovReport
	@./GcovReport
	@lcov -t "GcovReport" -o GcovReport.info -c -d .
	@genhtml -o report GcovReport.info
	@open ./report/index-sort-f.html
	@rm -rf ./*.gcno ./*.gcda ./GcovReport.*

clean:
	@rm -rf ./a.out ./*.o ./*.a ./test ./GcovReport ./report
	@rm -rf *.aux *.dvi *.log *.out *.pdf
	@rm -rf build/

valgrind_test: tests
	valgrind --tool=memcheck --leak-check=yes ./test

leaks_test: tests
	leaks -atExit -- ./test

rebuild_lib_matrix: clean s21_matrix.a

rebuild_lib_get_data: clean s21_get_data_viewer.a

single_test: rebuild_lib_get_data
	$(CC) $(CFLAGS) test.c s21_get_data_viewer.a -lm
	@./a.out

install: build
	@mkdir $(HOME)/Desktop/3Dviewer
	@cp -rf $(APP) $(HOME)/Desktop/3Dviewer/
	make clean

uninstall:
	@rm -rf $(HOME)/Desktop/3Dviewer/

dvi:
	texi2dvi 3dviewer.tex

pdf:
	texi2pdf 3dviewer.tex

dist: build
	rm -rf ./build/*.dmg
	hdiutil create -volname "3Dviewer1.0" -srcfolder ./build/Viewer.app -ov -format UDRW 3Dviewer1.0.dmg
	mv 3Dviewer1.0.dmg $(HOME)/Desktop/
