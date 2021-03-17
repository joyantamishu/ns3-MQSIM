#ifndef PLANE_H
#define PLANE_H

#include "ns3/NVM_Types.h"
#include "ns3/FlashTypes.h"
#include "ns3/Block.h"
#include "ns3/Flash_Command.h"
namespace ns3{
namespace NVM
{
	namespace FlashMemory
	{
		class Plane
		{
		public:
			Plane(unsigned int BlocksNoPerPlane, unsigned int PagesNoPerBlock);
			~Plane();
			Block** Blocks;
			unsigned int Healthy_block_no;
			unsigned long Read_count;                     //how many read count in the process of workload
			unsigned long Progam_count;
			unsigned long Erase_count;
			stream_id_type* Allocated_streams;
		};
	}
}
}
#endif // !PLANE_H
