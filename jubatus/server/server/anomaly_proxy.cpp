// This file is auto-generated from anomaly.idl(1.0.6-6-g2cf96c3) with jenerator version 0.9.4-42-g70f7539/develop
// *** DO NOT EDIT ***

#include <map>
#include <string>
#include <vector>
#include <utility>

#include "jubatus/core/common/exception.hpp"
#include "../../server/common/logger/logger.hpp"
#include "../../server/framework/aggregators.hpp"
#include "../../server/framework/proxy.hpp"
#include "anomaly_types.hpp"

namespace jubatus {

int run_proxy(int argc, char* argv[]) {
  try {
    jubatus::server::framework::proxy k(
        jubatus::server::framework::proxy_argv(argc, argv, "anomaly"));
    k.register_async_cht<2, bool>("clear_row",
        jubatus::util::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
    k.register_async_random<id_with_score, jubatus::core::fv_converter::datum>(
        "add");
    k.register_async_random<std::vector<std::string>,
        std::vector<jubatus::core::fv_converter::datum> >("add_bulk");
    k.register_async_cht<2, double, jubatus::core::fv_converter::datum>(
        "update", jubatus::util::lang::function<double(double, double)>(
        &jubatus::server::framework::pass<double>));
    k.register_async_cht<2, double, jubatus::core::fv_converter::datum>(
        "overwrite", jubatus::util::lang::function<double(double, double)>(
        &jubatus::server::framework::pass<double>));
    k.register_async_broadcast<bool>("clear",
        jubatus::util::lang::function<bool(bool, bool)>(
        &jubatus::server::framework::all_and));
    k.register_async_random<double, jubatus::core::fv_converter::datum>(
        "calc_score");
    k.register_async_random<std::vector<std::string> >("get_all_rows");
    return k.run();
  } catch (const jubatus::core::common::exception::jubatus_exception& e) {
    LOG(FATAL) << "exception in proxy main thread: "
               << e.diagnostic_information(true);
    return -1;
  }
}

}  // namespace jubatus

int main(int argc, char* argv[]) {
  return jubatus::run_proxy(argc, argv);
}
