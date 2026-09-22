include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Session2_Timer_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Session2_Timer_default_default_XC8_FILE_TYPE_assemble)
add_library(Session2_Timer_default_default_XC8_assemble OBJECT ${Session2_Timer_default_default_XC8_FILE_TYPE_assemble})
    Session2_Timer_default_default_XC8_assemble_rule(Session2_Timer_default_default_XC8_assemble)
    list(APPEND Session2_Timer_default_library_list "$<TARGET_OBJECTS:Session2_Timer_default_default_XC8_assemble>")
<<<<<<< HEAD
=======

>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
endif()

# Handle files with suffix S, for group default-XC8
if(Session2_Timer_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Session2_Timer_default_default_XC8_assemblePreprocess OBJECT ${Session2_Timer_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Session2_Timer_default_default_XC8_assemblePreprocess_rule(Session2_Timer_default_default_XC8_assemblePreprocess)
    list(APPEND Session2_Timer_default_library_list "$<TARGET_OBJECTS:Session2_Timer_default_default_XC8_assemblePreprocess>")
<<<<<<< HEAD
=======

>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
endif()

# Handle files with suffix [cC], for group default-XC8
if(Session2_Timer_default_default_XC8_FILE_TYPE_compile)
add_library(Session2_Timer_default_default_XC8_compile OBJECT ${Session2_Timer_default_default_XC8_FILE_TYPE_compile})
    Session2_Timer_default_default_XC8_compile_rule(Session2_Timer_default_default_XC8_compile)
    list(APPEND Session2_Timer_default_library_list "$<TARGET_OBJECTS:Session2_Timer_default_default_XC8_compile>")
<<<<<<< HEAD
endif()

add_executable(${Session2_Timer_default_image_name} ${Session2_Timer_default_library_list})

target_link_libraries(${Session2_Timer_default_image_name} PRIVATE ${Session2_Timer_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
Session2_Timer_default_link_rule(${Session2_Timer_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${Session2_Timer_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${Session2_Timer_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${Session2_Timer_default_image_name} ${Session2_Timer_default_output_dir}/${Session2_Timer_default_original_image_name}
                    BYPRODUCTS ${Session2_Timer_default_output_dir}/${Session2_Timer_default_original_image_name})
=======

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

>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
