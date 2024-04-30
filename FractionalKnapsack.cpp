#include <algorithm>
#include<iostream>
using namespace std;

struct Item {
  int value;
  int weight;
};
static bool compare(Item i1, Item i2) {
  return (i1.value / i1.weight) > (i2.value / i2.weight);
}
double fractionalKnapsack(Item arr[], int n, int W) {
  sort(arr, arr + n, compare);
  double totalValue = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i].weight <= W) {
      W -= arr[i].weight;
      totalValue += arr[i].value;
    } else {
      totalValue += arr[i].value * ((double)W / arr[i].weight);
      break;
    }
  }
  return totalValue;
}
int main() {
  int n = 3;
  int W = 50;
  Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
  cout << "Maximum value we can obtain = " << fractionalKnapsack(arr, n, W);
  return 0;
}
