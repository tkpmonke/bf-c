#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strfind(char* str, char end, size_t size)
{
   char* c;
   char* s = malloc(strlen(str)*sizeof(char));
   memcpy(s, str, strlen(str));

   c = strtok(s, "]");

   return c;
}

void parse(char* contents, size_t size, int* memory)
{

   for (int i = 0; i < size; ++i)
   {
      switch (contents[i])
      {
         case('>'):
            memory += 1;
            break;
         case('<'):
            memory -= 1;
            break;
         case('+'):
            *memory += 1;
            break;
         case('-'):
            *memory -= 1;
            break;
         case('['):
            char* loop = strfind(contents + i + 1, ']', size-i);
            //printf("%s", loop);
            while (*memory != 0) {
               parse(loop, strlen(loop), memory);
            }
            break;
         case(','):
            *memory = (int)getchar();
            break;
         case('.'):
            putchar((char)*memory);
            break;
      }
   }
   

}

int main(int argc, char* argv[])
{
   FILE* file;

   file = fopen(argv[1], "r");

   if (file == NULL)
   {
      printf("can't open brainfuck file. don't know what to tell you");
      return -1;
   }

   char contents[1000];
   int length;
   int* memory = calloc(100, sizeof(int));
   while(fgets(contents, 1000, file)) {}
   length = strlen(contents);
   parse(contents, length, memory);


   fclose(file);
}
