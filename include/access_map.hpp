#pragma once
#include "tiledbuffer.hpp"
#include "platform.hpp"
#include "context.hpp"
#include <vector>
#include <string>

namespace tiledkernel {
    class AccessMap {
       public:
        AccessMap(size_t loop_depth, size_t access_dims,
                  std::vector<std::vector<int32_t>> access_pattern,
                  std::vector<int32_t> iteration_domain,
                  std::vector<int32_t> offset)
            : loop_depth(loop_depth),
              access_dims(access_dims),
              access_pattern(access_pattern),
              iteration_domain(iteration_domain),
              offset(offset) {}

        std::string map(Platform platform, BufferPtr a, BufferPtr b,
                        ContextPtr ctx);

        size_t loop_depth;
        size_t access_dims;
        // row: access_dims, col: loop_depth
        std::vector<std::vector<int32_t>> access_pattern;
        std::vector<int32_t> iteration_domain;
        std::vector<int32_t> offset;
    };
}  // namespace tiledkernel