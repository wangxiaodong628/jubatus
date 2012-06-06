// this program is automatically generated by jenerator. do not edit.
#include "../framework.hpp"
#include "recommender_server.hpp"
#include "recommender_serv.hpp"
using namespace jubatus;
using namespace jubatus::framework;
namespace jubatus { namespace server {
class recommender_impl_ : public recommender<recommender_impl_>
{
public:
  recommender_impl_(const server_argv& a):
    recommender<recommender_impl_>(a.timeout),
    p_(new recommender_serv(a))
  { p_->use_cht();}

  bool set_config(std::string name, config_data c) //update broadcast
  { JWLOCK__(p_); return p_->set_config(c); }

  config_data get_config(std::string name) //analysis random
  { JRLOCK__(p_); return p_->get_config(); }

  bool clear_row(std::string name, std::string id) //update cht(2)
  { JWLOCK__(p_); return p_->clear_row(id); }

  bool update_row(std::string name, std::string id, datum arg2) //update cht(2)
  { JWLOCK__(p_); return p_->update_row(id, arg2); }

  bool clear(std::string name) //update broadcast
  { JWLOCK__(p_); return p_->clear(); }

  datum complete_row_from_id(std::string name, std::string id) //analysis cht(2)
  { JRLOCK__(p_); return p_->complete_row_from_id(id); }

  datum complete_row_from_data(std::string name, datum arg1) //analysis random
  { JRLOCK__(p_); return p_->complete_row_from_data(arg1); }

  similar_result similar_row_from_id(std::string name, std::string id, unsigned int size) //analysis cht(2)
  { JRLOCK__(p_); return p_->similar_row_from_id(id, size); }

  similar_result similar_row_from_data(std::string name, datum data, unsigned int size) //analysis random
  { JRLOCK__(p_); return p_->similar_row_from_data(data, size); }

  datum decode_row(std::string name, std::string id) //analysis cht(2)
  { JRLOCK__(p_); return p_->decode_row(id); }

  std::vector<std::string > get_all_rows(std::string name) //analysis broadcast
  { JRLOCK__(p_); return p_->get_all_rows(); }

  float similarity(std::string name, datum lhs, datum rhs) //analysis random
  { JRLOCK__(p_); return p_->similarity(lhs, rhs); }

  float l2norm(std::string name, datum arg1) //analysis random
  { JRLOCK__(p_); return p_->l2norm(arg1); }

  bool save(std::string name, std::string arg1) //update broadcast
  { JWLOCK__(p_); return p_->save(arg1); }

  bool load(std::string name, std::string arg1) //update broadcast
  { JWLOCK__(p_); return p_->load(arg1); }

  std::map<std::string,std::map<std::string,std::string > > get_status(std::string name) //analysis broadcast
  { JRLOCK__(p_); return p_->get_status(); }
  int run(){ return p_->start(*this); };
  pfi::lang::shared_ptr<recommender_serv> get_p(){ return p_; };
private:
  pfi::lang::shared_ptr<recommender_serv> p_;
};
}} // namespace jubatus::server
int main(int args, char** argv){
  return
    jubatus::framework::run_server<jubatus::server::recommender_impl_,
                                   jubatus::server::recommender_serv>
       (args, argv);
}
