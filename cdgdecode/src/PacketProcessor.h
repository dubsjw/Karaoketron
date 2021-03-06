#pragma once

// cdgdecode dependencies
#include <cdgdecode/Packet.h>
#include "src/cdgdecode_InstructionValues.h"
#include "src/cdgdecode_BorderPreset.h"
#include "src/cdgdecode_LoadPalette.h"
#include "src/cdgdecode_MemoryPreset.h"
#include "src/cdgdecode_TileBlock.h"
#include "src/cdgdecode_XORTileBlock.h"

// std dependencies
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>

namespace cdgdecode
{

/**
 * The PacketProcessor is a generic way to structure how instructions
 * are handled. 
 */
template <typename EngineType> struct PacketProcessor
{
	//! Reference back to the engine where something is going to be 
	//! done. 
	EngineType& m_engine;

	//! The following is a typedef describing the type of pointer to 
	//! functions being used.
	typedef void (*Processor)(EngineType& engine, Packet const& packet);

	//! The collection of processors, indexed by instruction identifier.
	//! See InstructionValues.h for reference.
	std::vector<Processor> m_processors;

	PacketProcessor(PacketProcessor const&) = delete;
	PacketProcessor& operator=(PacketProcessor const&) = delete;

	/**
	 * Constructor for the packet processor, requires that an engine 
	 * is passed to construction by reference.
	 *
	 * @param engine The engine, this could contain all sorts of stuff
	 *               (pallette, drawing context, etc.).
	 */	
	PacketProcessor(EngineType& engine)
	: m_engine(engine)
	{
		m_processors.resize( MaximumNumberOfCommands
		                   , &PacketProcessor<EngineType>::NullProcessor);

		// Assign all of the known commands.
		m_processors[MemoryPreset] = &HandleMemoryPreset<EngineType>;
		m_processors[BorderPreset] = &HandleBorderPreset<EngineType>;
		m_processors[TileBlock] = &HandleTileBlockPreset<EngineType>;
		m_processors[TileBlockXOR] = &HandleXORTileBlockPreset<EngineType>;
		m_processors[LoadColorTableLow] = HandleLoadLowPalette<EngineType>; 
		m_processors[LoadColorTableHigh] = HandleLoadHighPalette<EngineType>;

	}	


	/**
	 * This method is used to process a single packet. Essentially it figures
	 * out what instruction it is, then calls the appropriate function in 
	 * the container.
	 *
	 * @param packet The packet to process.
	 */
	void operator()(Packet const& packet)
	{
		if (packet.HasCDGEncoding())
		{
			auto instruction = packet.Instruction();
			m_processors[instruction](m_engine, packet);
		}
	}


	/**
	 * Handle any other kind of packet that hasn't been handled.
	 *
	 * @param engine The engine to write or format output to.
	 * @param packet The packet to be processed.
	 */
	static void NullProcessor( EngineType& /*engine*/
	                         , Packet const& packet)
	{
		std::cout << "The instruction " << static_cast<int>(packet.Instruction()) << " was not handled.\n\n"; 
		assert(false && "The command was not implemented");
	}

};

}

