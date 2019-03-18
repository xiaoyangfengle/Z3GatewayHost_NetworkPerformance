# This file was generated by Simplicity Studio from the following template:
#   app/esf_common/template/unix/Makefile
# Please do not edit it directly.

# This Makefile defines how to build a unix host application connected to an
# Ember NCP EZSP device.  This also works for Windows machines running
# Cygwin.

# Variables

# If using a different compiler than GCC, you can create a makefile
# that overrides the following variables.  
#   COMPILER - Compiler binary path
#   LINKER - Linker binary path
#   ARCHIVE - Optional archive tool, only necessary for building a library.
#     Must also set GENERATE_LIBRARY := 1 in your makefile.
#   COMPILER_INCLUDES - Any additional compiler includes each prefixed with -I
#   COMPILER_DEFINES - Any additional compiler defines each prefixed with -D
#   COMPILER_FLAGS - The set of compiler flags (not including dependencies)
#   LINKER_FLAGS - The set of linker flags
#   ARCHIVE_FLAGS - The set of archive tool flags.
#   DEPENDENCY_FLAGS - The set of dependency generation flags used to generate
#     dependencies at the same time compilation is executed.
#   DEPENDENCY_POST_PROCESS - An optional post processing step for massaging
#     generated dependencies.  Only necessary when using a compiler on the 
#     non-native platform (e.g. Windows compiler on Linux)
#   PLATFORM_HEADER_FILE - The header file defining the basic int8u, int32u,
#     and other typedefs and platform elements.
#   ARCHIVE_EXTENSION - The file extension for archives if not using the standard
#     .a file extension.
#
# Then pass the makefile to this one on the command line with:
#   "make -C app/builder/Z3GatewayHost_NetworkPerformance INCLUDE_MAKEFILE=my-custom.mak"
#   or 
#   "cd app/builder/Z3GatewayHost_NetworkPerformance; make INCLUDE_MAKEFILE=my-custom.mak"
#

ifdef INCLUDE_MAKEFILE
  include $(INCLUDE_MAKEFILE)
endif  

COMPILER ?= gcc
LINKER   ?= gcc
ARCHIVE  ?= ar
STD      ?= gnu99

ARCHIVE_EXTENSION ?= .a

CC = $(COMPILER)
LD = $(LINKER)
SHELL = /bin/sh

ifneq ($(CURDIR),$(shell dirname '$(abspath $(lastword $(MAKEFILE_LIST)))'))
$(error This makefile should only be invoked under its current directory ($(shell dirname '$(abspath $(lastword $(MAKEFILE_LIST)))')))
endif

COMPILER_INCLUDES ?= 

INCLUDES= \
  $(COMPILER_INCLUDES) \
  -I./../../.. \
  -I./../../../protocol/zigbee/app/framework \
  -I./../../../protocol/zigbee/app/framework/../.. \
  -I./../../../protocol/zigbee/app/framework/../../stack \
  -I./../../../protocol/zigbee/app/framework/../util \
  -I./../../../protocol/zigbee/app/framework/../util/common \
  -I./../../../protocol/zigbee/app/framework/../util/ezsp \
  -I./../../../protocol/zigbee/app/framework/../util/serial \
  -I./../../../protocol/zigbee/app/framework/../util/zigbee-framework \
  -I./../../../protocol/zigbee/app/framework/cli \
  -I./../../../protocol/zigbee/app/framework/include \
  -I./../../../protocol/zigbee/app/framework/security \
  -I./../../../protocol/zigbee/app/framework/util \
  -I./../../../app/builder/Z3GatewayHost_NetworkPerformance \
  -I./../../../platform/base/hal \
  -I./../../../platform/base/hal/plugin \
  -I./../../../platform/base/hal/.. \
  -I./../../../platform/base/hal/micro/generic \
  -I./../../../platform/base/hal/micro/unix/host \
  -I../../../platform/base/hal/micro/unix/host/board \
 \

APP_BUILDER_OUTPUT_DIRECTORY=.
APP_BUILDER_CONFIG_HEADER=$(APP_BUILDER_OUTPUT_DIRECTORY)/Z3GatewayHost_NetworkPerformance.h
APP_BUILDER_STORAGE_FILE=$(APP_BUILDER_OUTPUT_DIRECTORY)/Z3GatewayHost_NetworkPerformance_endpoint_config.h

PLATFORM_HEADER_FILE ?= \"../../../platform/base/hal/micro/unix/compiler/gcc.h\"

DEFINES = \
  $(COMPILER_DEFINES) \
  -DUNIX \
  -DUNIX_HOST \
  -DPHY_NULL \
  -DCONFIGURATION_HEADER=\"../../../protocol/zigbee/app/framework/util/config.h\" \
  -DEZSP_HOST \
  -DGATEWAY_APP \
  -DZA_GENERATED_HEADER=\"$(APP_BUILDER_CONFIG_HEADER)\" \
  -DATTRIBUTE_STORAGE_CONFIGURATION=\"$(APP_BUILDER_STORAGE_FILE)\" \
  -DPLATFORM_HEADER=$(PLATFORM_HEADER_FILE) \
    -DBOARD_HOST \
  -DBOARD_HEADER=\"app/builder/Z3GatewayHost_NetworkPerformance/Z3GatewayHost_NetworkPerformance_board.h\" \
  -DEM_AF_TEST_HARNESS_CODE \
  -DEM_AF_LINK_M \
  -DEM_AF_LINK_PTHREAD \
  -DEZSP_ASH=1 \
  -DEZSP_HOST=1 \
  -DEMBER_AF_API_EMBER_TYPES=\"stack/include/ember-types.h\" \
  -DEMBER_AF_API_DEBUG_PRINT=\"app/framework/util/print.h\" \
  -DEMBER_AF_API_AF_HEADER=\"app/framework/include/af.h\" \
  -DEMBER_AF_API_AF_SECURITY_HEADER=\"app/framework/security/af-security.h\" \
  -DEMBER_STACK_ZIGBEE \
  -DAPPLICATION_TOKEN_HEADER=\"app/builder/Z3GatewayHost_NetworkPerformance/afv2-token.h\" \
  -DAPPLICATION_MFG_TOKEN_HEADER=\"app/builder/Z3GatewayHost_NetworkPerformance/afv2-mfg-token.h\" \



COMPILER_FLAGS ?= \
  -Wall \
  -ggdb \
  -O0   \
  -std=$(STD)

APPLICATION_FILES= \
  ../../../app/builder/Z3GatewayHost_NetworkPerformance/afv2-bookkeeping.c \
  ../../../app/builder/Z3GatewayHost_NetworkPerformance/call-command-handler.c \
  ../../../app/builder/Z3GatewayHost_NetworkPerformance/callback-stub.c \
  ../../../app/builder/Z3GatewayHost_NetworkPerformance/stack-handler-stub.c \
  ../../../app/builder/Z3GatewayHost_NetworkPerformance/cli.c \
  ../../../app/builder/Z3GatewayHost_NetworkPerformance/Z3GatewayHost_NetworkPerformance_callbacks.c \
  ../../../protocol/zigbee/app/framework/cli/core-cli.c \
  ../../../protocol/zigbee/app/framework/cli/network-cli.c \
  ../../../protocol/zigbee/app/framework/cli/option-cli.c \
  ../../../protocol/zigbee/app/framework/cli/plugin-cli.c \
  ../../../protocol/zigbee/app/framework/cli/security-cli.c \
  ../../../protocol/zigbee/app/framework/cli/zcl-cli.c \
  ../../../protocol/zigbee/app/framework/cli/zdo-cli.c \
  ../../../protocol/zigbee/app/framework/security/af-node.c \
  ../../../protocol/zigbee/app/framework/security/af-security-common.c \
  ../../../protocol/zigbee/app/framework/security/af-trust-center.c \
  ../../../protocol/zigbee/app/framework/security/crypto-state.c \
  ../../../protocol/zigbee/app/framework/util/af-event.c \
  ../../../protocol/zigbee/app/framework/util/af-main-common.c \
  ../../../protocol/zigbee/app/framework/util/af-main-host.c \
  ../../../protocol/zigbee/app/framework/util/attribute-size.c \
  ../../../protocol/zigbee/app/framework/util/attribute-storage.c \
  ../../../protocol/zigbee/app/framework/util/attribute-table.c \
  ../../../protocol/zigbee/app/framework/util/client-api.c \
  ../../../protocol/zigbee/app/framework/util/message.c \
  ../../../protocol/zigbee/app/framework/util/multi-network.c \
  ../../../protocol/zigbee/app/framework/util/print.c \
  ../../../protocol/zigbee/app/framework/util/print-formatter.c \
  ../../../protocol/zigbee/app/framework/util/process-cluster-message.c \
  ../../../protocol/zigbee/app/framework/util/process-global-message.c \
  ../../../protocol/zigbee/app/framework/util/service-discovery-common.c \
  ../../../protocol/zigbee/app/framework/util/service-discovery-host.c \
  ../../../protocol/zigbee/app/framework/util/time-util.c \
  ../../../protocol/zigbee/app/framework/util/util.c \
  ../../../protocol/zigbee/app/framework/../util/common/library.c \
  ../../../protocol/zigbee/app/framework/../util/serial/command-interpreter2.c \
  ../../../protocol/zigbee/app/framework/../util/zigbee-framework/zigbee-device-common.c \
  ../../../protocol/zigbee/app/framework/../util/zigbee-framework/zigbee-device-host.c \
  ../../../protocol/zigbee/app/framework/../../stack/framework/event-control.c \
  ../../../platform/base/hal/micro/generic/led-stub.c \
  ../../../platform/base/hal/micro/generic/mem-util.c \
  ../../../platform/base/hal/plugin/antenna-stub/antenna-stub.c \
  ../../../platform/base/hal/plugin/buzzer-stub/buzzer-stub.c \
  ../../../protocol/zigbee/app/framework/plugin/address-table/address-table.c \
  ../../../protocol/zigbee/app/framework/plugin/address-table/address-table-cli.c \
  ../../../platform/base/phy/simulation/aes-software.c \
  ../../../protocol/zigbee/app/framework/plugin/basic/basic.c \
  ../../../protocol/zigbee/app/framework/plugin/concentrator/concentrator-support.c \
  ../../../protocol/zigbee/app/framework/plugin/concentrator/concentrator-support-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/concentrator/source-route-common.c \
  ../../../protocol/zigbee/app/framework/plugin/concentrator/source-route-host.c \
  ../../../protocol/zigbee/app/framework/plugin/counters/counters-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/counters/counters-ota-host.c \
  ../../../protocol/zigbee/app/framework/plugin/counters/counters-host.c \
  ../../../protocol/zigbee/app/framework/plugin/ezmode-commissioning/ez-mode.c \
  ../../../protocol/zigbee/app/framework/plugin/ezmode-commissioning/ez-mode-cli.c \
  ../../../protocol/zigbee/app/util/ezsp/ezsp-callbacks.c \
  ../../../protocol/zigbee/app/util/ezsp/ezsp-enum-decode.c \
  ../../../protocol/zigbee/app/util/ezsp/ezsp-frame-utilities.c \
  ../../../protocol/zigbee/app/util/ezsp/ezsp.c \
  ../../../protocol/zigbee/app/ezsp-host/ezsp-host-io.c \
  ../../../protocol/zigbee/app/ezsp-host/ezsp-host-queues.c \
  ../../../protocol/zigbee/app/ezsp-host/ezsp-host-ui.c \
  ../../../protocol/zigbee/app/util/ezsp/serial-interface-uart.c \
  ../../../protocol/zigbee/app/ezsp-host/ash/ash-host-ui.c \
  ../../../protocol/zigbee/app/ezsp-host/ash/ash-host.c \
  ../../../platform/base/hal/micro/generic/ash-common.c \
  ../../../protocol/zigbee/app/framework/plugin-host/file-descriptor-dispatch/file-descriptor-dispatch.c \
  ../../../protocol/zigbee/app/framework/plugin/form-and-join/form-and-join-afv2.c \
  ../../../protocol/zigbee/app/util/common/form-and-join.c \
  ../../../protocol/zigbee/app/util/common/form-and-join-host-adapter.c \
  ../../../protocol/zigbee/app/framework/plugin-host/gateway/gateway-support.c \
  ../../../protocol/zigbee/app/framework/plugin-host/gateway/backchannel-support.c \
  ../../../protocol/zigbee/app/framework/plugin-host/gateway/gateway-support-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/green-power-client/green-power-client.c \
  ../../../protocol/zigbee/app/framework/plugin/green-power-client/green-power-client-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/green-power-common/green-power-common.c \
  ../../../protocol/zigbee/stack/gp/gp-util.c \
  ../../../protocol/zigbee/app/framework/plugin/heartbeat/heartbeat.c \
  ../../../protocol/zigbee/app/framework/plugin/ias-zone-client/ias-zone-client.c \
  ../../../protocol/zigbee/app/framework/plugin/ias-zone-client/ias-zone-client-cli.c \
  ../../../util/plugin/plugin-common/linked-list/linked-list.c \
  ../../../protocol/zigbee/app/framework/plugin-host/ncp-configuration/ncp-configuration.c \
  ../../../protocol/zigbee/app/framework/plugin/network-creator/network-creator.c \
  ../../../protocol/zigbee/app/framework/plugin/network-creator/network-creator-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/network-creator-security/network-creator-security.c \
  ../../../protocol/zigbee/app/framework/plugin/network-creator-security/network-creator-security-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/network-find/network-find.c \
  ../../../protocol/zigbee/app/framework/plugin/network-find/network-find-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/ota-common/ota-common.c \
  ../../../protocol/zigbee/app/framework/plugin/ota-server/ota-server.c \
  ../../../protocol/zigbee/app/framework/plugin/ota-server/ota-server-page-request.c \
  ../../../protocol/zigbee/app/framework/plugin/ota-server/ota-server-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/ota-server/ota-server-dynamic-block-period.c \
  ../../../protocol/zigbee/app/framework/plugin/ota-server-policy/ota-server-policy.c \
  ../../../protocol/zigbee/app/framework/plugin/ota-storage-common/ota-storage-common.c \
  ../../../protocol/zigbee/app/framework/plugin/ota-storage-common/ota-storage-common-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/ota-storage-posix-filesystem/ota-storage-linux.c \
  ../../../protocol/zigbee/app/framework/plugin/poll-control-client/poll-control-client.c \
  ../../../protocol/zigbee/app/framework/plugin/poll-control-client/poll-control-client-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/reporting/reporting.c \
  ../../../protocol/zigbee/app/framework/plugin/reporting/reporting-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/reporting/reporting-default-configuration.c \
  ../../../protocol/zigbee/app/framework/plugin/scan-dispatch/scan-dispatch.c \
  ../../../protocol/zigbee/app/framework/plugin-host/secure-ezsp/secure-ezsp-cli.c \
  ../../../protocol/zigbee/app/util/ezsp/secure-ezsp.c \
  ../../../protocol/zigbee/app/util/ezsp/secure-ezsp-host.c \
  ../../../protocol/zigbee/app/util/secure-ezsp/aes-mmo.c \
  ../../../protocol/zigbee/app/util/secure-ezsp/hmac.c \
  ../../../protocol/zigbee/app/util/secure-ezsp/802-15-4-ccm.c \
  ../../../protocol/zigbee/app/framework/plugin-host/security-support/security-support.c \
  ../../../protocol/zigbee/tool/random/random-linux.c \
  ../../../protocol/zigbee/app/framework/plugin/simple-main/simple-main.c \
  ../../../protocol/zigbee/app/framework/plugin/simple-metering-client/simple-metering-client.c \
  ../../../protocol/zigbee/app/framework/plugin/simple-metering-client/simple-metering-client-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/stack-diagnostics/stack-diagnostics.c \
  ../../../protocol/zigbee/app/framework/plugin/test-harness/test-harness.c \
  ../../../protocol/zigbee/app/framework/plugin/test-harness/read-write-attributes.c \
  ../../../protocol/zigbee/app/framework/plugin/test-harness/test-harness-host.c \
  ../../../protocol/zigbee/app/framework/plugin/time-server/time-server.c \
  ../../../protocol/zigbee/app/framework/plugin/trust-center-backup/trust-center-backup.c \
  ../../../protocol/zigbee/app/framework/plugin/trust-center-backup/trust-center-backup-cli.c \
  ../../../protocol/zigbee/app/framework/plugin/trust-center-backup/trust-center-backup-cli-posix.c \
  ../../../protocol/zigbee/app/framework/plugin/trust-center-backup/trust-center-backup-posix.c \
  ../../../protocol/zigbee/app/framework/plugin/trust-center-nwk-key-update-broadcast/trust-center-nwk-key-update-broadcast.c \
  ../../../protocol/zigbee/app/framework/plugin/trust-center-nwk-key-update-periodic/trust-center-nwk-key-update-periodic.c \
  ../../../protocol/zigbee/app/framework/plugin/trust-center-nwk-key-update-unicast/trust-center-nwk-key-update-unicast.c \
  ../../../platform/base/hal/micro/generic/crc.c \
  ../../../platform/base/hal/micro/generic/endian.c \
  ../../../platform/base/hal/micro/generic/random.c \
  ../../../platform/base/hal/micro/generic/system-timer.c \
  ../../../platform/base/hal/micro/unix/host/micro.c \
  ../../../platform/base/hal/micro/unix/host/token-def-unix.c \
  ../../../platform/base/hal/micro/unix/host/token.c \
  ../../../platform/base/hal/plugin/serial/ember-printf-convert.c \
  ../../../protocol/zigbee/app/util/serial/linux-serial.c \
  ../../../platform/base/hal/micro/generic/aes/rijndael-alg-fst.c \
  ../../../platform/base/hal/micro/generic/aes/rijndael-api-fst.c \


LIBRARIES = \
 \


OUTPUT_DIR=$(APP_BUILDER_OUTPUT_DIRECTORY)/build
OUTPUT_DIR_CREATED= $(OUTPUT_DIR)/created
EXE_DIR=$(OUTPUT_DIR)/exe
# Build a list of object files from the source file list, but all objects
# live in the $(OUTPUT_DIR) above.  The list of object files
# created assumes that the file part of the filepath is unique
# (i.e. the bar.c of foo/bar.c is unique across all sub-directories included).
APPLICATION_OBJECTS= $(shell echo $(APPLICATION_FILES) | xargs -n1 echo | sed -e 's^.*/\(.*\)\.c^$(OUTPUT_DIR)/\1\.o^')

ifdef GENERATE_LIBRARY
TARGET_FILE= $(EXE_DIR)/Z3GatewayHost_NetworkPerformance$(ARCHIVE_EXTENSION)
else
TARGET_FILE= $(EXE_DIR)/Z3GatewayHost_NetworkPerformance
endif

# -MMD and -MF generates Makefile dependencies while at the same time compiling.
# -MP notes to add a dummy 'build' rule for each header file.  This 
# prevent a problem where a removed header file will generate an error because a
# dependency references it but it can't be found anymore.
DEPENDENCY_FLAGS ?= -MMD -MP -MF $(@D)/$(@F:.o=.d)

# Dependency post process is a way to massage generated dependencies.
# This is necessary for example when using Make under Cygwin but compiling
# using a native Windows compiler that generates native Windows paths
# that Cygwin will choke on.  Or if compiling on Linux using Wine to run a 
# Windows compiler, a similar problem can occur.  
DEPENDENCY_POST_PROCESS ?=

CPPFLAGS= $(INCLUDES) $(DEFINES) $(COMPILER_FLAGS) $(DEPENDENCY_FLAGS)
LINKER_FLAGS ?=

ifdef NO_READLINE
  CPPFLAGS += -DNO_READLINE
else
  LINKER_FLAGS +=  \
    -lreadline \
    -lncurses 
endif

# Conditionally include the math library if EM_AF_LINK_M is defined.
ifeq ($(findstring -DEM_AF_LINK_M,$(DEFINES)),-DEM_AF_LINK_M)
  LINKER_FLAGS += \
    -lm
endif

# Conditionally include the POSIX threads library if EM_AF_LINK_PTHREAD is
# defined.
ifeq ($(findstring -DEM_AF_LINK_PTHREAD,$(DEFINES)),-DEM_AF_LINK_PTHREAD)
  LINKER_FLAGS += \
    -lpthread
endif

ARCHIVE_FLAGS ?= rus

# Rules

.PHONY: all
all: $(TARGET_FILE)

ifneq ($(MAKECMDGOALS),clean)
-include $(APPLICATION_OBJECTS:.o=.d)
endif

ifdef GENERATE_LIBRARY
$(TARGET_FILE): $(APPLICATION_OBJECTS) $(LIBRARIES)
	$(ARCHIVE) $(ARCHIVE_FLAGS) $(TARGET_FILE) $^
	@echo -e '\n$@ build success'
else
$(TARGET_FILE): $(APPLICATION_OBJECTS) $(LIBRARIES)
	$(LD) $^ $(LINKER_FLAGS) -o $(TARGET_FILE)
	@echo -e '\n$@ build success'
endif

.PHONY: clean
clean:
	rm -rf $(OUTPUT_DIR)

$(OUTPUT_DIR_CREATED):
	mkdir -p $(OUTPUT_DIR)
	mkdir -p $(EXE_DIR)
	touch $(OUTPUT_DIR_CREATED)

# To facilitate generating all output files in a single output directory, we
# must create separate .o and .d rules for all the different sub-directories
# used by the source files.
# If additional directories are added that are not already in the
# $(APPLICATION_FILES) above, new rules will have to be created below.

# Object File rules

define make-deps 
$(OUTPUT_DIR)/$(notdir $(1:%.c=%.o)): $1 | $(OUTPUT_DIR_CREATED) 
endef 
 
$(foreach d, $(APPLICATION_FILES), $(eval $(call make-deps,$d))) 
 
%.o :
	$(CC) $(CPPFLAGS) -c $< -o $(OUTPUT_DIR)/$(@F)
	$(DEPENDENCY_POST_PROCESS)

# Dependency rules
# No explicit rules.  Dependencies are generated as part of the compile step.
