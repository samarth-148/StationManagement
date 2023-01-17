// Name: Samarth Shaileshkumar Patel
// Seneca email: sspatel74@seneca.ca
// Date of completion: 11/16/2022

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
  size_t Station::m_widthField = 0u;
  size_t Station::id_generator = 0u;

  Station::Station(const std::string &src)
  {
    Utilities util;
    stationID = ++Station::id_generator;
    bool more = true;
    size_t pos = 0u;

    try
    {
      itemName = util.extractToken(src, pos, more);
      nextSerialNum = stoi(util.extractToken(src, pos, more));
      numItems = stoi(util.extractToken(src, pos, more));
      Station::m_widthField = max(util.getFieldWidth(), Station::m_widthField);
      stationDescription = util.extractToken(src, pos, more);
    }
    catch (std::string err)
    {
      cout << err;
    }
  }

  const std::string &Station::getItemName() const
  {
    return itemName;
  }

  size_t Station::getNextSerialNumber()
  {
    ++nextSerialNum;
    return nextSerialNum - 1;
  }

  size_t Station::getQuantity() const
  {
    return numItems;
  }

  void Station::updateQuantity()
  {
    numItems == 0 ? numItems = 0 : --numItems;
  }

  void Station::display(std::ostream &os, bool full) const
  {

    os << setw(3) << setfill('0') << stationID << " | ";
    os << left << setw(Station::m_widthField) << setfill(' ') << itemName << " | ";
    os << right << setw(6) << setfill('0') << nextSerialNum << " | ";

    if (full)
    {

      os << right << setw(4) << setfill(' ') << numItems << " | ";
      string desc = stationDescription;
      while (desc[0] == ' ')
      {
        desc.erase(0, 1);
      }

      os << desc << endl;
    }

    else
      os << endl;
  }
}
