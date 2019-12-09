#include "Executive.h"

int Executive::getLength(string word)
{
  int length =0;
  for(int i =0; i<50;i++)
  {
    if(word[i] == '\0')
    {
      return length;
    }
    length++;
  }

}



string Executive::cleanString(string word)
{
  int length = getLength(word);
  string newWord;
  for(int i =0; i<length; i++)
  {
    if(word[i] == ',')
    {
      //Do nothing
    }
    else
    {
      newWord = newWord + word[i];
    }

  }

  return newWord;
}

Executive::Executive(string fileName)
{
  inFile.open(fileName);
  string word;
  m_hashTable = HashTable(5);
  while(inFile >> word)
  {
    if(word == "elements:")
    {
        // do nothing
    }
    else
    {
      word = cleanString(word);
      m_hashTable.insert(word);
    }

  }
  PrintMenu();
}

void Executive::Insert()
{
  string word;
  cout << "Enter an element to be inserted:" << endl;
  cout << ">";
  cin >> word;
  word = cleanString(word);
  m_hashTable.insert(word);
}
void Executive::Delete()
{
  string word;
  cout << "Enter an element to be removed:" << endl;
  cout << ">";
  cin >> word;
  m_hashTable.Delete(word);
}
void Executive::Find()
{
  string word;
  cout << "Enter an element to be found:" << endl;
  cout << ">";
  cin >> word;
  m_hashTable.Find(word);
}
void Executive::Print()
{
  cout << endl;
  m_hashTable.Print();
}
void Executive::PrintMenu()
{
  while(1)
  {
    cout << endl;
    int selection;
    cout << "Please choose one of the following commands:" << endl;
    cout << "1- Insert" << endl;
    cout << "2- Delete" << endl;
    cout<< "3- Find" << endl;
    cout << "4- Print" <<endl;
    cout << "5- Exit" << endl;
    cin >> selection;

    if(selection==1)
      Insert();
    if(selection ==2)
      Delete();
    if(selection ==3)
      Find();
    if(selection ==4)
      Print();
    if(selection==5)
    {
      cout << "Bye Bye!" << endl;
      break;
    }



  }
}
