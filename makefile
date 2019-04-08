BUILD_DEBUG = yes
.PHONY: all
all: ; @echo BUILD_DEBUG is $(BUILD_DEBUG)
$(info $(FOO) $(origin FOO))  

