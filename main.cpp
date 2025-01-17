#include <cstdint>
#include <cstdio>

#include <emscripten.h>

EM_JS(int32_t, my_async_i32, (), {
  return Asyncify.handleAsync(async () => {
    return -123;
  });
});

EM_JS(uint32_t, my_async_u32, (), {
  return Asyncify.handleAsync(async () => {
    return -123;
  });
});

EM_JS(int64_t, my_async_i64, (), {
  return Asyncify.handleAsync(async () => {
    return -123n; // bigint
  });
});

EM_JS(uint64_t, my_async_u64, (), {
  return Asyncify.handleAsync(async () => {
    return -123n; // bigint
  });
});

int main() {
    printf("my_async_i32 -> %i\n", my_async_i32());
    printf("my_async_u32 -> %u\n", my_async_u32());
    printf("my_async_i64 -> %lli\n", my_async_i64());
    printf("my_async_u64 -> %llu\n", my_async_u64());
}
