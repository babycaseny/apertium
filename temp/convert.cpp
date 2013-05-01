#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
vector< vector<string> >TOKEN_LIST;

void debug()
{
  for(int i=0;i<TOKEN_LIST.size();i++)
    {
      for(int j=0;j<TOKEN_LIST[i].size();j++)
	{
	  cout << TOKEN_LIST[i][j];
	  cout << " ";
	}
      cout << endl;
    }
}

bool read(char *arguments[])
{
  FILE *file = fopen(arguments[1],"r");
  string opt_raw = arguments[2];
  bool opt;
  if(opt_raw.compare("-r") == 0)opt = true;
  else if(opt_raw.compare("-f") == 0)opt = false;
  else
    {
      cout << "Cannot recognize the option!";
      exit(0);   
    }
  if(file == NULL)
    {
      cout << "Cannot open the file!";
      exit(0);
    }

  char temp;

  bool skip_all=true,start_convert=false;
  vector<string>tokens;
  string token;

  while(1)
    {
      temp = fgetc(file);
      if(temp == EOF)break;

      if(skip_all && temp != '^')continue;
      if(temp == '^')
	{
	  skip_all = false;
	  if(tokens.size() >0)
	    {
	      TOKEN_LIST.push_back(tokens);
	    }
	  tokens.clear();
	  token = "";

	  continue;
	}
      else if(temp == '/')
	{
	  if(start_convert == false)start_convert = true;
   	  else
	    {
	      tokens.push_back(token);
	      token = "";
	    }
	}
      else if(temp == '$')
	{
	  skip_all = true;
	  start_convert = false;
          tokens.push_back(token);
	  token = "";
	}
      else if(start_convert && temp!= '>')
	{
	  if(temp == '<')temp = '.';
	  token.append(&temp);
	}
    }
  TOKEN_LIST.push_back(tokens);
  //  debug();
  return opt;
}
void print()
{
  for(int i=0;i<TOKEN_LIST.size();i++)
    {
      for(int j=0;j<TOKEN_LIST[i].size();j++)
	{
	  cout << TOKEN_LIST[i][j];
	  cout << " ";
	}
      cout << endl;
    }
}
void print(bool opt)
{

  vector<int>indexes(TOKEN_LIST.size());
  if(opt)
    for(int i=0;i<TOKEN_LIST.size();i++)
       indexes[i] = rand()%TOKEN_LIST[i].size();
   for(int i=0;i<TOKEN_LIST.size();i++)
    {
      cout << TOKEN_LIST[i][indexes[i]];
      cout << " ";
    }
   cout << endl;
}

int main( int argc, char *argv[])
{
  bool opt = read(argv);
  print(opt);
  return 0;
}
