#include <optional>
#include "qos_table.hpp"

namespace nfd{
namespace qos{
  QosTable::QosTable(){
    m_policy_vector.reserve(1);
  }

  void
  QosTable::push(const QosEntry entry){
    m_policy_vector.push_back(entry);
  }

  bool 
  QosTable::erase(QosEntry& entry){
    std::vector<QosEntry>::iterator it;
    std::vector<QosEntry>::iterator pos;
    Name entry_name = entry.getPrefix();
    int index = 0;
    for(it = m_policy_vector.begin(); it != m_policy_vector.end(); it++,index++) {
      index++;
      QosEntry cur_name = *it;
      if(cur_name.match(entry_name)){
        m_policy_vector.erase(it);
	return true;
      }
    }
    return false;
  }

  const QosEntry
  QosTable::get(Name& name){
    std::vector<QosEntry>::iterator it;
    int index = 0;
    for(it = this->m_policy_vector.begin(); it != this->m_policy_vector.end(); it++,index++) {
      if(it->match(name)){
        return *it;
      }
    }
    QosEntry wildcard = QosEntry("*",0);
    return wildcard;
  }

  uint16_t
  QosTable::match_and_fetch(Name& name){
    std::vector<QosEntry>::iterator it;
    int index = 0;
    for(it = this->m_policy_vector.begin(); it != this->m_policy_vector.end(); it++,index++) {
      if(it->prefixMatch(name)){
        return it->getFbField();
      }
    }    
    return 0;
  }
}}
