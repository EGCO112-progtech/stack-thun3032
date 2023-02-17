argument: main.c 
	gcc main.c -o stack

run: stack
	 ./stack


clean: stack
	 rm stack
