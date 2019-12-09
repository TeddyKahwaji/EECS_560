#include "Yelp.h"



void Yelp::setName(string name)
{
  m_restarauntName = name;
}

void Yelp::setRating(int rating)
{
  m_rating = rating;
}

void Yelp::setPriceRange(string range)
{
  m_priceRange = range;
}


string Yelp::getName()
{
  return m_restarauntName;
}

int Yelp::getRating()
{
  return m_rating;
}

string Yelp::getPriceRange()
{
  return m_priceRange;
}

bool Yelp::isEmpty()
{
  return m_isEmpty;
}

bool Yelp::operator==(Yelp rhs)
{
  return (rhs.getName() == m_restarauntName && rhs.getRating() == m_rating && rhs.getPriceRange() == m_priceRange);
}
bool Yelp::operator!=(Yelp rhs)
{
  return (rhs.getName() != m_restarauntName && rhs.getRating() != m_rating && rhs.getPriceRange() != m_priceRange);
}
void Yelp::setStatus(bool status)
{
  m_isEmpty = status;
}
