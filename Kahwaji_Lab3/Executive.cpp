#include "Executive.h"

int Executive::getLength(string word)
{
  int count =0;
  for(int i =0; i<80;i++)
  {
    if(word[i]=='\0')
    {
      return count;
      break;
    }
    else
    {
      count++;
    }
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

Executive::~Executive()
{
  delete[] m_DoubleHash.getArray();
  delete[] m_QuadhashTable.getArray();
}
Executive::Executive(string fileName)
{
  inFile.open(fileName);
  string resName;
  string resRating;
  string resRange;
  m_QuadhashTable = HashTableQuad(31);
  m_DoubleHash = DoubleHashTable(31);
  cout << "File Reading: " << endl;
  while(inFile >> resName >> resRating >> resRange)
  {
    resName = cleanString(resName);
    resRating = cleanString(resRating);
    resRange = cleanString(resRange);
    int rating = (int)resRating[0] -'0';
    //initial object added to first hash table
    Yelp generic;
    generic.setName(resName);
    generic.setRating(rating);
    generic.setPriceRange(resRange);
    generic.setStatus(true);
    cout << "Quadratic probing: ";
    m_QuadhashTable.insert(generic);
    //Second object added to second hash HashTable
    Yelp secondYelp;
    secondYelp.setName(resName);
    secondYelp.setRating(rating);
    secondYelp.setPriceRange(resRange);
    generic.setStatus(true);
    cout << "Double Hashing: ";
    m_DoubleHash.insert(secondYelp);
  }
  cout << "-------------------------------------------------" << endl;
  PrintMenu();
}

void Executive::Insert()
{
  string ResName;
  int resRating;
  string ResRange;
  cout << "Enter the data to be inserted:" << endl;
  cout << ">";
  cin >> ResName >> resRating >> ResRange;
  Yelp genericObjec;
  genericObjec.setName(ResName);
  genericObjec.setRating(resRating);
  genericObjec.setPriceRange(ResRange);
  cout << "Quadratic probing: ";
  m_QuadhashTable.insert(genericObjec);
  cout << endl;
  Yelp secondGeneric;
  secondGeneric.setName(ResName);
  secondGeneric.setRating(resRating);
  secondGeneric.setPriceRange(ResRange);
  cout << "Double Hashing: ";
  m_DoubleHash.insert(secondGeneric);
  cout << endl;
}
void Executive::Delete()
{
  string res;
  cout << "Enter a restaraunt to be deleted:" << endl;
  cout << ">";
  cin >> res;
  cout << "Quadratic probing: ";
  m_QuadhashTable.Delete(res);
  cout << endl;
  cout << "Double Hashing: ";
  m_DoubleHash.Delete(res);
  cout << endl;
}
void Executive::FindByName()
{
  string word;
  cout << "Enter a restaraunt to be found:" << endl;
  cout << ">";
  cin >> word;
  cout << endl;
  cout << "Quadratic Probing: ";
  m_QuadhashTable.FindByName(word);
  cout << endl;
  cout << "Double Hashing: ";
  m_DoubleHash.FindByName(word);
  cout << endl;
}
void Executive::FindByRating()
{
  int rating;
  cout << "Please enter the rating for restaraunts you want to find: " << endl;
  cout << ">";
  cin >> rating;
  cout << "Quadratic Probing: ";
  m_QuadhashTable.FindByRating(rating);
  cout << endl;
  cout << "Double Hashing: ";
  m_DoubleHash.FindByRating(rating);
  cout << endl;
}
void Executive::SearchByPrice()
{
  string Price;
  cout << "Please enter your price range: " << endl;
  cout << ">";
  cin >> Price;
  cout << "Quadratic Probing: ";
  m_QuadhashTable.SearchByPrice(Price);
  cout << endl;
  cout << "Double Hashing: ";
  m_DoubleHash.SearchByPrice(Price);
  cout << endl;
}
void Executive::Print()
{
  cout << endl;
  cout << "Quadratic probing: " << endl << endl;
  m_QuadhashTable.Print();
  cout << "Double Hashing: " << endl << endl;
  m_DoubleHash.Print();

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
    cout<< "3- FindByName" << endl;
    cout << "4- FindByRating" <<endl;
    cout << "5- SearchByPrice" << endl;
    cout << "6- Print" << endl;
    cout << "7- Exit" << endl;
    cin >> selection;

    if(selection==1)
      Insert();
    if(selection ==2)
      Delete();
    if(selection ==3)
      FindByName();
    if(selection ==4)
      FindByRating();
    if(selection ==5)
      SearchByPrice();
    if(selection ==6)
      Print();
    if(selection==7)
    {
      cout << "Done!" << endl;
      break;
    }



  }
}
