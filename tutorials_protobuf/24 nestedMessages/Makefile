PROJ_DIR:=$(shell pwd)
ROOT_DIR:=$(shell dirname "$(PROJ_DIR)")
SCONS=../tools/scons/bin/scons

all: debug
#all: LINK_HEADER_DIR

# PROTO_GENERATE should be before BUILD_APP_WITH_SCONS_RELEASE
release:	BOOTSTRAP 						\
			LINK_HEADER_DIR 				\
			LINK_LIB_DIR 					\
			PROTO_GENERATE 					\
			BUILD_APP_WITH_SCONS_RELEASE 	
			
# PROTO_GENERATE should be before BUILD_APP_WITH_SCONS_DEBUG
debug: 		BOOTSTRAP 						\
			LINK_HEADER_DIR 				\
			LINK_LIB_DIR 					\
			PROTO_GENERATE 					\
			BUILD_APP_WITH_SCONS_DEBUG

PROTO_GENERATE: 
	"$(PROJ_DIR)"/lib/protobuf/bin/protoc *.proto --cpp_out=src/proto/ -I.

BUILD_APP_WITH_SCONS_DEBUG:
	cd "$(PROJ_DIR)" && $(SCONS)

BUILD_APP_WITH_SCONS_RELEASE:
	cd "$(PROJ_DIR)" && $(SCONS) --release

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