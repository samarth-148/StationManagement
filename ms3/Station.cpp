// Name: Samarth Shaileshkumar Patel
// Seneca Student ID: 143147213
// Seneca email: sspatel74@seneca.ca
// Date of completion: 11/16/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <iostream>
#include <algorithm>
#include "Station.h"
#include "Utilities.h"

using namespace std;
namespace sdds
{

	static size_t m_widthField = 0;
	static int id_generator = 0;

	Station::Station(const std::string &record)
	{
		m_id = ++id_generator;
		size_t next_pos = 0;
		Utilities util;
		bool more = true;
		m_itemName = util.extractToken(record, next_pos, more);
		m_nextSerial = stoi(util.extractToken(record, next_pos, more));
		m_itemsNum = stoi(util.extractToken(record, next_pos, more));
		m_widthField = std::max(util.getFieldWidth(), m_widthField);
		m_description = util.extractToken(record, next_pos, more);
	}
	const std::string &Station::getItemName() const
	{
		return m_itemName;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_nextSerial++;
	}
	size_t Station::getQuantity() const
	{
		return m_itemsNum;
	}
	void Station::updateQuantity()
	{
		if (m_itemsNum > 0)
			m_itemsNum--;
	}
	void Station::display(std::ostream &os, bool full) const
	{
		if (!full)
		{
			os.width(3);
			os.fill('0');
			os.setf(ios::right);
			os << m_id;
			os.unsetf(ios::right);
			os.fill(' ');
			os << " | ";
			os.width(m_widthField);
			os.setf(ios::left);
			os << m_itemName;
			os.unsetf(ios::left);
			os << "  | ";
			os.setf(ios::right);
			os.width(6);
			os.fill('0');
			os << m_nextSerial;
			os.unsetf(ios::right);
			os.fill(' ');
			os << " | ";
		}
		else
		{
			os.width(3);
			os.fill('0');
			os.setf(ios::right);
			os << m_id;
			os.unsetf(ios::right);
			os.fill(' ');
			os << " | ";
			os.width(m_widthField);
			os.setf(ios::left);
			os << m_itemName;
			os << "  | ";
			os.setf(ios::right);
			os.width(6);
			os.fill('0');
			os << m_nextSerial;
			os.fill(' ');
			os << " | ";
			os.width(4);
			os << m_itemsNum;
			os.unsetf(ios::right);
			os << " | ";
			os << m_description;
		}
		os << endl;
	}
}