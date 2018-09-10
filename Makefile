#
#
# Copyright (C) 2017 OpenWrt.org
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=gl-demo
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/gl-demo
  SECTION:=base
  CATEGORY:=gl-inet
  TITLE:=GL iNet SDK3.0 demo
  DEPENDS:=
endef

define Package/gl-demo/description
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/include/gl
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/libgldemo.so $(1)/usr/lib
endef

define Package/gl-demo/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/demotest  $(1)/usr/bin
	
	$(INSTALL_DIR) $(1)/usr/lib/gl
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/libgldemo.so $(1)/usr/lib/gl
	$(LN) /usr/lib/gl/libgldemo.so $(1)/usr/lib/
endef

$(eval $(call BuildPackage,gl-demo))
