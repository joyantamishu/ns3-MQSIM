#ifndef EXECUTION_PARAMETER_SET_H
#define EXECUTION_PARAMETER_SET_H

#include <vector>
#include "ns3/Parameter_Set_Base.h"
#include "ns3/Device_Parameter_Set.h"
#include "ns3/IO_Flow_Parameter_Set.h"
#include "ns3/Host_Parameter_Set.h"
namespace ns3
{
	class Execution_Parameter_Set : public Parameter_Set_Base
	{
	public:
		static Host_Parameter_Set Host_Configuration;
		static Device_Parameter_Set SSD_Device_Configuration;

		void XML_serialize(Utils::XmlWriter& xmlwriter);
		void XML_deserialize(rapidxml::xml_node<> *node);
	};
}

#endif // !EXECUTION_PARAMETER_SET_H
