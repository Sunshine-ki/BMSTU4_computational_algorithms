CFLAGS := -std=c99 -lm
FILE_O :=  bin/main.o bin/functions.o bin/matrix_func.o
HEADERS_DIR := headers/

all: app.exe 

app.exe: $(FILE_O)
	gcc -o app.exe $^ $(CFLAGS)

bin/%.o: src/%.c
	mkdir -p bin
	gcc -c -I $(HEADERS_DIR) $^ -o $@ $(CFLAGS)


test: src/test.c
	mkdir -p bin
	gcc src/test.c -I $(HEADERS_DIR) -o bin/test.out -lm
	./bin/test.out

run:
	./app.exe table/table2.txt

clean:
	rm -f *.o *.exe *.out -r bin