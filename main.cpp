// em++ main.cpp -o main_bigint.html -g -sWASM_BIGINT=1
// or
// em++ main.cpp -o main_wasm64.html -g -sMEMORY64=1

#include <cstdint>
#include <cstdio>

#include <emscripten.h>

EM_JS(int64_t, my_async_i64, (), {
  return Asyncify.handleAsync(async () => {
    return 123n; // bigint
  });
});

EM_JS(uint64_t, my_async_u64, (), {
  return Asyncify.handleAsync(async () => {
    return 123n; // bigint
  });
});

int main() {
    int64_t i = my_async_i64();
    uint64_t u = my_async_u64();
}
