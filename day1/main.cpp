#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

pair<vector<int>, vector<int>> readCsv(const string &filename);
void sortList(std::vector<int> &array);
long long totalDistance(std::vector<int> lList, std::vector<int> rList);

int main(int argc, char *argv[]) {
  cout << argv[1] << endl;
  auto [left, right] = readCsv(argv[1]);
  sortList(left);
  sortList(right);
  int totalDist = totalDistance(left, right);
  cout << "Total Distance: " << totalDist << endl;

  return 0;
}

pair<vector<int>, vector<int>> readCsv(const string &filename) {
  vector<int> left;
  vector<int> right;
  ifstream fin;

  fin.open(filename);
  string line;

  if (!fin.is_open()) {
    cerr << "Error opening file: " << filename << endl;
    return {left, right};
  }

  cout << "Reading file: " << filename << endl;
  while (getline(fin, line)) {
    if (line.empty())
      continue;
    stringstream ss(line);
    int val1, val2;

    if (ss >> val1 >> val2) {
      left.push_back(val1);
      right.push_back(val2);
    } else {
      cerr << "Error reading line: " << line << endl;
    }
  }
  fin.close();
  return {left, right};
}

void sortList(std::vector<int> &array) {
  int arrSize = array.size();
  for (int i = 0; i < arrSize - 1; i++) {
    for (int j = 0; j < arrSize - i - 1; j++) {
      if (array[j] > array[j + 1]) {
        int temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

long long totalDistance(std::vector<int> lList, std::vector<int> rList) {
  int totalDistance = 0;
  int leftListSize = lList.size();
  for (int i = 0; i < leftListSize; i++) {
    totalDistance += abs(lList[i] - rList[i]);
  }
  return totalDistance;
}
