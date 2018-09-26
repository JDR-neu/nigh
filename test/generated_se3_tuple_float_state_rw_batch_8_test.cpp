// This test case was automatically generated
// generated_se3_tuple_float_state_rw_batch_8_test.cpp
#include "sampler_lp.hpp"
#include "sampler_so3.hpp"
#include "sampler_cartesian.hpp"
#include <nigh/kdtree_batch.hpp>
#include "test_template.hpp"

TEST(se3_tuple_float_state_rw_batch_8) {
    using namespace unc::robotics::nigh;
    using namespace unc::robotics::nigh::metric;
    using namespace nigh_test;  
    using Metric = Cartesian<SO3, LP<2>>;
    using State = std::tuple<Eigen::Quaternion<float>, Eigen::Matrix<float, 3, 1>>;
    using Space = metric::Space<State, Metric>;
    using Concurrency = Concurrent;
    using Strategy = KDTreeBatch<8>;
    Space space;
#ifdef BUILD_TYPE_VALGRIND
    static constexpr std::size_t N = 5000/10;
    static constexpr std::size_t K = 1;
#else
    static constexpr std::size_t N = 5000;
    static constexpr std::size_t K = 50;
#endif
    runTest<State, Space, Identity, Concurrency, Strategy>(space, N, K);
}