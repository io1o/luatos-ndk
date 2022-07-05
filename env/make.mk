
ifneq ($(MAKECMDGOALS),clean)
ifeq ($(CC),)
$(error please set compiler)
endif

ifeq ($(CCOPTION),)
$(error please set CCOPTION)
endif
endif

INCS += .
HEADERS := $(foreach dir,$(INCS),$(wildcard $(dir)/*.h))
LIBERS := $(foreach dir,$(INCS),$(wildcard $(dir)/*.a))

# compile flags
CCFLAG := $(addprefix -I,$(PACKAGE_INC_PATHS))

OBJCCFLAG := $(CCOPTION) $(CCFLAG) $(DFLAG)

DEPSFLAG := $(OBJCCFLAG) -MM

.PHONY: all
all: $(addprefix $(OUT_OBJ)/,$(SRCS:.c=.o)) $(addprefix $(OUT_LIBA)/,$(LIBERS)) $(addprefix $(OUT_INCLUDE)/,$(HEADERS)) build-subdirs
# recursive make and clean
.PHONY: build-subdirs
build-subdirs: $(DIRS)

.PHONY: $(DIRS)
$(DIRS):
	@$(MAKE) -C $@ all

.PHONY: clean
clean: clean-subdirs
	@del *.d
	@del *.o

.PHONY: clean-subdirs
clean-subdirs:
	@for /D %%G in ($(DIRS)) do $(MAKE) -C %%G clean

$(OUT_OBJ)/%.o: %.o
	@copy $(subst /,\,$<) $(subst /,\,$@)

$(OUT_LIBA)/%.a: %.a
	@copy $(subst /,\,$<) $(subst /,\,$@)

$(OUT_INCLUDE)/%.h: %.h
	@copy $(subst /,\,$<) $(subst /,\,$@)

OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

%.o: %.c
	$(CC) $(OBJCCFLAG) $(subst /,\,$<) -o $(subst /,\,$@)

%.d: %.c
	$(CC) $(DEPSFLAG) $(subst /,\,$<) -o $(subst /,\,$@)


ifneq ($(MAKECMDGOALS),clean)
-include $(DEPS)
endif

export PACKAGE_INC_PATHS