using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
struct  PERSON {
    char  Name[20];
    float Balance; };


void Display(PERSON a[], int N,fstream &inData);
void findRichest(PERSON P[], int N);
void Deposit(string custName, PERSON a[], int N, fstream &inData);
void NewCopy(fstream &inData, string fileName, PERSON a[], int N);
int main()
{
  int N = 0;

  string records;
  string fName;
  string lName;
  string fullName;
  fstream inData;

inData.open("Data.txt", ios::in | ios::out);// You need ios to tell the system what you are doing with the file

  while (getline(inData, records)) //Getting the number of people in the file
  {
    N++;
  }
PERSON P[N];

inData.close(); // close to re-index the file

inData.open("Data.txt", ios::in | ios::out);
cout << "The number of records in the file is " << N << endl;


  for(int i = 0; i < N; i++)
  {
  inData >> fName >> lName >> P[i].Balance;
  fullName = fName + " " + lName; //Combining both strings in order to manipulate below
  strcpy(P[i].Name, fullName.c_str());
  }
PERSON a[N]; // new array for objects to be displayed
  for  (int j = 0; j < N; j++)
  {
    a[j] = P[j];
  }

findRichest(a,N);
Display(a,N, inData);
cout << "Enter your full name to deposit money:\t";

string custName;

getline(cin, custName);

Deposit(custName, a, N, inData);


inData.close();

inData.open("Data.txt", ios::in | ios::out);
NewCopy(inData,"Data.txt", a, N);
inData.close();
return 0;
}
void Display(PERSON a[], int N, fstream &inData)
{
  cout << "Name \t\t Balance \n\n  ----------------------------------------------- \n\n";
  for (int i = 0; i < N; i++)
  {
    cout << a[i].Name << "\t\t" << a[i].Balance << endl;
  }

}

void findRichest(PERSON P[], int N) //Finds the person with the highest balance
{
float highest;
int index = 0;
highest = P[0].Balance;
  for (int i = 0; i < N; i++)
{
  if(P[i].Balance > highest)
  {
    highest = P[i].Balance;
    index = i;
  }
}
  cout << "The customer with the largest balance is " << P[index].Name << ". \n\n";
}


void Deposit(string custName, PERSON a[], int N, fstream &inData)
{
  float depositAmount = 0;


  cout << custName << " how much would you like to deposit?\t";
  cin >> depositAmount;
  cin.ignore();
  for (int i = 0; i < N; i++)
    {
      if(strcmp(a[i].Name, custName.c_str()) == 0)
    {
  a[i].Balance += depositAmount;
  cout << "Your new balance is:\t" << a[i].Balance << endl;
    }
    }
}
void NewCopy(fstream &inData, string fileName, PERSON a[], int N)
{

  for (int i = 0; i < N; i++)
  {
    inData << a[i].Name << "\t" << a[i].Balance << endl;
  }

}
