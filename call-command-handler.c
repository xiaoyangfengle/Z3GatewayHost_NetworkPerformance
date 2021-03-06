// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// This is a set of generated functions that parse the
// the incomming message, and call appropriate command handler.



#include PLATFORM_HEADER
#ifdef EZSP_HOST
// Includes needed for ember related functions for the EZSP host
#include "stack/include/error.h"
#include "stack/include/ember-types.h"
#include "app/util/ezsp/ezsp-protocol.h"
#include "app/util/ezsp/ezsp.h"
#include "app/util/ezsp/ezsp-utils.h"
#include "app/util/ezsp/serial-interface.h"
#else
// Includes needed for ember related functions for the EM250
#include "stack/include/ember.h"
#endif // EZSP_HOST

#include "app/framework/util/util.h"
#include "af-structs.h"
#include "call-command-handler.h"
#include "command-id.h"
#include "callback.h"

static EmberAfStatus status(bool wasHandled, bool clusterExists, bool mfgSpecific)
{
  if (wasHandled) {
    return EMBER_ZCL_STATUS_SUCCESS;
  } else if (mfgSpecific) {
    return EMBER_ZCL_STATUS_UNSUP_MANUF_CLUSTER_COMMAND;
  } else if (clusterExists) {
    return EMBER_ZCL_STATUS_UNSUP_CLUSTER_COMMAND;
  } else {
    return EMBER_ZCL_STATUS_UNSUPPORTED_CLUSTER;
  }
}

// Main command parsing controller.
EmberAfStatus emberAfClusterSpecificCommandParse(EmberAfClusterCommand *cmd)
{
  EmberAfStatus result = status(false, false, cmd->mfgSpecific);
  if (cmd->direction == (uint8_t)ZCL_DIRECTION_SERVER_TO_CLIENT
      && emberAfContainsClientWithMfgCode(cmd->apsFrame->destinationEndpoint,
                               cmd->apsFrame->clusterId,
                               cmd->mfgCode)) {
    switch (cmd->apsFrame->clusterId) {
    case ZCL_BASIC_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_POWER_CONFIG_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_DEVICE_TEMP_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_IDENTIFY_CLUSTER_ID:
      result = emberAfIdentifyClusterClientCommandParse(cmd);
      break;
    case ZCL_GROUPS_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_SCENES_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_ON_OFF_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_LEVEL_CONTROL_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_ALARM_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_POLL_CONTROL_CLUSTER_ID:
      result = emberAfPollControlClusterClientCommandParse(cmd);
      break;
    case ZCL_GREEN_POWER_CLUSTER_ID:
      result = emberAfGreenPowerClusterClientCommandParse(cmd);
      break;
    case ZCL_SHADE_CONFIG_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_DOOR_LOCK_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_WINDOW_COVERING_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_BARRIER_CONTROL_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_PUMP_CONFIG_CONTROL_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_THERMOSTAT_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_FAN_CONTROL_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_DEHUMID_CONTROL_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_THERMOSTAT_UI_CONFIG_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_COLOR_CONTROL_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_ILLUM_MEASUREMENT_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_TEMP_MEASUREMENT_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_PRESSURE_MEASUREMENT_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_FLOW_MEASUREMENT_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_RELATIVE_HUMIDITY_MEASUREMENT_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_OCCUPANCY_SENSING_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_IAS_ZONE_CLUSTER_ID:
      result = emberAfIasZoneClusterClientCommandParse(cmd);
      break;
    case ZCL_IAS_WD_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_SIMPLE_METERING_CLUSTER_ID:
      result = emberAfSimpleMeteringClusterClientCommandParse(cmd);
      break;
    case ZCL_METER_IDENTIFICATION_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_APPLIANCE_STATISTICS_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_ELECTRICAL_MEASUREMENT_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_OTA_CONFIGURATION_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_MFGLIB_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    default:
      // Unrecognized cluster ID, error status will apply.
      break;
    }
  } else if (cmd->direction == (uint8_t)ZCL_DIRECTION_CLIENT_TO_SERVER
             && emberAfContainsServerWithMfgCode(cmd->apsFrame->destinationEndpoint,
                                       cmd->apsFrame->clusterId,
                                       cmd->mfgCode)) {
    switch (cmd->apsFrame->clusterId) {
    case ZCL_BASIC_CLUSTER_ID:
      result = emberAfBasicClusterServerCommandParse(cmd);
      break;
    case ZCL_TIME_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_OTA_BOOTLOAD_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    case ZCL_POWER_PROFILE_CLUSTER_ID:
      result = status(false, true, cmd->mfgSpecific);
      break;
    default:
      // Unrecognized cluster ID, error status will apply.
      break;
    }
  }
  return result;
}

// Cluster: Basic, server
EmberAfStatus emberAfBasicClusterServerCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_RESET_TO_FACTORY_DEFAULTS_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfBasicClusterResetToFactoryDefaultsCallback();
        break;
      }
    default:
      {
        // Unrecognized command ID, error status will apply.
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: Identify, client
EmberAfStatus emberAfIdentifyClusterClientCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_IDENTIFY_QUERY_RESPONSE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t timeout;  // Ver.: always
        // Command is fixed length: 2
        if (cmd->bufLen < payloadOffset + 2u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        timeout = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfIdentifyClusterIdentifyQueryResponseCallback(timeout);
        break;
      }
    default:
      {
        // Unrecognized command ID, error status will apply.
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: Poll Control, client
EmberAfStatus emberAfPollControlClusterClientCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_CHECK_IN_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfPollControlClusterCheckInCallback();
        break;
      }
    default:
      {
        // Unrecognized command ID, error status will apply.
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: Green Power, client
EmberAfStatus emberAfGreenPowerClusterClientCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_GP_NOTIFICATION_RESPONSE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t options;  // Ver.: since gp-1.0-09-5499-24
        uint32_t gpdSrcId;  // Ver.: since gp-1.0-09-5499-24
        uint8_t* gpdIeee;  // Ver.: since gp-1.0-09-5499-24
        uint8_t endpoint;  // Ver.: since gp-1.0-09-5499-24
        uint32_t gpdSecurityFrameCounter;  // Ver.: since gp-1.0-09-5499-24
        // Command is not a fixed length
        if ( ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          options = 0xFF;
        } else {
          options = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( !( (options & 0x0007) == 0x0000) || ( cmd->bufLen < payloadOffset + 4u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x0007) == 0x0000
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdSrcId = 0xFFFFFFFF;
        } else {
          gpdSrcId = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 4u;
        }
        if ( !( (options & 0x0007) == 0x0002) || ( cmd->bufLen < payloadOffset + 8u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x0007) == 0x0002
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdIeee = NULL;
        } else {
          gpdIeee = cmd->buffer + payloadOffset;
          payloadOffset += 8u;
        }
        if ( !( (options & 0x0007) == 0x0002) || ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x0007) == 0x0002
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          endpoint = 0xFF;
        } else {
          endpoint = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( ( cmd->bufLen < payloadOffset + 4u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdSecurityFrameCounter = 0xFFFFFFFF;
        } else {
          gpdSecurityFrameCounter = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
        }
        wasHandled = emberAfGreenPowerClusterGpNotificationResponseCallback(options,
                                                                            gpdSrcId,
                                                                            gpdIeee,
                                                                            endpoint,
                                                                            gpdSecurityFrameCounter);
        break;
      }
    case ZCL_GP_PAIRING_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint32_t options;  // Ver.: since gp-1.0-09-5499-24
        uint32_t gpdSrcId;  // Ver.: since gp-1.0-09-5499-24
        uint8_t* gpdIeee;  // Ver.: since gp-1.0-09-5499-24
        uint8_t endpoint;  // Ver.: since gp-1.0-09-5499-24
        uint8_t* sinkIeeeAddress;  // Ver.: since gp-1.0-09-5499-24
        uint16_t sinkNwkAddress;  // Ver.: since gp-1.0-09-5499-24
        uint16_t sinkGroupId;  // Ver.: since gp-1.0-09-5499-24
        uint8_t deviceId;  // Ver.: since gp-1.0-09-5499-24
        uint32_t gpdSecurityFrameCounter;  // Ver.: since gp-1.0-09-5499-24
        uint8_t* gpdKey;  // Ver.: since gp-1.0-09-5499-24
        uint16_t assignedAlias;  // Ver.: since gp-1.0-09-5499-24
        uint8_t groupcastRadius;  // Ver.: since gp-1.0-09-5499-24
        // Command is not a fixed length
        if ( ( cmd->bufLen < payloadOffset + 3u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          options = 0xFFFFFFFF;
        } else {
          options = emberAfGetInt24u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 3u;
        }
        if ( !( (options & 0x000007) == 0x000000) || ( cmd->bufLen < payloadOffset + 4u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x000007) == 0x000000
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdSrcId = 0xFFFFFFFF;
        } else {
          gpdSrcId = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 4u;
        }
        if ( !( (options & 0x000007) == 0x000002) || ( cmd->bufLen < payloadOffset + 8u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x000007) == 0x000002
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdIeee = NULL;
        } else {
          gpdIeee = cmd->buffer + payloadOffset;
          payloadOffset += 8u;
        }
        if ( !( (options & 0x000007) == 0x000002) || ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x000007) == 0x000002
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          endpoint = 0xFF;
        } else {
          endpoint = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( !( (options & 0x000010) == 0x000000 && ((options & 0x000060) == 0x000000 || (options & 0x000060) == 0x000060)) || ( cmd->bufLen < payloadOffset + 8u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x000010) == 0x000000 && ((options & 0x000060) == 0x000000 || (options & 0x000060) == 0x000060)
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          sinkIeeeAddress = NULL;
        } else {
          sinkIeeeAddress = cmd->buffer + payloadOffset;
          payloadOffset += 8u;
        }
        if ( !( (options & 0x000010) == 0x000000 && ((options & 0x000060) == 0x000000 || (options & 0x000060) == 0x000060)) || ( cmd->bufLen < payloadOffset + 2u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x000010) == 0x000000 && ((options & 0x000060) == 0x000000 || (options & 0x000060) == 0x000060)
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          sinkNwkAddress = 0xFFFF;
        } else {
          sinkNwkAddress = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 2u;
        }
        if ( !( (options & 0x000010) == 0x000000 && ((options & 0x000060) == 0x000020 || (options & 0x000060) == 0x000040)) || ( cmd->bufLen < payloadOffset + 2u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x000010) == 0x000000 && ((options & 0x000060) == 0x000020 || (options & 0x000060) == 0x000040)
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          sinkGroupId = 0xFFFF;
        } else {
          sinkGroupId = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 2u;
        }
        if ( !( (options & 0x000008) == 0x000008 && (options & 0x000010) != 0x000010) || ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x000008) == 0x000008 && (options & 0x000010) != 0x000010
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          deviceId = 0xFF;
        } else {
          deviceId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( !( (options & 0x004000) == 0x004000) || ( cmd->bufLen < payloadOffset + 4u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x004000) == 0x004000
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdSecurityFrameCounter = 0xFFFFFFFF;
        } else {
          gpdSecurityFrameCounter = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 4u;
        }
        if ( !( (options & 0x008000) == 0x008000) || ( cmd->bufLen < payloadOffset + 16u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x008000) == 0x008000
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdKey = NULL;
        } else {
          gpdKey = cmd->buffer + payloadOffset;
          payloadOffset += 16u;
        }
        if ( !( (options & 0x010000) == 0x010000) || ( cmd->bufLen < payloadOffset + 2u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x010000) == 0x010000
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          assignedAlias = 0xFFFF;
        } else {
          assignedAlias = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 2u;
        }
        if ( !( (options & 0x020000) == 0x020000) || ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x020000) == 0x020000
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          groupcastRadius = 0xFF;
        } else {
          groupcastRadius = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        }
        wasHandled = emberAfGreenPowerClusterGpPairingCallback(options,
                                                               gpdSrcId,
                                                               gpdIeee,
                                                               endpoint,
                                                               sinkIeeeAddress,
                                                               sinkNwkAddress,
                                                               sinkGroupId,
                                                               deviceId,
                                                               gpdSecurityFrameCounter,
                                                               gpdKey,
                                                               assignedAlias,
                                                               groupcastRadius);
        break;
      }
    case ZCL_GP_PROXY_COMMISSIONING_MODE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t options;  // Ver.: since gp-1.0-09-5499-24
        uint16_t commissioningWindow;  // Ver.: since gp-1.0-15-02014-011
        uint8_t channel;  // Ver.: since gp-1.0-09-5499-24
        // Command is not a fixed length
        if ( ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          options = 0xFF;
        } else {
          options = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( !( (options & 0x02) == 0x02) || ( cmd->bufLen < payloadOffset + 2u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x02) == 0x02
          // - it is present only in versions higher than: gp-1.0-15-02014-011
          commissioningWindow = 0xFFFF;
        } else {
          commissioningWindow = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 2u;
        }
        if ( !( (options & 0x10) == 0x10) || ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x10) == 0x10
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          channel = 0xFF;
        } else {
          channel = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        }
        wasHandled = emberAfGreenPowerClusterGpProxyCommissioningModeCallback(options,
                                                                              commissioningWindow,
                                                                              channel);
        break;
      }
    case ZCL_GP_RESPONSE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t options;  // Ver.: since gp-1.0-09-5499-24
        uint16_t tempMasterShortAddress;  // Ver.: since gp-1.0-09-5499-24
        uint8_t tempMasterTxChannel;  // Ver.: since gp-1.0-09-5499-24
        uint32_t gpdSrcId;  // Ver.: since gp-1.0-09-5499-24
        uint8_t* gpdIeee;  // Ver.: since gp-1.0-09-5499-24
        uint8_t endpoint;  // Ver.: always
        uint8_t gpdCommandId;  // Ver.: since gp-1.0-09-5499-24
        uint8_t* gpdCommandPayload;  // Ver.: always
        // Command is not a fixed length
        if ( ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          options = 0xFF;
        } else {
          options = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( ( cmd->bufLen < payloadOffset + 2u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          tempMasterShortAddress = 0xFFFF;
        } else {
          tempMasterShortAddress = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 2u;
        }
        if ( ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          tempMasterTxChannel = 0xFF;
        } else {
          tempMasterTxChannel = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( !( (options & 0x07) == 0x00) || ( cmd->bufLen < payloadOffset + 4u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x07) == 0x00
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdSrcId = 0xFFFFFFFF;
        } else {
          gpdSrcId = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 4u;
        }
        if ( !( (options & 0x07) == 0x02) || ( cmd->bufLen < payloadOffset + 8u)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x07) == 0x02
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdIeee = NULL;
        } else {
          gpdIeee = cmd->buffer + payloadOffset;
          payloadOffset += 8u;
        }
        if ( !( (options & 0x07) == 0x02)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x07) == 0x02
          endpoint = 0xFF;
        } else {
          endpoint = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: gp-1.0-09-5499-24
          gpdCommandId = 0xFF;
        } else {
          gpdCommandId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if (cmd->bufLen < payloadOffset + emberAfStringLength(cmd->buffer + payloadOffset) + 1u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        gpdCommandPayload = emberAfGetString(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfGreenPowerClusterGpResponseCallback(options,
                                                                tempMasterShortAddress,
                                                                tempMasterTxChannel,
                                                                gpdSrcId,
                                                                gpdIeee,
                                                                endpoint,
                                                                gpdCommandId,
                                                                gpdCommandPayload);
        break;
      }
    case ZCL_GP_SINK_TABLE_RESPONSE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t status;  // Ver.: always
        uint8_t totalNumberofNonEmptySinkTableEntries;  // Ver.: always
        uint8_t startIndex;  // Ver.: always
        uint8_t sinkTableEntriesCount;  // Ver.: always
        uint8_t* sinkTableEntries;  // Ver.: always
        // Command is fixed length: 4
        if (cmd->bufLen < payloadOffset + 4u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        status = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        totalNumberofNonEmptySinkTableEntries = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        startIndex = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        sinkTableEntriesCount = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        sinkTableEntries = cmd->buffer + payloadOffset;
        wasHandled = emberAfGreenPowerClusterGpSinkTableResponseCallback(status,
                                                                         totalNumberofNonEmptySinkTableEntries,
                                                                         startIndex,
                                                                         sinkTableEntriesCount,
                                                                         sinkTableEntries);
        break;
      }
    case ZCL_GP_PROXY_TABLE_REQUEST_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t options;  // Ver.: always
        uint32_t gpdSrcId;  // Ver.: always
        uint8_t* gpdIeee;  // Ver.: always
        uint8_t endpoint;  // Ver.: always
        uint8_t index;  // Ver.: always
        // Command is not a fixed length
        if (cmd->bufLen < payloadOffset + 1u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        options = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        if ( !( ((options & 0x18) == 0x00) && ((options & 0x07) == 0x00))) {
          // Argument is not always present:
          // - it is conditionally present based on expression: ((options & 0x18) == 0x00) && ((options & 0x07) == 0x00)
          gpdSrcId = 0xFFFFFFFF;
        } else {
          gpdSrcId = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 4u;
        }
        if ( !( ((options & 0x18) == 0x00) && ((options & 0x07) == 0x02))) {
          // Argument is not always present:
          // - it is conditionally present based on expression: ((options & 0x18) == 0x00) && ((options & 0x07) == 0x02)
          gpdIeee = NULL;
        } else {
          gpdIeee = cmd->buffer + payloadOffset;
          payloadOffset += 8u;
        }
        if ( !( (options & 0x07) == 0x02)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x07) == 0x02
          endpoint = 0xFF;
        } else {
          endpoint = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( !( (options & 0x18) == 0x08)) {
          // Argument is not always present:
          // - it is conditionally present based on expression: (options & 0x18) == 0x08
          index = 0xFF;
        } else {
          index = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        }
        wasHandled = emberAfGreenPowerClusterGpProxyTableRequestCallback(options,
                                                                         gpdSrcId,
                                                                         gpdIeee,
                                                                         endpoint,
                                                                         index);
        break;
      }
    default:
      {
        // Unrecognized command ID, error status will apply.
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: IAS Zone, client
EmberAfStatus emberAfIasZoneClusterClientCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_ZONE_STATUS_CHANGE_NOTIFICATION_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t zoneStatus;  // Ver.: always
        uint8_t extendedStatus;  // Ver.: always
        uint8_t zoneId;  // Ver.: since ha-1.2-05-3520-29
        uint16_t delay;  // Ver.: since ha-1.2-05-3520-29
        // Command is not a fixed length
        if (cmd->bufLen < payloadOffset + 2u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        zoneStatus = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2u;
        if (cmd->bufLen < payloadOffset + 1u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        extendedStatus = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        if ( ( cmd->bufLen < payloadOffset + 1u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: ha-1.2-05-3520-29
          zoneId = 0xFF;
        } else {
          zoneId = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
          payloadOffset += 1u;
        }
        if ( ( cmd->bufLen < payloadOffset + 2u)) {
          // Argument is not always present:
          // - it is present only in versions higher than: ha-1.2-05-3520-29
          delay = 0xFFFF;
        } else {
          delay = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        }
        wasHandled = emberAfIasZoneClusterZoneStatusChangeNotificationCallback(zoneStatus,
                                                                               extendedStatus,
                                                                               zoneId,
                                                                               delay);
        break;
      }
    case ZCL_ZONE_ENROLL_REQUEST_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint16_t zoneType;  // Ver.: always
        uint16_t manufacturerCode;  // Ver.: always
        // Command is fixed length: 4
        if (cmd->bufLen < payloadOffset + 4u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        zoneType = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 2u;
        manufacturerCode = emberAfGetInt16u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfIasZoneClusterZoneEnrollRequestCallback(zoneType,
                                                                    manufacturerCode);
        break;
      }
    default:
      {
        // Unrecognized command ID, error status will apply.
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}

// Cluster: Simple Metering, client
EmberAfStatus emberAfSimpleMeteringClusterClientCommandParse(EmberAfClusterCommand *cmd)
{
  bool wasHandled = false;
  if (!cmd->mfgSpecific) {
    switch (cmd->commandId) {
    case ZCL_GET_PROFILE_RESPONSE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint32_t endTime;  // Ver.: always
        uint8_t status;  // Ver.: always
        uint8_t profileIntervalPeriod;  // Ver.: always
        uint8_t numberOfPeriodsDelivered;  // Ver.: always
        uint8_t* intervals;  // Ver.: always
        // Command is fixed length: 7
        if (cmd->bufLen < payloadOffset + 7u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        endTime = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 4u;
        status = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        profileIntervalPeriod = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        numberOfPeriodsDelivered = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        intervals = cmd->buffer + payloadOffset;
        wasHandled = emberAfSimpleMeteringClusterGetProfileResponseCallback(endTime,
                                                                            status,
                                                                            profileIntervalPeriod,
                                                                            numberOfPeriodsDelivered,
                                                                            intervals);
        break;
      }
    case ZCL_REQUEST_MIRROR_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfSimpleMeteringClusterRequestMirrorCallback();
        break;
      }
    case ZCL_REMOVE_MIRROR_COMMAND_ID:
      {
        // Command is fixed length: 0
        wasHandled = emberAfSimpleMeteringClusterRemoveMirrorCallback();
        break;
      }
    case ZCL_REQUEST_FAST_POLL_MODE_RESPONSE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint8_t appliedUpdatePeriod;  // Ver.: always
        uint32_t fastPollModeEndtime;  // Ver.: always
        // Command is fixed length: 5
        if (cmd->bufLen < payloadOffset + 5u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        appliedUpdatePeriod = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 1u;
        fastPollModeEndtime = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfSimpleMeteringClusterRequestFastPollModeResponseCallback(appliedUpdatePeriod,
                                                                                     fastPollModeEndtime);
        break;
      }
    case ZCL_SUPPLY_STATUS_RESPONSE_COMMAND_ID:
      {
        uint16_t payloadOffset = cmd->payloadStartIndex;
        uint32_t providerId;  // Ver.: always
        uint32_t issuerEventId;  // Ver.: always
        uint32_t implementationDateTime;  // Ver.: always
        uint8_t supplyStatus;  // Ver.: always
        // Command is fixed length: 13
        if (cmd->bufLen < payloadOffset + 13u) { return EMBER_ZCL_STATUS_MALFORMED_COMMAND; }
        providerId = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 4u;
        issuerEventId = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 4u;
        implementationDateTime = emberAfGetInt32u(cmd->buffer, payloadOffset, cmd->bufLen);
        payloadOffset += 4u;
        supplyStatus = emberAfGetInt8u(cmd->buffer, payloadOffset, cmd->bufLen);
        wasHandled = emberAfSimpleMeteringClusterSupplyStatusResponseCallback(providerId,
                                                                              issuerEventId,
                                                                              implementationDateTime,
                                                                              supplyStatus);
        break;
      }
    default:
      {
        // Unrecognized command ID, error status will apply.
        break;
      }
    }
  }
  return status(wasHandled, true, cmd->mfgSpecific);
}
