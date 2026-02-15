CC = gcc
LCOV = lcov
GENHTML = genhtml

C_FLAGS = -Wall -Wextra -Werror -std=c11
GCOV_FLAGS = --coverage
LFLAGS = -pthread -lcheck_pic -lrt -lm -lsubunit 
LIBRARY = s21_matrix
RUN_TEST_FILE = run_test.out
COV_DIR = ./cov_report
TEST_FILE = ./tests.c
SRC_FILES =  $(filter-out ./tests.c, $(wildcard ./*.c))
HEADER = ./s21_matrix.h

all: $(LIBRARY).a test

$(LIBRARY).a:
	$(CC) $(C_FLAGS) -c $(SRC_FILES) 
	ar rcs $(LIBRARY).a *.o
	rm -rf *.o
	ranlib $(LIBRARY).a

test: $(LIBRARY).a
	$(CC) $(C_FLAGS) $(TEST_FILE) $(LIBRARY).a $(LFLAGS) -o $(RUN_TEST_FILE)
	./$(RUN_TEST_FILE)

gcov_report: clean
	mkdir -p $(COV_DIR)
	$(CC) $(C_FLAGS) $(GCOV_FLAGS) -c $(SRC_FILES)
	ar rcs $(LIBRARY).a *.o
	ranlib $(LIBRARY).a
	rm -f *.o
	$(CC) $(C_FLAGS) $(GCOV_FLAGS) $(TEST_FILE) $(LIBRARY).a $(LFLAGS) -o $(RUN_TEST_FILE)
	./$(RUN_TEST_FILE)
	$(LCOV) -c -d . -o $(COV_DIR)/cov_report.info
	$(LCOV) --ignore-errors unused -r $(COV_DIR)/cov_report.info '/usr/*' -o $(COV_DIR)/cov_filtered.info
	$(GENHTML) $(COV_DIR)/cov_filtered.info -o $(COV_DIR)
	xdg-open $(COV_DIR)/index.html
clean_all: clean
	rm -f *.gcda *.gcno
	rm -f $(RUN_TEST_FILE)
	rm -f $(LIBRARY).a
	rm -rf $(COV_DIR)/*	
	rm -rf $(COV_DIR)

clean:
	rm -rf *.o

clang_f:
	clang-format -style=Google -i *.c *.h $(SRC_FILES) $(HEADER) $(TEST_FILE) -style=file:../materials/linters/.clang-format

clang_check:
	clang-format -style=Google -n *.c *.h  $(SRC_FILES) $(HEADER) $(TEST_FILE) -style=file:../materials/linters/.clang-format