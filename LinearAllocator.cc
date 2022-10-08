/*
 * Copyright Ildar Kashaev
 */

#include "LinearAllocator.h"

#include <stdexcept>
#include <string>

namespace allocs {

LinearAllocator::LinearAllocator(std::size_t size) {
  if (size == 0) throw std::runtime_error("Could not allocate 0 byte.");
  base_ = malloc(size);
  if (!base_)
    throw std::runtime_error("Could not allocate " + std::to_string(size) +
                             " bytes.");
}

LinearAllocator::~LinearAllocator() { free(base_); }

void* LinearAllocator::allocate(std::size_t size) noexcept {
  if (memory_offset_ + size > memory_size_) return nullptr;
  std::size_t allocated_addr =
      reinterpret_cast<std::size_t>(base_) + memory_offset_;
  memory_offset_ += allocated_addr;

  return reinterpret_cast<void*>(allocated_addr);
}

void LinearAllocator::deallocate() noexcept {
  memory_size_ = 0;
  memory_offset_ = 0;
}

}  // namespace allocs
