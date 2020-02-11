CFLAGS := -std=c99
FILE_O :=  functions.o
HEADERS_DIR := headers/

all: app.exe 

app.exe: main.o $(FILE_O)
	gcc -o app.exe $^ $(CFLAGS)

%.o: %.c
	gcc -c -I $(HEADERS_DIR) $^ $(CFLAGS)

clean:
	rm -f *.o *.exe functions/*.o

run:
	./app.exe table/table2.txt < in.txt
