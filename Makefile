all:

ARGS := -v -g -sASYNCIFY_IMPORTS=my_async_i32,my_async_u32,my_async_i64,my_async_u64

all: main_asyncify_bigint.html
main_asyncify_bigint.html: main.cpp Makefile
	em++ main.cpp -o $@ ${ARGS} -sASYNCIFY=1 -sWASM_BIGINT=1
all: main_asyncify_wasm64.html
main_asyncify_wasm64.html: main.cpp Makefile
	em++ main.cpp -o $@ ${ARGS} -sASYNCIFY=1 -sMEMORY64=1
all: main_jspi_bigint.html
main_jspi_bigint.html: main.cpp Makefile
	em++ main.cpp -o $@ ${ARGS} -sJSPI=1 -sWASM_BIGINT=1
all: main_jspi_wasm64.html
main_jspi_wasm64.html: main.cpp Makefile
	em++ main.cpp -o $@ ${ARGS} -sJSPI=1 -sMEMORY64=1
