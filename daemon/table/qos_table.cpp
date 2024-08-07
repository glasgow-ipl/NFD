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
  QosTable::get(const Name& name){
    std::vector<QosEntry>::iterator it;
    int index = 0;
    for(it = this->m_policy_vector.begin(); it != this->m_policy_vector.end(); it++,index++) {
      if(it->match(name)){
        return *it;
      }
    }
    QosEntry wildcard = QosEntry("*",BOOST_BINARY( 00000000 ));
    return wildcard;
  }

  uint16_t
  QosTable::match_and_fetch(const Name& name){
    std::vector<QosEntry>::iterator it;
    int index = 0;
    for(it = this->m_policy_vector.begin(); it != this->m_policy_vector.end(); it++,index++) {
      if(it->prefixMatch(name)){
	//std::cout<<name.toUri()<<std::endl;
        return it->getFbField();
      }
    }    
    return BOOST_BINARY( 00000000 ); //CS0 Best Effort (0)
  }
}}
