// this program is automatically generated by jenerator. do not edit.
#include "../framework.hpp"
#include "graph_server.hpp"
#include "graph_serv.hpp"
using namespace jubatus;
using namespace jubatus::framework;
namespace jubatus { namespace server {
class graph_impl_ : public graph<graph_impl_>
{
public:
  graph_impl_(const server_argv& a):
    graph<graph_impl_>(a.timeout),
    p_(graph_serv(a))
  { p_->use_cht();}

  int create_node(std::string name, std::string nid) //update cht
  { JWLOCK__(p_); return p_->create_node(nid); }

   int create_global_node(std::string name, std::string nid) //update broadcast
  { JWLOCK__(p_); return p_->create_global_node(nid); }

  int remove_global_node(std::string name, std::string nid) //update broadcast
  { JWLOCK__(p_); return p_->remove_global_node(nid); }

  int update_node(std::string name, std::string nid, property p) //update cht
  { JWLOCK__(p_); return p_->update_node(nid, p); }

  int remove_node(std::string name, std::string nid) //update cht
  { JWLOCK__(p_); return p_->remove_node(nid); }

  int create_edge(std::string name, std::string nid, edge_req r) //update cht
  { JWLOCK__(p_); return p_->create_edge(nid, r); }

  int update_edge(std::string name, std::string nid, edge_req r) //update cht
  { JWLOCK__(p_); return p_->update_edge(nid, r); }

  int remove_edge(std::string name, std::string nid, edge_id_t e) //update cht
  { JWLOCK__(p_); return p_->remove_edge(nid, e); }

  double centrality(std::string name, std::string nid, centrality_type ct) //analysis random
  { JRLOCK__(p_); return p_->centrality(nid, ct); }

  std::vector<node_id > shortest_path(std::string name, shortest_path_req r) //analysis random
  { JRLOCK__(p_); return p_->shortest_path(r); }

  int update_index(std::string name) //update broadcast
  { JWLOCK__(p_); return p_->update_index(); }

  int clear(std::string name) //update broadcast
  { JWLOCK__(p_); return p_->clear(); }

  node_info get_node(std::string name, std::string nid) //analysis cht
  { JRLOCK__(p_); return p_->get_node(nid); }

  edge_info get_edge(std::string name, std::string nid, edge_id_t e) //analysis cht
  { JRLOCK__(p_); return p_->get_edge(nid, e); }

  bool save(std::string name, std::string arg1) //update broadcast
  { JWLOCK__(p_); return p_->save(arg1); }

  bool load(std::string name, std::string arg1) //update broadcast
  { JWLOCK__(p_); return p_->load(arg1); }

  std::map<std::string,std::map<std::string,std::string > > get_status(std::string name) //analysis broadcast
  { JRLOCK__(p_); return p_->get_status(); }

  int run(){ return p_->start(*this); };
  pfi::lang::shared_ptr<graph_serv> get_p(){ return p_; };
private:
  pfi::lang::shared_ptr<graph_serv> p_;
};
}} // namespace jubatus::server
int main(int args, char** argv){
  return
    jubatus::framework::run_server<jubatus::server::graph_impl_,
                                   jubatus::server::graph_serv>
       (args, argv);
}
