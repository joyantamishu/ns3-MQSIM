#ifndef DIE_H
#define DIE_H

#include "ns3/Sim_Event.h"
#include "ns3/FlashTypes.h"
#include "ns3/Plane.h"
//using namespace ns3;
namespace ns3{
namespace NVM
{
	namespace FlashMemory
	{
		enum class DieStatus { BUSY, IDLE };
		class Die
		{
		public:
			Die(unsigned int PlanesNoPerDie, unsigned int BlocksNoPerPlane, unsigned int PagesNoPerBlock);
			~Die();
			Plane** Planes;
			unsigned int Plane_no;
			DieStatus Status;
			MQSimEngine::Sim_Event* CommandFinishEvent;
			sim_time_type Expected_finish_time;
			sim_time_type RemainingSuspendedExecTime;//used to support suspend command
			Flash_Command* CurrentCMD, *SuspendedCMD;
			bool Suspended;

			sim_time_type STAT_TotalProgramTime, STAT_TotalReadTime, STAT_TotalEraseTime, STAT_TotalXferTime;
		};
	}
}
}
#endif // !DIE_H
