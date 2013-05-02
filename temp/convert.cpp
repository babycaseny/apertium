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
bool alphabetic(char c){return (c>='A' && c<='Z') || (c>='a' && c<='z');}

void printdecoded()
{
  vector<int>indexes(TOKEN_LIST.size());
  for(int i=0;i<TOKEN_LIST.size();i++)
    {

      if(TOKEN_LIST[i].size() == 1)
	{
	  cout << "^../.." << TOKEN_LIST[i][0] << "$"<< endl;
	  continue;
	}
      cout << "^"<< TOKEN_LIST[i][0] << "/" << TOKEN_LIST[i][0];
      for(int j=1;j<TOKEN_LIST[i].size();j++)
	cout << "<" << TOKEN_LIST[i][j] << ">";
      cout << "$" << endl;
    }
}

void deconvert(FILE *file)
{
  bool skip_all=true,start_lemma=false;
  vector<string>tokens;
  string lemma;
  char temp;

  while(1)
    {
      temp = fgetc(file);
      if(temp == EOF)break;

      if(skip_all && !alphabetic(temp))continue;
      if(alphabetic(temp))
	{
	  if(start_lemma == false)
	    {
	      lemma = "";
	      start_lemma = true;
	      skip_all = false;
	    }
	  lemma.append(&temp);
	}
      if(temp == '.')
	{
	  tokens.push_back(lemma);
	  lemma = "";
	}
      else if(!alphabetic(temp))
	{
	  tokens.push_back(lemma);
	  lemma = "";
	  start_lemma = false;
	  skip_all = true;
	  TOKEN_LIST.push_back(tokens);
	  tokens.clear();
	}
    }
  //debug();
  printdecoded();
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

void read(char *arguments[],int argc)
{
  FILE *file = fopen(arguments[1],"r");
  if(file == NULL || argc <= 2)
    {
      cout << "Error with the input arguments!";
      exit(0);
    }


  string opt_raw = arguments[2];
  bool opt;
  if(opt_raw.compare("-r") == 0)opt = true;
  else if(opt_raw.compare("-f") == 0)opt = false;
  else if(opt_raw.compare("-d") == 0)
    {
      deconvert(file);
      return;
    }
  else
    {
      cout << "Cannot recognize the option!";
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
  print(opt);
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

int main( int argc, char *argv[])
{
  read(argv,argc); 
  return 0;
}

