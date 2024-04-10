#ifndef NFD_DAEMON_QOS_ENTRY
#define NFD_DAEMON_QOS_ENTRY

#include "core/common.hpp"

namespace nfd {
namespace qos {

class QosEntry{
  public:
    QosEntry(ndn::Name prefix, uint16_t fb_field);
    QosEntry(const QosEntry& entry);
    QosEntry();
    virtual
    ~QosEntry();

  public:
    Name getPrefix();

    uint16_t getFbField();

    bool prefixMatch(const Name& name);

    bool match(const Name& name);

  private:
  Name m_prefix;
  uint16_t m_fb_field;

};

}
}

#endif // NFD_DAEMON_QOS_ENTRY
