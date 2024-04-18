CC = g++

LIBS = -lcheck -lsubunit -lrt -lm -lpthread

CFLAGS = -c -Wall -Werror -Wextra $(LIBS)

RES_DIR = resourses/

all: build1 build2

clean:
	rm -rf $(RES_DIR) exe* *.o def *.gch graph/*.gch graph/Stack/*.gch

rebuild1: clean build1

rebuild2: clean build2

build_d: clean
	mkdir -p resourses
	$(CC) $(CFLAGS) defend* graph/Graph*
	mv *.o *.gch graph/*.gch $(RES_DIR)
	$(CC) $(RES_DIR)*.o $(LIBS) -o def

build1:
	mkdir -p resourses
	$(CC) $(CFLAGS) main1.cpp
	mv *.o $(RES_DIR)
	$(CC) $(RES_DIR)*.o $(LIBS) -o exe1

build2:
	mkdir -p resourses
	$(CC) $(CFLAGS) main2.cpp
	mv *.o $(RES_DIR)
	$(CC) $(RES_DIR)*.o $(LIBS) -o exe2

run1: rebuild1
	./exe1

run2: rebuild2
	./exe2

style:
	clang-format -n tests/*.c *.c *.h --style=Google

style_fix:
	clang-format -i tests/*.c *.c *.h --style=Google