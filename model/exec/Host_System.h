#ifndef HOST_SYSTEM_H
#define HOST_SYSTEM_H

#include <vector>
#include "ns3/Sim_Object.h"
#include "ns3/Sim_Reporter.h"
#include "ns3/PCIe_Root_Complex.h"
#include "ns3/PCIe_Link.h"
#include "ns3/PCIe_Switch.h"
#include "ns3/PCIe_Message.h"
#include "ns3/IO_Flow_Base.h"
#include "ns3/Host_IO_Request.h"
#include "ns3/Host_Interface_Base.h"
#include "ns3/Host_Parameter_Set.h"
#include "ns3/SSD_Device.h"
#include "ns3/Workload_Statistics.h"

namespace ns3
{

	class Host_System : public MQSimEngine::Sim_Object, public MQSimEngine::Sim_Reporter
	{
	public:
		Host_System(Host_Parameter_Set* parameters, bool preconditioning_required, SSD_Components::Host_Interface_Base* ssd_host_interface);
		~Host_System();
		void Start_simulation();
		void Validate_simulation_config();
		void Execute_MQsim_Simulator_event(MQSimEngine::Sim_Event* event);
		void Report_results_in_XML(std::string name_prefix, Utils::XmlWriter& xmlwriter);

		void Attach_ssd_device(SSD_Device* ssd_device);
		const std::vector<Host_Components::IO_Flow_Base*> Get_io_flows();
	private:
		Host_Components::PCIe_Root_Complex* PCIe_root_complex;
		Host_Components::PCIe_Link* Link;
		Host_Components::PCIe_Switch* PCIe_switch;
		Host_Components::SATA_HBA* SATA_hba;
		std::vector<Host_Components::IO_Flow_Base*> IO_flows;
		SSD_Device* ssd_device;
		std::vector<Utils::Workload_Statistics*> get_workloads_statistics();
		bool preconditioning_required;
	};
}

#endif // !HOST_SYSTEM_H
