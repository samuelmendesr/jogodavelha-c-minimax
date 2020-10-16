All: jogodavelha

jogodavelha:	main.o jogo_da_velha.o
	gcc main.o jogo_da_velha.o -o jogodavelha

main.o:	main.c jogo_da_velha.h
	gcc -c main.c

jogo_da_velha.o: jogo_da_velha.c jogo_da_velha.h
	gcc -c jogo_da_velha.c

clean:
	rm -f *.o projeto
