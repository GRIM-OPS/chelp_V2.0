#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input/getArgs.h"
#include "input/getInput.h"
#include "input/getFileExtention.h"
#include "add/add.h"

int main(int argc, char *argv[])
{
  char *baseStr = (char*)malloc(1);
  char *filePath;
  int fileArgLoc;

  strcpy(baseStr, "");

  if(getArgs('t', "--std", argc, argv))   // Add the standard/basic header files for a basic C program
  {
    baseStr = add(baseStr, "#include <stdio.h>\n#include <stdlib.h\n#include <string.h>\n");
  }


  if(getArgs('s', "--socket", argc, argv))    // Add socket based header files into file
  {
    baseStr = add(baseStr, "#include <sys/types.h>\n#include <sys/socket.h>\n#include <netinet/in.h>\n#include <unistd.h>\n");
  }


  fileArgLoc = getArgs('f', "--file", argc, argv);

  if(!fileArgLoc) // Get file path from CLI arguments
  {
    printf("[!] Need file location!\n");
    return 1;
  }
  else
  {

    if(fileArgLoc + 2 > argc)
    {
      printf("[!] Not enough arguments");
      return 1;
    }
    filePath = (char*)malloc(strlen(argv[fileArgLoc + 1] + 1));
    strcpy(filePath, argv[fileArgLoc + 1]);

  }

  if(getFileExtention(filePath) == 'c')
  {
    baseStr = add(baseStr, "\nint main(int argc, char *argv[])\n{\n\nreturn 0;\n}");
  }
  printf("BaseStr:\n%s", baseStr);


return 0;
}
