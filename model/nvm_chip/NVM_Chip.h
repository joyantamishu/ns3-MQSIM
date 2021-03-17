#ifndef NVM_CHIP_H
#define NVM_CHIP_H

#include "ns3/Sim_Object.h"
#include "ns3/NVM_Memory_Address.h"
namespace ns3{
namespace NVM
{
	class NVM_Chip : public MQSimEngine::Sim_Object
	{
	public:
		NVM_Chip(const sim_object_id_type& id) : Sim_Object(id) {}
		virtual void Change_memory_status_preconditioning(const NVM_Memory_Address* address, const void* status_info) = 0;
	};
}
}

#endif // !NVM_CHIP_H
