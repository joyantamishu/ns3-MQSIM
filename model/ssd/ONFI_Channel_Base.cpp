#include "ns3/ONFI_Channel_Base.h"
using namespace ns3;
namespace ns3{
namespace SSD_Components
{
	ONFI_Channel_Base::ONFI_Channel_Base(flash_channel_ID_type channelID, unsigned int chipCount, NVM::FlashMemory::Flash_Chip** flashChips, ONFI_Protocol type)
		: ChannelID(channelID), status(BusChannelStatus::IDLE), Chips(flashChips), Type(type)
	{
	}
}

}
