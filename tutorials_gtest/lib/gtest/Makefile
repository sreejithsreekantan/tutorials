PROJECT_DIR=$(shell pwd)
STAGING_DIR=$(shell dirname $(PROJECT_DIR))/staging
INSTALL_DIR=$(shell dirname $(PROJECT_DIR))/install/gtest
GTEST_DIR=gmock-1.7.0
GTEST_ZIP=$(GTEST_DIR).zip
GTEST_LIB=$(INSTALL_DIR)/lib/libgtest.a
TMP_DIR=$(STAGING_DIR)/tmp


all: GTEST

GTEST: $(GTEST_LIB)

$(GTEST_LIB): $(STAGING_DIR)/$(GTEST_DIR)
	mkdir -p $(TMP_DIR)
	mkdir -p $(INSTALL_DIR)/lib $(INSTALL_DIR)/include
	cp -R $</include/* 		$(INSTALL_DIR)/include
	cp -R $</gtest/include/*	$(INSTALL_DIR)/include
	g++ -pthread -I $</gtest/ -I $</gtest/include/ -c  $</gtest/src/gtest-all.cc  -o $(TMP_DIR)/gtest-all.o
	g++ -pthread -I $</ -I $</include/ -I $</gtest/include/ -c  $</src/gmock-all.cc  -o $(TMP_DIR)/gmock-all.o
	ar -rv $(INSTALL_DIR)/lib/libgtest.a $(TMP_DIR)/gtest-all.o $(TMP_DIR)/gmock-all.o
	ranlib $(INSTALL_DIR)/lib/libgtest.a
	@echo "****** $(GTEST_ZIP) successfully installed in $(INSTALL_DIR)"


$(STAGING_DIR)/$(GTEST_DIR): $(GTEST_ZIP) 
	if [ ! -e $(STAGING_DIR)/$(GTEST_DIR) ]; then \
		mkdir -p $(STAGING_DIR) $(INSTALL_DIR); \
		unzip $(GTEST_ZIP) -d $(STAGING_DIR); \
	fi

.PHONY: clean

clean:
	rm -rf $(STAGING_DIR) $(INSTALL_DIR)
