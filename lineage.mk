#
# Copyright (C) 2015-2016 The CyanogenMod Project
#               2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

# Get non-open-source specific aspects
$(call inherit-product-if-exists, vendor/htc/melsuhl/melsuhl-vendor.mk)
$(call inherit-product-if-exists, vendor/htc/melsuhl-common/melsuhl-common-vendor.mk)

# Inherit from melsuhl device
$(call inherit-product, device/htc/melsuhl/melsuhl.mk)

# Inherit from melsuhl-common
$(call inherit-product, device/htc/melsuhl-common/common.mk)

# Inherit some common Lineage stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Device identifier. This must come after all inclusions.
PRODUCT_NAME := lineage_melsuhl
PRODUCT_DEVICE := melsuhl
PRODUCT_BRAND := htc
PRODUCT_MODEL := melsuhl
PRODUCT_MANUFACTURER := HTC
