// fence v.1.2
#include <iostream>
using namespace std;

class Farm {
  public:
    int fenceLenght;
    int area(int a) {
      int b = fenceLenght - 2 * a;
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

  int fenceLenght = 0;
  while (fenceLenght < 3) {
    // cin.clear();
    // cin.ignore(numeric_limits<int 3>::max());
    cout << "Enter lenght of your fence (onl int number): ";
    cin >> fenceLenght;
  } 

  int area = 0;
  int bestA = 0;
  Farm farm;
  farm.fenceLenght = fenceLenght;
  for (int a = 1; a < fenceLenght/2 + 1; a++) {
    if(farm.area(a)>area) {
      area = farm.area(a);
      bestA = a;
    }
  }
    
  cout << "\nMax area for the fence length " << fenceLenght << " is: " << area << endl;
  cout << " for a = " << bestA << endl;
  cout << " and b = " << fenceLenght - 2 * bestA << "\n\n";
  return 0;
}