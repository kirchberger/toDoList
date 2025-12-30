#include <stdio.h>
#include <string.h>
#include <sys/stat.h>


int list(int argc, char* argv[]){ 
  // Lexor for tokens
  if (argc < 1){
    printf("Too few arguments\n");
    return 1;
  }
  if (argc > 1){
    printf("Too many arguments\n");
    return 1;
  }
  FILE * fileptr;
  fileptr = fopen("/home/Alex/.todolist/first.todo","r");// need to fix to choose list
  if (fileptr == NULL){
    printf("Error opening file\n");
    return 1;
  }
  char line[255];

  while (fgets(line,255,fileptr)){
    if ((line[0]=='#')&&(line[1]=='#')&&(line[2]=='#')){
      printf("--- %s",&line[3]);
    }
    else if ((line[0]=='#')&&(line[1]=='#')){
      printf("-- %s",&line[2]);
    }
    else if (line[0]=='#'){
      printf("- %s",&line[1]);
    }
    else{

    }
  }



  fclose(fileptr);
  return 0;
}

int main(int argc, char* argv[]){

  if (!strcmp(argv[1], "-a")){
    printf("adding\n");
  } else if (!strcmp(argv[1], "-r")){
    printf("removing\n");
  } else if (!strcmp(argv[1], "-l")){
    printf("listing\n");
    return list(argc-2, &argv[2]); // This gives the number of arguments past the the first 2 arguments and the address of this in the double char pointer
  } else{
    printf("argument %s unknown.\n",argv[1]);
    return 1;
  }
  return 0; 
}
