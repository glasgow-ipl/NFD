#ifndef NFD_DAEMON_QOS
#define NFD_DAEMON_QOS

#include "qos-entry.hpp"
#include "table/qos_table.hpp"
#include "ndn-cxx/detail/packet-base.hpp"

namespace nfd {
namespace qos {

  class Qos : noncopyable
  {
  public:
    explicit
    Qos();

  public:

    void
    markPacket(ndn::PacketBase& pkt, Name& name);

    QosTable m_qosTable;

  };

}
}

#endif //NFD_DAEMON_QOS
