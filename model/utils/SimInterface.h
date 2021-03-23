/*
 * SimInterface.h
 *
 *  Created on: Mar 23, 2021
 *      Author: joyanta
 */

#ifndef SRC_MQSIM_MODEL_UTILS_SIMINTERFACE_H_
#define SRC_MQSIM_MODEL_UTILS_SIMINTERFACE_H_


#include <cstdint>
#include "ns3/core-module.h"
//#include "ns3/Execution_Parameter_Set.h"
namespace ns3{
enum class Request_Type { READ, WRITE };
class SimInterfaceRequest
{
	std::size_t flow_id;
	Time Arrival_time;
	uint64_t Start_LBA;
	unsigned int LBA_count;
	Request_Type Type;
public:
	SimInterfaceRequest(std::size_t index, Time t, uint64_t LBA, unsigned int size, Request_Type RW)
	{
		flow_id = index;
		Arrival_time = t;
		Start_LBA = LBA;
		LBA_count = size;
		Type = RW;
	}
};



}


#endif /* SRC_MQSIM_MODEL_UTILS_SIMINTERFACE_H_ */
