PROJ_DIR:=$(shell pwd)
ROOT_DIR:=$(shell dirname "$(PROJ_DIR)")
SCONS=../tools/scons/bin/scons
CPPLINT_TOOL=../tools/cpplint/bin/cpplint
CPPCHECK_TOOL=../tools/cppcheck/bin/cppcheck

all: build
#all: LINK_HEADER_DIR

build: BOOTSTRAP LINK_HEADER_DIR LINK_LIB_DIR BUILD_APP_WITH_SCONS

test: cpplint_test cppcheck_test

cpplint_test:

cppcheck_test:


BUILD_APP_WITH_SCONS:
	cd "$(PROJ_DIR)" && $(SCONS)

LINK_HEADER_DIR:
	for i in "$(ROOT_DIR)"/lib/install/*/include/*; do  	\
		base_name=`basename "$$i"`;							\
		if [ $$base_name == 'google' ]; then				\
			target_dir=src/$$base_name;						\
			if [ ! -e $$target_dir ]; then					\
				mkdir -p $$target_dir;						\
			fi;												\
			for j in "$$i"/*; do 							\
				target=$$target_dir/`basename "$$j"`;		\
				if [ -e "$$target" ]; then					\
					unlink "$$target";						\
				fi; 										\
				ln -s "$$j" "$$target";						\
			done;											\
		else												\
			target="src/$$base_name"; 						\
			if [ -e "$$target" ]; then						\
				unlink "$$target";							\
			fi; 											\
			ln -s "$$i" "$$target";							\
		fi;													\
	done;

LINK_LIB_DIR:
	source="$(ROOT_DIR)/lib/install"; 	\
	target="$(PROJ_DIR)/lib"; 			\
	if [ -e "$$target" ]; then 			\
			echo "$$target exists...!"; \
			unlink "$$target";			\
	fi; 								\
	ln -s "$$source" "$$target"; 		\
	echo "$$source linked as $$target" 	\

BOOTSTRAP:
	cd "$(ROOT_DIR)" && make -f Makefile.BOOTSTRAP
		
.PHONY: clean

clean:
	$(SCONS) --clean
	rm -Rf build/*