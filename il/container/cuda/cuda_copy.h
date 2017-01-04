//==============================================================================
//
//                                  InsideLoop
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.txt for details.
//
//==============================================================================

#ifndef IL_CUDA_COPY_H
#define IL_CUDA_COPY_H

#include <il/Array.h>
#include <il/Array2D.h>
#include <il/SparseMatrixCSR.h>
#include <il/container/cuda/1d/CudaArray.h>
#include <il/container/cuda/2d/CudaArray2D.h>
#include <il/container/cuda/2d/CudaSparseMatrixCSR.h>

namespace il {

template <typename B, typename A>
class Copy {};

template <typename B, typename A>
B copy(const A& src) {
  return Copy<B, A>::copy(src);
};

template <typename T>
class Copy<il::CudaArray<T>, il::Array<T>> {
 public:
  static il::CudaArray<T> copy(const il::Array<T>& src) {
    il::CudaArray<T> dest{src.size()};
    cudaError_t error =
        cudaMemcpy(dest.data(), src.data(), src.size() * sizeof(T),
                   cudaMemcpyHostToDevice);
    IL_ASSERT(error == 0);
    return dest;
  }
};

template <typename T>
class Copy<il::Array<T>, il::CudaArray<T>> {
 public:
  static il::Array<T> copy(const il::CudaArray<T>& src) {
    il::Array<T> dest{src.size()};
    cudaError_t error =
        cudaMemcpy(dest.data(), src.data(), src.size() * sizeof(T),
                   cudaMemcpyDeviceToHost);
    IL_ASSERT(error == 0);
    return dest;
  }
};

template <typename T>
class Copy<il::CudaArray2D<T>, il::Array2D<T>> {
 public:
  static il::CudaArray2D<T> copy(const il::Array2D<T>& src) {
    il::CudaArray2D<T> dest{src.size(0), src.size(1)};
    cudaError_t error = cudaMemcpy(dest.data(), src.data(),
                                   src.size(0) * src.size(1) * sizeof(T),
                                   cudaMemcpyHostToDevice);
    IL_ASSERT(error == 0);
    return dest;
  }
};

template <typename T>
class Copy<il::Array2D<T>, il::CudaArray2D<T>> {
 public:
  static il::Array2D<T> copy(const il::CudaArray2D<T>& src) {
    il::Array2D<T> dest{src.size(0), src.size(1)};
    cudaError_t error = cudaMemcpy(dest.data(), src.data(),
                                   src.size(0) * src.size(1) * sizeof(T),
                                   cudaMemcpyDeviceToHost);
    IL_ASSERT(error == 0);
    return dest;
  }
};

template <typename T>
class Copy<il::CudaSparseMatrixCSR<T>, il::SparseMatrixCSR<int, T>> {
 public:
  static il::CudaSparseMatrixCSR<T> copy(
      const il::SparseMatrixCSR<int, T>& src) {
    il::CudaArray<int> row{src.size(0) + 1};
    il::CudaArray<int> column{src.nb_nonzeros()};
    il::CudaArray<T> element{src.nb_nonzeros()};
    cudaError_t error;
    error = cudaMemcpy(row.data(), src.row_data(),
                       (src.size(0) + 1) * sizeof(int), cudaMemcpyHostToDevice);
    IL_ASSERT(error == 0);
    error = cudaMemcpy(column.data(), src.column_data(),
                       src.nb_nonzeros() * sizeof(int), cudaMemcpyHostToDevice);
    IL_ASSERT(error == 0);
    error = cudaMemcpy(element.data(), src.element_data(),
                       src.nb_nonzeros() * sizeof(T), cudaMemcpyHostToDevice);
    IL_ASSERT(error == 0);

    return il::CudaSparseMatrixCSR<T>{src.size(0), src.size(1), std::move(row),
                                      std::move(column), std::move(element)};
  }
};
}

#endif  // IL_CUDA_COPY_H
