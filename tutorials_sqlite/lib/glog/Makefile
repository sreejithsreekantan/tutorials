PROJECT_DIR=$(shell pwd)
STAGING_DIR=$(shell dirname $(PROJECT_DIR))/staging
INSTALL_DIR=$(shell dirname $(PROJECT_DIR))/install/glog
GFLAGS_DIR=glog-0.3.3
GFLAGS_ZIP=$(GFLAGS_DIR).tar.gz
GFLAGS_LIB=$(INSTALL_DIR)/lib/libglog.a


all: gflags

gflags: $(GFLAGS_LIB)

$(GFLAGS_LIB): $(GFLAGS_ZIP)
	echo $(PROJECT_DIR)
	mkdir -p $(STAGING_DIR) $(INSTALL_DIR)
	tar -zxf $(GFLAGS_ZIP) -C $(STAGING_DIR)
	cd $(STAGING_DIR)/$(GFLAGS_DIR) && \
	./configure --prefix="$(INSTALL_DIR)" && \
	make install
	@echo "****** $(GFLAGS_ZIP) successfully installed in $(INSTALL_DIR)"

.PHONY: clean

clean:
	rm -rf $(STAGING_DIR) $(INSTALL_DIR)
