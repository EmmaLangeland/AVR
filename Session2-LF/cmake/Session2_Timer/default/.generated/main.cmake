include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Session2_Timer_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Session2_Timer_default_default_XC8_FILE_TYPE_assemble)
add_library(Session2_Timer_default_default_XC8_assemble OBJECT ${Session2_Timer_default_default_XC8_FILE_TYPE_assemble})
    Session2_Timer_default_default_XC8_assemble_rule(Session2_Timer_default_default_XC8_assemble)
    list(APPEND Session2_Timer_default_library_list "$<TARGET_OBJECTS:Session2_Timer_default_default_XC8_assemble>")

endif()

# Handle files with suffix S, for group default-XC8
if(Session2_Timer_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Session2_Timer_default_default_XC8_assemblePreprocess OBJECT ${Session2_Timer_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Session2_Timer_default_default_XC8_assemblePreprocess_rule(Session2_Timer_default_default_XC8_assemblePreprocess)
    list(APPEND Session2_Timer_default_library_list "$<TARGET_OBJECTS:Session2_Timer_default_default_XC8_assemblePreprocess>")

endif()

# Handle files with suffix [cC], for group default-XC8
if(Session2_Timer_default_default_XC8_FILE_TYPE_compile)
add_library(Session2_Timer_default_default_XC8_compile OBJECT ${Session2_Timer_default_default_XC8_FILE_TYPE_compile})
    Session2_Timer_default_default_XC8_compile_rule(Session2_Timer_default_default_XC8_compile)
    list(APPEND Session2_Timer_default_library_list "$<TARGET_OBJECTS:Session2_Timer_default_default_XC8_compile>")

endif()

# Handle files with suffix elf, for group default-XC8
if(Session2_Timer_default_default_XC8_FILE_TYPE_objcopy_avr)
add_library(Session2_Timer_default_default_XC8_objcopy_avr OBJECT ${Session2_Timer_default_default_XC8_FILE_TYPE_objcopy_avr})
    Session2_Timer_default_default_XC8_objcopy_avr_rule(Session2_Timer_default_default_XC8_objcopy_avr)
    list(APPEND Session2_Timer_default_library_list "$<TARGET_OBJECTS:Session2_Timer_default_default_XC8_objcopy_avr>")

endif()


# Main target for this project
add_executable(Session2_Timer_default_image_K_ncvKvl ${Session2_Timer_default_library_list})

set_target_properties(Session2_Timer_default_image_K_ncvKvl PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${Session2_Timer_default_output_dir}")
target_link_libraries(Session2_Timer_default_image_K_ncvKvl PRIVATE ${Session2_Timer_default_default_XC8_FILE_TYPE_link})
# Add the link options from the rule file.
Session2_Timer_default_link_rule( Session2_Timer_default_image_K_ncvKvl)


#Add objcopy steps
Session2_Timer_default_objcopy_avr_rule(Session2_Timer_default_image_K_ncvKvl)

