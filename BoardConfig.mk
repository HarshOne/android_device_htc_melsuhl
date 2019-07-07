#
# Copyright (C) 2015 The CyanogenMod Project
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

#
# This file sets variables that control the way modules are built
# thorughout the system. It should not be used to conditionally
# disable makefiles (the proper mechanism to control what gets
# included in a build is to use PRODUCT_PACKAGES in a product
# definition file).
#

# WARNING: This line must come *before* including the proprietary
# variant, so that it gets overwritten by the parent (which goes
# against the traditional rules of inheritance).

# Inherit from common melsuhl-common
-include device/htc/melsuhl-common/BoardConfigCommon.mk

# Model Ids
# 0P6B90000 - International

# Assert
TARGET_OTA_ASSERT_DEVICE := htc_melsuhl,melsuhl

# Kernel
TARGET_KERNEL_CONFIG := melstuhl_defconfig

# Bluetooth
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := device/htc/melsuhl/bluetooth

# RIL
BOARD_RIL_CLASS := ../../../device/htc/melsuhl/ril
TARGET_NEEDS_GCC_LIBC := true
TARGET_NEEDS_GCC_LIBRIL := true

# Partitions
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1073741824
BOARD_USERDATAIMAGE_PARTITION_SIZE := 13153337344

# Vendor Init
TARGET_INIT_VENDOR_LIB := libinit_melsuhl
TARGET_RECOVERY_DEVICE_MODULES := libinit_melsuhl

# Inherit from the proprietary version
-include vendor/htc/melsuhl/BoardConfigVendor.mk
