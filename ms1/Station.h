// Name: Samarth Shaileshkumar Patel
// Seneca email: sspatel74@seneca.ca
// Date of completion: 11/16/2022

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iostream>

namespace sdds
{
  class Station
  {
    int stationID{0};
    std::string itemName{""};
    std::string stationDescription{""};
    size_t nextSerialNum{0u};
    size_t numItems{0u};
    static size_t m_widthField;
    static size_t id_generator;

  public:
    Station(const std::string &src);
    const std::string &getItemName() const;
    size_t getNextSerialNumber();
    size_t getQuantity() const;
    void updateQuantity();
    void display(std::ostream &os, bool full) const;
  };
}
#endif // !SDDS_STATION_H
