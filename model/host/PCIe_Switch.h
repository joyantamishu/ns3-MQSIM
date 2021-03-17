#ifndef PCIE_SWITCH_H
#define PCIE_SWITCH_H

#include "ns3/PCIe_Message.h"
#include "ns3/PCIe_Link.h"
#include "ns3/Host_Interface_Base.h"
using namespace ns3;

namespace ns3{
namespace SSD_Components
{
	class Host_Interface_Base;
}

namespace Host_Components
{
	class PCIe_Link;
	class PCIe_Switch
	{
	public:
		PCIe_Switch(PCIe_Link* pcie_link, SSD_Components::Host_Interface_Base* host_interface);//, SSD_Components::Host_Interface_Base* host_interface
		void Deliver_to_device(PCIe_Message*);
		void Send_to_host(PCIe_Message*);
		void Attach_ssd_device(SSD_Components::Host_Interface_Base* host_interface);
		bool Is_ssd_connected();
	private:
		PCIe_Link* pcie_link;
		SSD_Components::Host_Interface_Base* host_interface;
	};
}
}
#endif //!PCIE_SWITCH_H


