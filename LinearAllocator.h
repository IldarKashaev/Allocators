/*
 * Copyright Ildar Kashaev
 */

#include <cstddef>

namespace allocs {

class LinearAllocator {
 public:
  explicit LinearAllocator(std::size_t size);
  ~LinearAllocator();
  void* allocate(std::size_t size) noexcept;
  void deallocate() noexcept;

 private:
  std::size_t memory_size_ = 0;
  std::size_t memory_offset_ = 0;
  void* base_ = nullptr;
};

}  // allocs
