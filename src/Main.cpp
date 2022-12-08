#include <iostream>
#include "Generator.h"
#include "Reader.h"

int main(int argc, char **argv)
{
   int range_processes_min;
   int range_processes_max;//range de processos a serem testados
   range_processes_min = atoi(argv[1]);
   range_processes_max = atoi(argv[2]);

   for(int i = range_processes_min; i <=range_processes_max; i++)
   {   //gerador de arquivos no range indicado
                  generator(i);
   }

   for(int i = range_processes_min; i <=range_processes_max; i++){   //gerador de arquivos no range indicado
      reader(i);
   }

   
   return 0;
}
