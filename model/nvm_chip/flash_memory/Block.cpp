#include "ns3/Block.h"
using namespace ns3;
namespace ns3{
namespace NVM
{
	namespace FlashMemory
	{
		Block::Block(unsigned int PagesNoPerBlock, flash_block_ID_type BlockID)
		{
			ID = BlockID;
			Pages = new Page[PagesNoPerBlock];
		}

		Block::~Block()
		{
		delete[] Pages;
		}
	}
}
}
