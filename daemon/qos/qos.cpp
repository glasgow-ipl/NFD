#include "qos.hpp"

namespace nfd{
namespace qos{
Qos::Qos()
{
  // setup QosTable
  m_qosTable = QosTable();

  Name prioPrefix("/prio");
  QosEntry entry = QosEntry(prioPrefix, 0b101110);
  m_qosTable.push(entry);
}

void
Qos::markPacket(ndn::PacketBase& pkt, const Name& name){
  uint16_t fb_code = BOOST_BINARY( 10111000 );
  //lookup
  fb_code = m_qosTable.match_and_fetch(name);
  //mark
  pkt.setFbField(fb_code);
}
}}
