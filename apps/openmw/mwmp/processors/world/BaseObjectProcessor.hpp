//
// Created by koncord on 18.04.17.
//

#ifndef OPENMW_BASEOBJECTPROCESSOR_HPP
#define OPENMW_BASEOBJECTPROCESSOR_HPP

#include "apps/openmw/mwmp/WorldProcessor.hpp"
#include "apps/openmw/mwmp/Main.hpp"
#include "apps/openmw/mwmp/WorldController.hpp"
#include "apps/openmw/mwworld/cellstore.hpp"

namespace mwmp
{
    class BaseObjectProcessor : public WorldProcessor
    {
    public:
        virtual void Do(WorldPacket &packet, WorldEvent &event)
        {
            MWWorld::CellStore *ptrCellStore = Main::get().getWorldController()->getCell(event.cell);

            if (!ptrCellStore) return;

            LOG_MESSAGE_SIMPLE(Log::LOG_VERBOSE, "Received %s about %s", strPacketID.c_str(), event.cell.getDescription().c_str());
        }
    protected:
        MWWorld::CellStore *ptrCellStore;

    };
}

#endif //OPENMW_BASEOBJECTPROCESSOR_HPP
