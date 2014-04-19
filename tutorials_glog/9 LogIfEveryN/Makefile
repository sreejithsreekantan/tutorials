PROJ_DIR:="."
ROOT_DIR:="../"
SCONS=../tools/scons/bin/scons

all: BOOTSTRAP LINK_HEADER_DIR LINK_LIB_DIR BUILD_APP_WITH_SCONS
#all: LINK_HEADER_DIR

BUILD_APP_WITH_SCONS:
	cd "$(PROJ_DIR)" && $(SCONS)

LINK_HEADER_DIR:
	@for i in $(ROOT_DIR)/lib/install/*/include/*; do  \
		target="src/"`basename "$$i"`; \
		if [ -e $$target ]; then \
			unlink $$target;	\
		fi; \
		ln -sf "$$i" $$target; \
	done;

LINK_LIB_DIR:
	source=$(ROOT_DIR)/lib/install; \
	target=$(PROJ_DIR)/lib; \
	if [ -e "$$target" ]; then \
			unlink "$$target";	\
	fi; \
	ln -sf "$$source" "$$target"; 

BOOTSTRAP:
	cd $(ROOT_DIR) && make -f Makefile.BOOTSTRAP
		
.PHONY: clean

clean:
	$(SCONS) --clean
	rm -Rf build/*