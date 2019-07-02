/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void common_properties()
{
    property_set("rild.libargs", "-d /dev/smd0");
    property_set("ro.ril.hsdpa.category", "24");
    property_set("ro.ril.hsxpa", "4");
    property_set("ro.ril.disable.cpc", "1");
}

void cdma_properties(char const default_cdma_sub[], char const default_network[])
{
    property_set("ro.telephony.default_cdma_sub", default_cdma_sub);
    property_set("ro.telephony.default_network", default_network);
    property_set("telephony.lteOnCdmaDevice", "1");
    property_set("ro.ril.enable.sdr", "0");
    property_set("persist.radio.snapshot_enabled", "1");
    property_set("persist.radio.snapshot_timer", "22");
}

void gsm_properties(char const default_network[])
{
    property_set("ro.telephony.default_network", default_network);
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.ril.radio.svn", "1");
}

void vendor_load_properties()
{
    std::string platform;
    std::string bootmid;
    std::string device;

    platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    bootmid = property_get("ro.boot.mid");

    if (bootmid == "0P6B90000") {
        /* melsuhl */
        common_properties();
        gsm_properties("9");
        property_override("ro.product.model", "HTC One_M8 Eye");
        property_override("ro.build.fingerprint", "htc/melsuhl_htc_europe/htc_melsuhl:6.0.1/MMB29M/713780.1:user/release-keys");
        property_override("ro.build.description", "5.07.401.1 CL713780 release-keys");
        property_override("ro.product.device", "htc_melsuhl");
        property_override("ro.build.product", "htc_melsuhl");
    } else {
        /* melsuhl */
        common_properties();
        gsm_properties("9");
        property_override("ro.product.model", "HTC One_M8 Eye");
        property_override("ro.build.fingerprint", "htc/melsuhl_htc_europe/htc_melsuhl:6.0.1/MMB29M/713780.1:user/release-keys");
        property_override("ro.build.description", "5.07.401.1 CL713780 release-keys");
        property_override("ro.product.device", "htc_melsuhl");
        property_override("ro.build.product", "htc_melsuhl");
    }

    device = property_get("ro.product.device");
    ERROR("Found bootmid %s setting build properties for %s device\n", bootmid.c_str(), device.c_str());
}
