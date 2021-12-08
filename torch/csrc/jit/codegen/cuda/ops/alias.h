#pragma once

#include <torch/csrc/WindowsTorchApiMacro.h>

#include <torch/csrc/jit/codegen/cuda/ir_interface_nodes.h>
#include <torch/csrc/jit/codegen/cuda/type.h>

//
// The operations defined in this header is intended as user facing functions.
// The user will provide the necessary input TensorViews and the function will
// create the correct intermediate nodes and return the output TensorViews.
//

namespace torch {
namespace jit {
namespace fuser {
namespace cuda {

TORCH_CUDA_CU_API TensorView* view(
    TensorView* x,
    const std::vector<int64_t>& original_sizes,
    const std::vector<int64_t>& new_sizes);

TORCH_CUDA_CU_API TensorView* squeeze(
    TensorView* x,
    const std::vector<int64_t>& sizes);

TORCH_CUDA_CU_API TensorView* squeeze(
    TensorView* x,
    const std::vector<int64_t>& sizes,
    int64_t dim);

TORCH_CUDA_CU_API TensorView* unsqueeze(TensorView* x, int64_t dim);

} // namespace cuda
} // namespace fuser
} // namespace jit
} // namespace torch
