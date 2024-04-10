#ifndef NFD_DAEMON_TABLE_QOS_TABLE
#define NFD_DAEMON_TABLE_QOS_TABLE

#include <vector>

#include "daemon/qos/qos-entry.hpp"

namespace nfd {
namespace qos {
  class QosTable 
  {
  public:
    explicit
    QosTable();

  public:
    void
    push(const QosEntry entry);

    bool 
    erase(QosEntry& entry);

    uint16_t
    match_and_fetch(const ndn::Name& name);


    std::vector<QosEntry> m_policy_vector;

  private:
    QosEntry
    const get(const Name& name);

  };
}
}

#endif // NFD_DAEMON_TABLE_QOS_TABLE
