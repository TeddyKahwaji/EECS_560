#ifndef YELP_H
#define YELP_H
#include <iostream>
#include <cstring>
using namespace std;
class Yelp
{
public:
void setName(string name);
void setRating(int rating);
void setPriceRange(string range);
string getName();
int getRating();
string getPriceRange();
bool isEmpty();
void setStatus(bool status);

bool operator==(Yelp rhs);
bool operator!=(Yelp rhs);
private:
  string m_restarauntName;
  int m_rating;
  string m_priceRange;
  bool m_isEmpty = true;
};
#endif
