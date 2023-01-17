// Name: Samarth Shaileshkumar Patel
// Seneca Student ID: 143147213
// Seneca email: sspatel74@seneca.ca
// Date of completion: 11/16/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <algorithm>
#include "Utilities.h"
using namespace std;
namespace sdds
{

	static char m_delimiter;

	static size_t findNonWhiteSpace(std::string str, bool reversed = false)
	{
		if (reversed)
		{
			for (size_t i = str.length() - 1; i >= 0; i--)
				if (str[i] != ' ')
					return i;
		}
		for (size_t i = 0; i < str.length(); i++)
			if (str[i] != ' ')
				return i;
		return 0;
	}

	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string &str, size_t &next_pos, bool &more)
	{
		string token{};

		size_t pos = str.find(m_delimiter, next_pos);
		if (pos == next_pos)
		{
			more = false;
			throw "pos = next_pos";
		}
		if (more)
		{
			token = str.substr(next_pos, pos - next_pos);
			token = token.substr(findNonWhiteSpace(token));
			token = token.substr(0, findNonWhiteSpace(token, true) + 1);
			m_widthField = std::max(token.length(), getFieldWidth());
			if (pos != std::string::npos)
			{
				next_pos = pos + 1;
				more = true;
			}
			else
				more = false;
		}

		return token;
	}
	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}
}
