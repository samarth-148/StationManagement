// Name: Samarth Shaileshkumar Patel
// Seneca email: sspatel74@seneca.ca
// Date of completion: 11/16/2022

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include "Workstation.h"

namespace sdds
{
	class LineManager
	{
	private:
		std::vector<Workstation *> m_activeLine;
		size_t m_cntCustomerOrder{};
		Workstation *m_firstStation{};

	public:
		LineManager(const std::string &file, const std::vector<Workstation *> &stations);
		void reorderStations();
		bool run(std::ostream &os);
		void display(std::ostream &os) const;
	};
}

#endif // !LINEMANAGER_H
