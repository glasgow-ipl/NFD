#include "qos.hpp"

namespace nfd{
namespace qos{
Qos::Qos()
{
  // setup QosTable
  m_qosTable = QosTable();

  Name prioPrefix("/prio");
  QosEntry prioEntry = QosEntry(prioPrefix, BOOST_BINARY(10111000));
  m_qosTable.push(prioEntry);
  Name streaming_A_live_prefix("/streaming_service_A");
  QosEntry streaming_A_live = QosEntry(streaming_A_live_prefix,BOOST_BINARY(10111000));
  m_qosTable.push(streaming_A_live);
}

void
Qos::markPacket(ndn::PacketBase& pkt, const Name& name){
  uint16_t fb_code = BOOST_BINARY( 00000000 ); //default 
  //lookup
  fb_code = m_qosTable.match_and_fetch(name);
  //mark
  pkt.setFbField(fb_code);
}
}}
