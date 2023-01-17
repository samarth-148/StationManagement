// Name: Samarth Shaileshkumar Patel
// Seneca Student ID: 143147213
// Seneca email: sspatel74@seneca.ca
// Date of completion: 11/16/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <string>
#include <vector>
#include <list>
namespace sdds
{
	class Station
	{
	private:
		int m_id{};
		std::string m_itemName{};
		std::string m_description{};
		size_t m_nextSerial{};
		size_t m_itemsNum{};

	public:
		Station(const std::string &record);
		const std::string &getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream &os, bool full) const;
	};
}
#endif