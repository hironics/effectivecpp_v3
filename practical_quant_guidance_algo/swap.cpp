
#include <iostream>

using namespace std;

void printij(int i, int j)
{
  std::cout << "i=" << i << ",j=" << j << std::endl;
}
int main()
{
  int i = 2, j=3;
  printij(i,j );

  // swap
  i = i+j;
  j = i - j;
  i = i - j; 
  printij(i,j );
	
}
