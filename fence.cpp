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
  char doRun;
  do {
    cin.clear();
    cout << "Run? (y/n) ";
    cin >> doRun;
  } while (doRun != 'y' && doRun != 'n');
  if (doRun == 'n') {
    return 0;
  }

  int fenceLenght;
  do {
    cin.clear();
    cout << "Enter lenght of your fence (onl int number): ";
    cin >> fenceLenght;
  } while (!fenceLenght > 0);

  Farm farm;
  int area = 0;
  int bestA = 0;
  farm.fenceLenght = fenceLenght;
  for (int a = 1; a < fenceLenght/2; a++) {
    if(farm.area(a)>area) {
      area = farm.area(a);
      bestA = a;
    }
  }
  cout << "\nMax area for the fence length " << fenceLenght << " is: " << area << endl;
  cout << " for a = " << bestA << endl;
  cout << " and b = " << fenceLenght - 2 * bestA << "\n\n";
}
