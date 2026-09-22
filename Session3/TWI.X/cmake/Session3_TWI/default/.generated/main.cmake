include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Session3_TWI_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Session3_TWI_default_default_XC8_FILE_TYPE_assemble)
add_library(Session3_TWI_default_default_XC8_assemble OBJECT ${Session3_TWI_default_default_XC8_FILE_TYPE_assemble})
    Session3_TWI_default_default_XC8_assemble_rule(Session3_TWI_default_default_XC8_assemble)
    list(APPEND Session3_TWI_default_library_list "$<TARGET_OBJECTS:Session3_TWI_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(Session3_TWI_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Session3_TWI_default_default_XC8_assemblePreprocess OBJECT ${Session3_TWI_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Session3_TWI_default_default_XC8_assemblePreprocess_rule(Session3_TWI_default_default_XC8_assemblePreprocess)
    list(APPEND Session3_TWI_default_library_list "$<TARGET_OBJECTS:Session3_TWI_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(Session3_TWI_default_default_XC8_FILE_TYPE_compile)
add_library(Session3_TWI_default_default_XC8_compile OBJECT ${Session3_TWI_default_default_XC8_FILE_TYPE_compile})
    Session3_TWI_default_default_XC8_compile_rule(Session3_TWI_default_default_XC8_compile)
    list(APPEND Session3_TWI_default_library_list "$<TARGET_OBJECTS:Session3_TWI_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(Session3_TWI_default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(Session3_TWI_default_default_XC8_objcopy_avr OBJECT ${Session3_TWI_default_default_XC8_FILE_TYPE_objcopy_avr})
    Session3_TWI_default_default_XC8_objcopy_avr_rule(Session3_TWI_default_default_XC8_objcopy_avr)
    list(APPEND Session3_TWI_default_library_list "$<TARGET_OBJECTS:Session3_TWI_default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(Session3_TWI_default_image_Ve6e4wjv ${Session3_TWI_default_library_list})

set_target_properties(Session3_TWI_default_image_Ve6e4wjv PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${Session3_TWI_default_output_dir}")
target_link_libraries(Session3_TWI_default_image_Ve6e4wjv PRIVATE ${Session3_TWI_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
Session3_TWI_default_link_rule( Session3_TWI_default_image_Ve6e4wjv)


#Add objcopy steps
Session3_TWI_default_objcopy_avr_rule(Session3_TWI_default_image_Ve6e4wjv)

