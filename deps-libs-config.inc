_ROOT_DIR := $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))

#detect cxx version
$(shell $(CXX) -v 2> ./__tmp_makefile_cxx_version)
_CXX_VERSION := $(shell cat ./__tmp_makefile_cxx_version | grep -i 'gcc version' | awk '{print $$3}')
$(shell rm -f ./__tmp_makefile_cxx_version)

_DEPS_INC := 
_DEPS_LIB := 

_LIB_BOTAN_VER			:= 2.18.0
_LIB_BOTAN_PATH 			:= $(_ROOT_DIR)/botan_build/$(_LIB_BOTAN_VER)/gcc/$(_CXX_VERSION)/$(PRJ_ARCH)/release
_LIB_BOTAN_INC_PATH 		:= $(_LIB_BOTAN_PATH)/include/botan-2
_LIB_BOTAN_LIB_PATH			:= $(_LIB_BOTAN_PATH)/lib/libbotan-2.a

_DEPS_INC 		+= $(_LIB_BOTAN_INC_PATH)
_DEPS_LIB 		+= $(_LIB_BOTAN_LIB_PATH)