/*Tyler Allen
CS111
Assignment 6 Program 2
4-14-15
This program will produce a report that displays sales for each salsa type, total sales, and the names of the highest selling and lowest selling products.*/

#include <iostream>
using namespace std;
#include <iomanip>

void fillJarsSoldArray(const string types[], int jars[], int size);// prompts the user to enter the number of jars sold for each type and fills the jars sold array.
void printSales(const string types[], const int jars[], int size); //displays sales for each salsa type.  
int getTotal(const int jars[], int size); // returns the total sales. Display the total in the main. 
int getHighestLowestSelling(const int jars[], int size, int &lowest);
 //passes back the indices of the highest and lowest selling salsas. Display the highest and lowest selling types in the main.     

int main(){
  const int SIZE=5;
  string types[] = {"mild", "medium", "sweet", "hot", "zesty"};
  int jars[SIZE];
  int lowest;
  int highest;
  fillJarsSoldArray(types, jars, SIZE);
  printSales(types, jars, SIZE);
  cout<<"The total number of sales is "<<getTotal(jars, SIZE)<<endl;
  highest= getHighestLowestSelling(jars, SIZE, lowest);
  cout<<"The highest selling type is "<<types[highest]<<endl;
  cout<<"The lowest selling type is "<<types[lowest]<<endl;
  
  return 0;
}

void fillJarsSoldArray(const string types[], int jars[], int size)
{
  for(int i=0;i<size;i++)
    {
      do{
      cout<<"Enter the number of jars sold for "<<types[i]<<": ";
      cin>>jars[i];
      }while(jars[i]<0);
    }
}

void printSales(const string types[], const int jars[], int size)
{
  cout<<endl<<endl<<endl;
  for(int i=0;i<size;i++)
    {
      cout<<left<<setw(8)<<types[i]<<right<<setw(8)<<jars[i]<<endl;
    }
}

int getTotal(const int jars[], int size)
{
int total=0;
for(int i =0; i<size;i++)
  {
    total+=jars[i];
  }
return total;
}

int getHighestLowestSelling(const int jars[], int size, int &lowest)
{
  int highest= 0;
  lowest = 0;

  for(int i=0;i<size;i++)
    {
      if(jars[i]>jars[highest])
	highest=i;
      if(jars[i]<jars[lowest])
	lowest=i;
    }
  return highest;
}
