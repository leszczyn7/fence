/* v 2.1a m.leszczynski@norcom.net.pl */
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
using namespace std;

class Farm {
  public:
    long area(long a, long b) {
      return a * b;
    }
};

int main() {
  string doRun;
  cout << "Run algoritm? (Write RUN) ";
  cin >> doRun;
  if (doRun.compare("RUN")) {
      return 0;
  } 
  string cinFenceLength = "";
  long fenceLength = 0;
  do {
    cout << "Enterthe lenght of your fence (only numbers) > 2 and <= 8589934591: ";
    // 8589934591 = sqrt(8*LONG_MAX)
    // bestA = ceil(fenceLength/4)
    // bestB = fenceLength - 2 * bestA;
    cin >> cinFenceLength;
    fenceLength = atol(cinFenceLength.c_str());
  } while (fenceLength < 3 || fenceLength > 8589934591);

  long a = 1;
  long b = fenceLength - 2 * a;
  long currentArea = 0;
  long bestA = 0;
  long bestB = 0;
  long bestArea = 0;
  Farm farm;
  while (b > 0) {
    currentArea = farm.area(a, b);
    if (currentArea > bestArea) {
      bestA = a;
      bestArea = currentArea;
    }
    ++a;
    b = fenceLength - 2 * a;
  }
  bestB = fenceLength - 2 * bestA;
  bestArea = bestA * bestB;
    
  cout << "a = " << bestA<< endl;
  cout << "b = " << bestB << endl;
  cout << "Max area: " << bestArea << endl;
  cout << endl;
  return 0;
}