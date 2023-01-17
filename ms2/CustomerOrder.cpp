// Name: Samarth Shaileshkumar Patel
// Seneca email: sspatel74@seneca.ca
// Date of completion: 11/16/2022

#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"

using namespace std;

namespace sdds
{
  size_t CustomerOrder::m_widthField = 0u;

  CustomerOrder::CustomerOrder(const std::string &src)
  {
    Utilities newUtility;
    bool isVal = true;
    size_t pos = 0u;
    size_t index = 0u;

    try
    {
      m_name = newUtility.extractToken(src, pos, isVal);
      m_name.erase(0, m_name.find_first_not_of(' '));
      m_name.erase(m_name.find_last_not_of(' ') + 1);
      m_product = newUtility.extractToken(src, pos, isVal);
      m_product.erase(0, m_product.find_first_not_of(' '));
      m_product.erase(m_product.find_last_not_of(' ') + 1);
      m_cntItem = std::count(src.begin(), src.end(), newUtility.getDelimiter()) - 1;

      if (m_cntItem)
      {
        m_lstItem = new Item *[m_cntItem];
      }

      while (isVal && m_cntItem)
      {
        m_lstItem[index] = new Item(newUtility.extractToken(src, pos, isVal));
        ++index;
      }

      CustomerOrder::m_widthField = max(newUtility.getFieldWidth(), CustomerOrder::m_widthField);
    }
    catch (std::string err)
    {
      cout << err;
    }
  }

  CustomerOrder::CustomerOrder(const CustomerOrder &src)
  {
    throw false;
  }

  CustomerOrder::CustomerOrder(CustomerOrder &&src) noexcept
  {
    *this = std::move(src);
  }

  CustomerOrder &CustomerOrder::operator=(CustomerOrder &&src) noexcept
  {
    if (this != &src)
    {
      if (m_lstItem)
      {
        for (auto i = 0u; i < m_cntItem; ++i)
          delete m_lstItem[i];

        delete[] m_lstItem;
      }

      m_name = src.m_name;
      m_product = src.m_product;
      m_cntItem = src.m_cntItem;
      m_lstItem = src.m_lstItem;
      src.m_name = "";
      src.m_product = "";
      src.m_cntItem = 0u;
      src.m_lstItem = nullptr;
    }

    return *this;
  }

  CustomerOrder::~CustomerOrder()
  {
    if (m_lstItem)
    {
      for (auto i = 0u; i < m_cntItem; ++i)
        delete m_lstItem[i];

      delete[] m_lstItem;
      m_lstItem = nullptr;
    }
  }

  bool CustomerOrder::isOrderFilled() const
  {
    bool filled = true;

    for (auto i = 0u; i < m_cntItem; ++i)
    {
      if (!m_lstItem[i]->m_isFilled)
      {
        filled = false;
        break;
      }
    }

    return filled;
  }

  bool CustomerOrder::isItemFilled(const std::string &itemName) const
  {
    bool result = false;

    for (auto i = 0u; i < m_cntItem; ++i)
      m_lstItem[i]->m_itemName == itemName ? result = false : result = true;

    return result;
  }

  void CustomerOrder::fillItem(Station &station, std::ostream &os)
  {
    for (auto i = 0u; i < m_cntItem; ++i)
    {
      if (m_lstItem[i]->m_itemName == station.getItemName())
      {
        if (station.getQuantity())
        {
          station.updateQuantity();
          m_lstItem[i]->m_isFilled = true;
          m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
          os << "    Filled ";
        }
        else
          os << "    Unable to fill ";

        os << m_name << ", " << m_product << " [" << m_lstItem[i]->m_itemName << "]" << endl;
      }
    }
  }

  void CustomerOrder::display(std::ostream &os) const
  {

    os << m_name << " - " << m_product << endl;

    for (auto i = 0u; i < m_cntItem; ++i)
    {
      os << "[" << right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber << "] ";
      string itemName = m_lstItem[i]->m_itemName;
      itemName.erase(0, itemName.find_first_not_of(' '));
      os << left << setw(CustomerOrder::m_widthField) << setfill(' ') << itemName;
      os << " - " << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << endl;
    }
  }
}
