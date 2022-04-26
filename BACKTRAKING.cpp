#include <iostream>
#include<limits.h>
using namespace std;
class Subset
{
public:
void printSum(int result[], int front, int tail)
{
cout << "[";
for (int i = front; i < tail; ++i)
{
if (result[i] != INT_MAX)
{
cout << " " << result[i] << " ";
}
}
cout << "]\n";
}
void subsetSum(int arr[], int result[], int sum, int size, int current_sum, int location)
{
if (location == -1)
{
return;
}
this->subsetSum(arr, result, sum, size, current_sum, location - 1);
result[location] = arr[location];
if (current_sum + arr[location] == sum)
{
this->printSum(result, location, size);
}
this->subsetSum(arr, result, sum, size, current_sum + arr[location], location - 1);
result[location] = INT_MAX;
}
void findSubset(int arr[], int size, int sum)
{
if (size <= 0)
{
return;
}
int result[size];
for (int i = 0; i < size; ++i)
{
result[i] = INT_MAX;
}
cout << "Subset Sum of " << sum << " is \n";
this->subsetSum(arr, result, sum, size, 0, size - 1);
}
};
int main()
{
Subset task = Subset();
int n;
cout<<" enter the element of set"<<endl;
cin>>n;
cout<<"enter the array element"<<endl;
int arr[n]={};
for(int i=0;i<n;i++){
cin>>arr[i];
}
int size = sizeof(arr) / sizeof(arr[0]);
int sum;
cout<<"\n enter the sum element"<<endl;
cin>>sum;
task.findSubset(arr, size, sum);
return 0;
}
