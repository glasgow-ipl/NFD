#include <optional>
#include "qos-entry.hpp"

namespace nfd{
namespace qos{

    QosEntry::QosEntry(ndn::Name prefix, uint16_t fb_field)
        :   m_prefix (prefix),
            m_fb_field (fb_field)
    {}

    QosEntry::QosEntry(const QosEntry& entry)
	:   m_prefix(entry.m_prefix),
	    m_fb_field(entry.m_fb_field)
    {}

    QosEntry::QosEntry()
    :   m_prefix(Name("*")),
        m_fb_field(BOOST_BINARY( 10111000 ))
    {}

    QosEntry::~QosEntry(){}

    Name QosEntry::getPrefix(){
      return m_prefix;
    }

    uint16_t QosEntry::getFbField(){
      return m_fb_field;
    }

    bool QosEntry::prefixMatch(const Name& name){
      return m_prefix.isPrefixOf(name);
    }

    bool QosEntry::match(const Name& name){
      return m_prefix.equals(name);
    }
}
}
