// Name: Samarth Shaileshkumar Patel
// Seneca Student ID: 143147213
// Seneca email: sspatel74@seneca.ca
// Date of completion: 11/16/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <string>
#include <vector>
#include <list>
namespace sdds
{

	class Utilities
	{
	private:
		size_t m_widthField{1};

	public:
		static void setDelimiter(char newDelimiter);
		static char getDelimiter();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string &str, size_t &next_pos, bool &more);
	};
}
#endif