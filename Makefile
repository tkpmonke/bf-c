CC=gcc

# why am i writing a full makefile when this could literally be a single-line shell script
# mostly cause idk how to make a makefile :sob:


bin/bf: main.o
	$(CC) $^ -o $@

main.o: main.c
	$(CC) $^ -c -o $@

.PHONY: clean

clean:
	rm ./bin -r
	rm main.o
