#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
  for (int i = 1; i <= (argc-1); ++i){
    printf("%s\n", argv[i]);
  } 
  if (!strcmp(argv[1], "-a")){
    printf("adding\n");
  } else if (!strcmp(argv[1], "-r")){
    printf("removing\n");
  } else if (!strcmp(argv[1], "-l")){
    printf("listing\n");
  } else{
    printf("argument %s unknown.\n",argv[1]);
  }
  return 0; 
}
