PRODUCT_MODEL := Tinker Board 2 Customized for Udemy

DEVICE_PACKAGE_OVERLAYS += device/task4/overlays

BOARD_SEPOLICY_DIRS += device/task4/sepolicy \
                       device/task4/sepolicy/example_service \
                       device/task4/sepolicy/temperatureDevice_service \

PRODUCT_PACKAGES += service \
                    example_service \
                    temperatureDevice_service \

DEVICE_MANIFEST_FILE += device/task4/manifests/manifest.xml

DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += device/task4/manifests/framework_compatibility_matrix.xml

# mytarget:
# 	@echo "Building my target"
# 	cp non_existing_file.txt output_directory/

