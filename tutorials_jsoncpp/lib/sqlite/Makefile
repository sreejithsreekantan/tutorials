PROJECT_DIR=$(shell pwd)

# change these to match libary's name,directory and type of compression.
LIB_NAME=sqlite
LIB_DIR=$(LIB_NAME)-autoconf-3080403
COMPRESSION_TYPE=tar.gz

ZIP_FILE=$(LIB_DIR).$(COMPRESSION_TYPE)
STAGING_ABS_PATH=$(shell dirname $(PROJECT_DIR))/staging
LIB_INSTALL_ABS_PATH=$(shell dirname $(PROJECT_DIR))/install/$(LIB_NAME)



all: sqlite

sqlite: $(LIB_INSTALL_ABS_PATH)

$(LIB_INSTALL_ABS_PATH): $(STAGING_ABS_PATH)/$(LIB_DIR)
	mkdir -p $@
	cd $< && \
	./configure --prefix="$@" && \
	make install
	@echo "****** $(ZIP_FILE) successfully installed in $(LIB_INSTALL_ABS_PATH)"

$(STAGING_ABS_PATH)/$(LIB_DIR): $(ZIP_FILE)
	mkdir -p $@
	tar -zxf $< -C $@/../

.PHONY: sqlite

clean:
	rm -rf $(STAGING_ABS_PATH)/$(LIB_DIR) $(LIB_INSTALL_ABS_PATH)
