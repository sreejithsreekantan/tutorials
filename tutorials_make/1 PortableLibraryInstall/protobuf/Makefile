LIB_NAME=protobuf
VERSION=2.5.0

ZIP_DIR=$(shell pwd)
LIB_DIR=$(shell dirname $(ZIP_DIR))
STAGING_DIR=$(LIB_DIR)/staging
INSTALL_DIR=$(LIB_DIR)/install/$(LIB_NAME)
LIB_VERSION_NAME=$(LIB_NAME)-$(VERSION)
LIB_ZIP_FILE_NAME=$(LIB_VERSION_NAME).tar.gz



all: PROTOBUF

PROTOBUF: $(INSTALL_DIR)

$(INSTALL_DIR): $(ZIP_DIR)/$(LIB_ZIP_FILE_NAME)
	echo $<
	mkdir -p $(STAGING_DIR) $@
	tar -zxf $< -C $(STAGING_DIR)
	cd $(STAGING_DIR)/$(LIB_VERSION_NAME) && \
	./configure --prefix="$(INSTALL_DIR)" && \
	make install
	@echo "****** $(PROTOBUF_ZIP) successfully installed in $(INSTALL_DIR)"

.PHONY: clean

clean:
	rm -rf $(STAGING_DIR) $(INSTALL_DIR)
