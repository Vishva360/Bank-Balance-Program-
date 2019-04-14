// Vishva Patel
//Section #2
using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
struct  PERSON {
    char  Name[20];
    float Balance; };

void printmenu();
PERSON * readData(int  N);
void Display(PERSON P[], int N,fstream &inData);
void findRichest(PERSON P[], int N);
void Deposit(PERSON P[], int N, string & custName, float & amount);
void NewCopy(fstream &inData, string fileName, PERSON P[], int N);
int main()
{
  string records;
  fstream inData;
  string custName;
  float amount = 0;

  int N = 0;
  inData.open("Data.txt", ios::in | ios::out);// You need ios to tell the system what you are doing with the file
  while (getline(inData, records)) //Getting the number of people in the file
  {
    N++;
  }
  inData.close(); // close to re-index the file


PERSON * P = readData(N);


    int choice;
    do
    {
        printmenu();
        cin >> choice;
        cin.ignore();
        switch(choice)
        {
            case 1:
                // Act on display
                Display(P,N, inData);
                break;

            case 2:
                // Act on deposit
                cout << "Enter your full name to deposit money:\t";
                getline(cin, custName);

                cout << custName << " how much would you like to deposit?\t";
                cin >> amount;
                Deposit(P,  N, custName, amount);
                break;

            case 3:
                // Act highest balance
                findRichest(P,N);
                break;

            case 4:
                // Act on update records
                inData.open("Data.txt", ios::in | ios::out);
                NewCopy(inData,"Data.txt", P, N);
                inData.close();
                break;

            case 5:
                // Must call update records here before exiting the program
                inData.open("Data.txt", ios::in | ios::out);
                NewCopy(inData,"Data.txt", P, N);
                inData.close();
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 5);






return 0;
}

PERSON * readData(int N)
{
  ifstream inData;
  string records;
  string fName;
  string lName;
  string fullName;

  inData.open("Data.txt", ios::in | ios::out);
  cout << "The number of records in the file is " << N << endl;

  PERSON * P;
  P = new PERSON[N];

    for(int i = 0; i < N; i++)
    {
    inData >> fName  >> lName >> P[i].Balance;
    fName = fName.substr(0,9);
    lName = lName.substr(0,10);
    fullName = fName + " " + lName; //Combining both strings in order to manipulate below
    strcpy(P[i].Name, fullName.c_str());
    }

return P;
}
void Display(PERSON P[], int N, fstream &inData)
{
  cout << "Name \t\t Balance \n\n  ----------------------------------------------- \n\n";
  for (int i = 0; i < N; i++)
  {
    cout <<  setw(20) << left << P[i].Name  << "\t\t" << setw(10) << left  << P[i].Balance <<  endl;
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


void Deposit(PERSON P[], int N, string & custName, float & amount)
{
  bool checker = false;
  for (int i = 0; i < N; i++)
    {
      if(strcmp(P[i].Name, custName.c_str()) == 0)
      {
        checker = true;
        P[i].Balance += amount;
        cout << "Your new balance is:\t" << P[i].Balance << endl;
        break;
      }

    }
    if(checker == false)
     {
     cout << "Record not found!" << endl;
     }

}
void NewCopy(fstream &inData, string fileName, PERSON P[], int N)
{
  for (int i = 0; i < N; i++)
  {
    inData  << P[i].Name << "\t"  << P[i].Balance << endl;
  }
  cout << "File updated..." << endl;
}

void printmenu() {
    cout << "Please enter a choice:" << endl;
    cout << "1. Display records"<< endl;
    cout << "2. Deposit funds"<< endl;
    cout << "3. Find Highest Balance" << endl;
    cout << "4. Update records" << endl;
    cout << "5. Exit the program" << endl;
}
