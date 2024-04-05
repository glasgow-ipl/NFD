#include "qos.hpp"

namespace nfd{
namespace qos{
Qos::Qos(){
  // setup QosTable
  QosTable m_qosTable = QosTable();
}

void
Qos::markPacket(ndn::PacketBase& pkt, Name& name){
  uint16_t fb_code = 0;
  //lookup
  fb_code = m_qosTable.match_and_fetch(name);
  //mark
  pkt.setFbField(fb_code);
}
}}
