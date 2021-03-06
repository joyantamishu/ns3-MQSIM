#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <unordered_map>
#include <queue>
#include "ns3/Sim_Defs.h"
#include "ns3/EventTree.h"
#include "ns3/Sim_Object.h"
#include "ns3/SimInterface.h"
namespace ns3
{
namespace MQSimEngine {
	class Engine
	{
		friend class EventTree;
	public:
		Engine()
		{
			this->_EventList = new EventTree;
			started = false;
		}

		~Engine() {
			delete _EventList;
		}
		
		std::queue<SimInterfaceRequest*> queued_requests;


		//added for interfacing
		static Engine* Instance();
		sim_time_type Time();
		Sim_Event* Register_sim_event(sim_time_type fireTime, Sim_Object* targetObject, void* parameters = NULL, int type = 0);
		void Ignore_sim_event(Sim_Event*);
		void Reset();
		void AddObject(Sim_Object* obj);
		Sim_Object* GetObject(sim_object_id_type object_id);
		void RemoveObject(Sim_Object* obj);
		void Start_simulation();
		void Stop_simulation();
		bool Has_started();
		bool Is_integrated_execution_mode();
		sim_time_type _sim_time;

//		static void invoke_event(Sim_Object*, Sim_Event * );
	private:

		EventTree* _EventList;
		std::unordered_map<sim_object_id_type, Sim_Object*> _ObjectList;
		bool stop;
		bool started;
		static Engine* _instance;
	};
}
}

#define MQsim_Simulator MQSimEngine::Engine::Instance()
#endif // !ENGINE_H
