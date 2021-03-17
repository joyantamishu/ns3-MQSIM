#ifndef PCIE_ROOT_COMPLEX_H
#define PCIE_ROOT_COMPLEX_H

#include "ns3/Host_Interface_Defs.h"
#include "ns3/Host_Defs.h"
#include "ns3/PCIe_Message.h"
#include "ns3/PCIe_Link.h"
#include "ns3/Host_IO_Request.h"
#include "ns3/IO_Flow_Base.h"
#include "ns3/SATA_HBA.h"

namespace ns3{
namespace Host_Components
{
	class PCIe_Link;
	class IO_Flow_Base;
	class SATA_HBA;
	class PCIe_Root_Complex
	{
	public:
		PCIe_Root_Complex(PCIe_Link* pcie_link, HostInterface_Types SSD_device_type, SATA_HBA* sata_hba, std::vector<Host_Components::IO_Flow_Base*>* IO_flows);
		
		void Consume_pcie_message(PCIe_Message* messages)//Modern processors support DDIO, where all writes to memory are going through LLC
		{
			switch (messages->Type)
			{
			case PCIe_Message_Type::READ_REQ:
				Read_from_memory(messages->Address, (unsigned int)(intptr_t)messages->Payload);
				break;
			case PCIe_Message_Type::WRITE_REQ:
				Write_to_memory(messages->Address, messages->Payload);
				break;
			default:
				break;
			}
			delete messages;
		}
		
		void Write_to_device(uint64_t address, uint16_t write_value);
		void Set_io_flows(std::vector<Host_Components::IO_Flow_Base*>* IO_flows);
	private:
		PCIe_Link* pcie_link;
		HostInterface_Types SSD_device_type;
		SATA_HBA * sata_hba;
		std::vector<Host_Components::IO_Flow_Base*>* IO_flows;
		
		void Write_to_memory(const uint64_t address, const void* payload);
		void Read_from_memory(const uint64_t address, const unsigned int size);
	};
}
}

#endif //!PCIE_ROOT_COMPLEX_H



