/* 
v 1.6a 
Miroslaw Leszczynski 
m.leszczynski@norcom.net.pl
*/
#include <iostream>
#include <limits>
using namespace std;

class Farm {
  public:
    int area(int a, int b) {
      return a * b;
    }
};
int takeFenceLength() {
  cout << "Enter the lenght of your fence (only numbers): ";
  int fenceLenght;
  cin >> fenceLenght;
  return fenceLenght;
}

int main() {
  string doRun;
  cout << "Run algoritm? (Write RUN) ";
  cin >> doRun;
  if (doRun.compare("RUN")) {
      return 0;
  }
  int fenceLenght = 0;
  do {
    cout << "Enterthe lenght of your fence (onl numbers): ";
    if(cin >> fenceLenght) break;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  } while (true);

  int a = 1;
  int b = fenceLenght - 2 * a;
  int currentArea = 0;
  int bestA = 0;
  int bestB = 0;
  int bestArea = 0;
  Farm farm;
  while (b > 0) {
    currentArea = farm.area(a, b);
    if (currentArea > bestArea) {
      bestA = a;
      bestArea = currentArea;
    }
    ++a;
    b = fenceLenght - 2 * a;
  }
  bestB = fenceLenght - 2 * bestA;
  bestArea = bestA * bestB;
    
  cout << "a = " << bestA<< endl;
  cout << "b = " << bestB << endl;
  cout << "Max area: " << bestArea << endl;
  cout << endl;
  return 0;
}