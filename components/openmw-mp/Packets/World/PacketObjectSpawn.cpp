#include <components/openmw-mp/NetworkMessages.hpp>
#include "PacketObjectSpawn.hpp"

using namespace mwmp;

PacketObjectSpawn::PacketObjectSpawn(RakNet::RakPeerInterface *peer) : WorldPacket(peer)
{
    packetID = ID_OBJECT_SPAWN;
}

void PacketObjectSpawn::Packet(RakNet::BitStream *bs, bool send)
{
    WorldPacket::Packet(bs, send);

    if (send)
        event->worldObjectCount = (unsigned int)(event->worldObjects.size());
    else
        event->worldObjects.clear();

    RW(event->worldObjectCount, send);

    RW(event->cell.mData.mFlags, send);
    RW(event->cell.mData.mX, send);
    RW(event->cell.mData.mY, send);
    RW(event->cell.mName, send);

    WorldObject worldObject;

    for (unsigned int i = 0; i < event->worldObjectCount; i++)
    {
        if (send)
        {
            worldObject = event->worldObjects.at(i);
        }

        RW(worldObject.refId, send);
        RW(worldObject.refNumIndex, send);
        RW(worldObject.mpNum, send);
        RW(worldObject.position, send);

        RW(worldObject.hasMaster, send);
        
        if (worldObject.hasMaster)
        {
            RW(worldObject.master.refNumIndex, send);
            RW(worldObject.master.mpNum, send);
            RW(worldObject.master.guid, send);
        }

        if (!send)
        {
            event->worldObjects.push_back(worldObject);
        }
    }
}