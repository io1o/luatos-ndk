SUBDIRS := 	src
#vpath %.c src
#vpath %.h inc
TARGET := user.lib
SRCS :=	$(wildcard *.c)

ifneq ($(MAKECMDGOALS),clean)
ifeq ($(LR),)
$(error please give ar command name)
endif
endif

LRFLAG := -r

OUT_DIR := out out/include out/obj out/lib 

out/lib/$(TARGET): subdirs
	$(LR) $(LRFLAG) $(subst /,\,$(wildcard out/obj/*.o))   -o $(subst /,\,$@) 

.PHONY: subdirs $(SUBDIRS) $(OUT_DIR) clean clean-subdirs

subdirs: $(SUBDIRS)

$(OUT_DIR):
	-mkdir $(subst /,\,$@)

$(SUBDIRS): | $(OUT_DIR)
	@$(MAKE) -C $@ all

clean: clean-subdirs
	@del /f /s /q out 1>nul
	@rmdir /s /q out

clean-subdirs:
	@for /D %%G in ($(SUBDIRS)) do $(MAKE) -C %%G clean

export BUILD_ROOT := $(dir $(realpath $(MAKEFILE_LIST))).


OUT_ROOT := $(BUILD_ROOT)/$(OUT_DIR)

export OUT_INCLUDE := $(BUILD_ROOT)/out/include

export OUT_OBJ := $(BUILD_ROOT)/out/obj

BASE_INC_PATHS += 	$(NDK_ROOT)/platform/Air72x/core
BASE_INC_PATHS += 	$(NDK_ROOT)/platform/Air72x/core/trans_api
$(info $(BASE_INC_PATHS) )

export BASE_INC_PATHS

# override DFLAG

# export DFLAG
$(info $(BUILD_ROOT) )

export MAKE_INCLUDE := $(NDK_ROOT)/env/make.mk
