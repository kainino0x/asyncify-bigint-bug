all: main_bigint.html main_wasm64.html

ARGS := -g -sASYNCIFY=1 -sASYNCIFY_IMPORTS=my_async_i64,my_async_u64
main_bigint.html: main.cpp Makefile
	em++ main.cpp -o main_bigint.html ${ARGS} -sWASM_BIGINT=1

main_wasm64.html: main.cpp Makefile
	em++ main.cpp -o main_wasm64.html ${ARGS} -sMEMORY64=1
