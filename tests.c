/**
Unit tests for environval() function
*/
#include "utils.h"

void environvalFindsPathVariable()
{
  printf("\nenvironValFindsPathVariable ====================\n");
  char* env[4] = {
    "PATHEXT=PATH",
    "PATH=hello",
    "TEST=blargh",
    NULL // The end of the 'environ' variable is marked with a NULL
  };

  char* result = environval("PATH", env);
  if (result == NULL)
  {
    printf("FAILED: result was null, should have been 'hello'.\n");
  } else if (strcmp(result, "hello") != 0) {
    printf("FAILED: result was '%s' instead of 'hello'.\n", result);
  }
}

void environvalFindsPathVariableWhenAPartialMatchExists()
{
  printf("\nenvironvalFindsPathVariableWhenAPartialMatchExists ====================\n");
  char* env[3] = {
    "PATH=blah",
    "PATHEXT=blahblah",
    NULL // The end of the 'environ' variable is marked with a NULL
  };

  char* result = environval("PATHEXT", env);
  if (result == NULL)
  {
    printf("FAILED: result was null, should have been 'blahblah'.\n");
  } else if (strcmp(result, "blahblah") != 0) {
    printf("FAILED: result was '%s' instead of 'blahblah'.\n", result);
  }
}

void environvalFindsNoPathVariable()
{
  printf("\nenvironvalFindsNoPathVariable ====================\n");
  char* env[3] = {
    "BLAH=PATH",
    "TEST=path",
    NULL // The end of the 'environ' variable is marked with a NULL
  };

  char* result = environval("PATH", env);
  if (result != NULL)
  {
    printf("FAILED: result should have been NULL\n");
  }
}

void environvalFindsNoPathVariableWhenEnvironmentIsEmpty()
{
  printf("\nenvironvalFindsNoPathVariableWhenEnvironmentIsEmpty ====================\n");
  char* env[1] = {
    NULL // The end of the 'environ' variable is marked with a NULL
  };

  char* result = environval("PATH", env);
  if (result != NULL)
  {
    printf("FAILED: result should have been NULL\n");
  }
}

void environvalWorksIfVariablesAreShorterThanName()
{
  printf("\nenvironvalWorksIfVariablesAreShorterThanName ====================\n");
  char* env[3] = {
    "A=1",
    "B=2",
    NULL // The end of the 'environ' variable is marked with a NULL
  };

  char* result = environval("VERY_VERY_VERY_VERY_VERY_VERY_VERY_VERY_LONG_NAME", env);
  if (result != NULL)
  {
    printf("FAILED: result should have been NULL\n");
  }
}

int main(int argc, char** argv)
{
  environvalFindsPathVariable();
  environvalFindsPathVariableWhenAPartialMatchExists();
  environvalFindsNoPathVariable();
  environvalFindsNoPathVariableWhenEnvironmentIsEmpty();
  environvalWorksIfVariablesAreShorterThanName();
}
