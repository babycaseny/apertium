#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;


void read(char *arguments[])
{
  FILE *file = fopen(arguments[1],"r");
  if(file == NULL)
    {
      cout << "Cannot open the file!";
      exit(0);
    }

  char temp;
  string token;
  bool skip_all=true,start_convert=false;

  while(1)
    {
      temp = fgetc(file);
      if(temp == EOF)break;

      if(skip_all && temp != '^')continue;
      if(temp == '^')
	{
	  skip_all = false;
	  cout << " ";
	  continue;
	}
      else if(temp == '/')
	{
	  if(start_convert == false)start_convert = true;
   	  else
	    {
	      skip_all = true;
	      start_convert = false;
	    }
	}
      else if(temp == '$')
	{
	  skip_all = true;
	  start_convert = false;
	}

      else if(start_convert && temp!= '>')
	{
	  if(temp == '<')temp = '.';
	  cout << temp;
	}
    }
  cout << endl;
}
int main( int argc, char *argv[])
{
  read(argv);
  return 0;
}
