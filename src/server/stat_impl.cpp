// this program is automatically generated by jenerator. do not edit.
#include "../framework.hpp"
#include "stat_server.hpp"
#include "stat_serv.hpp"
using namespace jubatus;
using namespace jubatus::framework;
namespace jubatus { namespace server {
class stat_impl_ : public stat<stat_impl_>
{
public:
  stat_impl_(const server_argv& a):
    stat<stat_impl_>(a.timeout),
    p_(new stat_serv(a))
  { p_->use_cht();}

  bool set_config(std::string name, config_data c) //update broadcast
  { JWLOCK__(p_); return p_->set_config(c); }

  config_data get_config(std::string name) //analysis random
  { JRLOCK__(p_); return p_->get_config(); }

  bool push(std::string arg0, std::string key, double v) //update cht(2)
  { JWLOCK__(p_); return p_->push(key, v); }

  double sum(std::string arg0, std::string key) //analysis cht(2)
  { JRLOCK__(p_); return p_->sum(key); }

  double stddev(std::string arg0, std::string key) //analysis cht(2)
  { JRLOCK__(p_); return p_->stddev(key); }

  double max(std::string arg0, std::string key) //analysis cht(2)
  { JRLOCK__(p_); return p_->max(key); }

  double min(std::string arg0, std::string key) //analysis cht(2)
  { JRLOCK__(p_); return p_->min(key); }

  double entropy(std::string arg0, std::string key) //analysis cht(2)
  { JRLOCK__(p_); return p_->entropy(key); }

  double moment(std::string arg0, std::string key, int n, double c) //analysis cht(2)
  { JRLOCK__(p_); return p_->moment(key, n, c); }

  bool save(std::string name, std::string id) //update broadcast
  { JWLOCK__(p_); return p_->save(id); }

  bool load(std::string name, std::string id) //update broadcast
  { JWLOCK__(p_); return p_->load(id); }

  std::map<std::string,std::map<std::string,std::string > > get_status(std::string name) //analysis broadcast
  { JRLOCK__(p_); return p_->get_status(); }
  int run(){ return p_->start(*this); };
  pfi::lang::shared_ptr<stat_serv> get_p(){ return p_; };
private:
  pfi::lang::shared_ptr<stat_serv> p_;
};
}} // namespace jubatus::server
int main(int args, char** argv){
  return
    jubatus::framework::run_server<jubatus::server::stat_impl_,
                                   jubatus::server::stat_serv>
       (args, argv);
}
