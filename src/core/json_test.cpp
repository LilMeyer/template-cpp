#include <iostream>
#include "../third_party/example/example.cpp"


#include <unistd.h>
#define GetCurrentDir getcwd


int main() {
  std::cout << "Json test" << std::endl;
  char cCurrentPath[400];

  if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) {
    return errno;
  }

  printf ("The current working directory is %s\n", cCurrentPath);
  EXAMPLE_1();
  return 0;
}
