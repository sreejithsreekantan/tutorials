PROJ_DIR:=$(shell pwd)
ROOT_DIR:=$(shell dirname "$(PROJ_DIR)")
MAIN_CLASS:=build/main/Main.class
MAIN_JAVA:=src/main/Main.java
PROTOBUF_JAR:=protobuf-java-2.5.0.jar


all: JAVA_BUILD
#all: LINK_HEADER_DIR

release:	JAVA_BUILD

runjava: JAVA_BUILD
	cd build; \
	java -cp ".:../src/$(PROTOBUF_JAR)"  main.Main; \
	cd ../;

debug:	JAVA_BUILD

JAVA_BUILD: $(MAIN_CLASS)

$(MAIN_CLASS): $(MAIN_JAVA) src/$(PROTOBUF_JAR)
	cd src; 												\
	javac -cp ".:$(PROTOBUF_JAR)" -d ../build main/Main.java; 	\
	cd ../;


.PHONY: clean

clean:
	rm -Rf $(MAIN_CLASS)