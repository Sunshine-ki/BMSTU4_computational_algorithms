CFLAGS := -std=c99 -lm
FILE_O :=  bin/main.o bin/functions.o bin/matrix_func.o
HEADERS_DIR := headers/

all: app.exe 

app.exe: $(FILE_O)
	gcc -o app.exe $^ $(CFLAGS)

bin/%.o: %.c
	mkdir -p bin
	gcc -c -I $(HEADERS_DIR) $^ -o $@ $(CFLAGS)


test: test.c
	gcc test.c -o test -lm
	./test
	rm -f test

run:
	./app.exe table/test.txt

clean:
	rm -f *.o *.exe *.out functions/*.o test -r bin