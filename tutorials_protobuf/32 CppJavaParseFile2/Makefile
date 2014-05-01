PROJ_DIR:=$(shell pwd)
ROOT_DIR:=$(shell dirname "$(PROJ_DIR)")
SCONS=../tools/scons/bin/scons
MAIN_CLASS:=build/main/Main.class
MAIN_JAVA:=src/main/Main.java
PROTOBUF_JAR:=../lib/protobuf/lib/protobuf-java-2.5.0.jar

all: debug
#all: LINK_HEADER_DIR

# PROTO_GENERATE should be before BUILD_APP_WITH_SCONS_RELEASE
release:	BOOTSTRAP 						\
			LINK_HEADER_DIR 				\
			LINK_LIB_DIR 					\
			PROTO_GENERATE 					\
			BUILD_APP_WITH_SCONS_RELEASE 	\
			JAVA_BUILD
			
# PROTO_GENERATE should be before BUILD_APP_WITH_SCONS_DEBUG
debug: 		BOOTSTRAP 						\
			LINK_HEADER_DIR 				\
			LINK_LIB_DIR 					\
			PROTO_GENERATE 					\
			BUILD_APP_WITH_SCONS_DEBUG		\
			JAVA_BUILD

runjava: JAVA_BUILD
	cd build; \
	java -cp ".:../src/$(PROTOBUF_JAR)"  main.Main; \
	cd ../;

runcpp: debug
	./build/darwin/exe

JAVA_BUILD: $(MAIN_CLASS)

$(MAIN_CLASS): $(MAIN_JAVA) src/$(PROTOBUF_JAR)
	cd src; 												\
	javac -cp ".:$(PROTOBUF_JAR)" -d ../build main/Main.java; 	\
	cd ../;

PROTO_GENERATE: 
	"$(PROJ_DIR)"/lib/protobuf/bin/protoc *.proto --cpp_out=src/proto/ --java_out=src/

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
