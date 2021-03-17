#ifndef MQsim_Simulator_EVENT_H
#define MQsim_Simulator_EVENT_H

#include "ns3/Sim_Defs.h"
#include "ns3/Sim_Object.h"

namespace ns3
{
	namespace MQSimEngine
	{
		class Sim_Object;
		class Sim_Event
		{
		public:
			Sim_Event(sim_time_type fireTime, Sim_Object* targetObject, void* parameters = NULL, int type = 0)
				: Fire_time(fireTime), Target_sim_object(targetObject), Parameters(parameters), Type(type), Next_event(NULL), Ignore(false) {}
			sim_time_type Fire_time;
			Sim_Object* Target_sim_object;
			void* Parameters = NULL;
			int Type;
			Sim_Event* Next_event;//Used to store event list in the MQSim's engine
			bool Ignore;//If true, this event will not be executed
		};
	}
}
#endif // !MQsim_Simulator_EVENT_H
