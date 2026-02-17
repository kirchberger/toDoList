#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


int list(int argc, char* argv[]){ 
	
	// Lexor for tokens
	FILE * fileptr;
	fileptr = fopen("/home/Alex/.todolist/first.todo","r");// need to fix to choose list
	if (fileptr == NULL){
		printf("Error opening file\n");
		return 1;
	}
	char line[255];
	int i = 0;

	while (fgets(line,255,fileptr)){

		i = 0;	

		while (line[i] == ' '){
			i++;
		}

		if ((line[i] == '#') && (line[i + 1] == '#') && (line[i + 2] == '#')){
			i = i + 3;
			while (line[i] == ' '){
				i++;
			}
			printf("--- %s", &line[i]);
		}

		else if ((line[i] == '#') && (line[i + 1] == '#')){
			i = i + 2;
			while (line[i] == ' '){
				i++;
			}
			printf("-- %s", &line[i]);
		}

		else if (line[i] == '#'){
			i = i + 1;
			while (line[i] == ' '){
				i++;
			}
			printf("- %s", &line[i]);
		}

		else{

		}
	}
	fclose(fileptr);
	return 0;
}

int main(int argc, char* argv[]){

	// Parsing arguments
	if (!strcmp(argv[1], "-a")){ // Append or add to a current list 
		if (argc != 5) {
			printf("Wrong number of arguments for -a argument\n");
			return 1;
		}
		printf("adding\n");

	} else if (!strcmp(argv[1], "-r")){	// Remove an item from a list
		if (argc != 4) {
			printf("Wrong number of arguments for -r argument\n");
			return 1;
		}

	} else if (!strcmp(argv[1], "-l")){ // List a list
		if (argc != 3) {
			printf("Wrong number of arguments for -l argument\n");
			return 1;
		}
		return list(argc-2, &argv[2]); // This gives the number of arguments past the the first 2 arguments and the address of this in the double char pointer
									  
	} else if (!strcmp(argv[1], "-n")){ // Create new list
		if (argc != 3) {
			printf("Wrong number of arguments for -n argument\n");
			return 1;
		}

	} else if (!strcmp(argv[1], "-d")){ // delete list
		if (argc != 3) {
			printf("Wrong number of arguments for -d argument\n");
			return 1;
		}

	} else{
		printf("argument %s unknown.\n",argv[1]);
		return 1;
	}

	return 0; 
}



