#include<iostream>
using namespace std;

struct Job {
  char id;
  int deadline;
  int profit;
};
int n=5;
Job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
            {'d', 1, 25}, {'e', 3, 15}};
void sortByProfit(Job arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i].profit < arr[j].profit) {
        Job temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
int getMaxDeadline(Job arr[], int n) {
  int max = arr[0].deadline;
  for (int i = 1; i < n; i++) {
    if (arr[i].deadline > max) {
      max = arr[i].deadline;
    }
  }
  return max;
}
void sequenceJobs(Job arr[], int n) {
  sortByProfit(arr, n);
  int maxDeadline = getMaxDeadline(arr, n);
  char *result=new char[maxDeadline];
  bool *slot=new bool[maxDeadline];
  int profit=0;
  for (int i = 0; i < maxDeadline; i++) {
    slot[i] = false;
  }
  for (int i = 0; i < n; i++) {
    for (int j = min(maxDeadline, arr[i].deadline) - 1; j >= 0; j--) {
      if (slot[j] == false) {
        result[j] = arr[i].id;
        slot[j] = true;
        profit+=arr[i].profit;
        break;
      }
    }
  }
  cout << "Sequence of jobs: ";
  for (int i = 0; i < maxDeadline; i++) {
    if (slot[i]) {
    cout << result[i] << " ";
    }
  }
  cout << endl;
  cout<<"The profit is: "<<profit<<endl;
}
int main() {
  sequenceJobs(arr, n);
  return 0;
}
