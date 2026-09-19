include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Session2_ADC_UART_default_library_list )

# Handle files with suffix (s|as|asm|AS|ASM|As|aS|Asm), for group default-XC8
if(Session2_ADC_UART_default_default_XC8_FILE_TYPE_assemble)
add_library(Session2_ADC_UART_default_default_XC8_assemble OBJECT ${Session2_ADC_UART_default_default_XC8_FILE_TYPE_assemble})
    Session2_ADC_UART_default_default_XC8_assemble_rule(Session2_ADC_UART_default_default_XC8_assemble)
    list(APPEND Session2_ADC_UART_default_library_list "$<TARGET_OBJECTS:Session2_ADC_UART_default_default_XC8_assemble>")
endif()

# Handle files with suffix S, for group default-XC8
if(Session2_ADC_UART_default_default_XC8_FILE_TYPE_assemblePreprocess)
add_library(Session2_ADC_UART_default_default_XC8_assemblePreprocess OBJECT ${Session2_ADC_UART_default_default_XC8_FILE_TYPE_assemblePreprocess})
    Session2_ADC_UART_default_default_XC8_assemblePreprocess_rule(Session2_ADC_UART_default_default_XC8_assemblePreprocess)
    list(APPEND Session2_ADC_UART_default_library_list "$<TARGET_OBJECTS:Session2_ADC_UART_default_default_XC8_assemblePreprocess>")
endif()

# Handle files with suffix [cC], for group default-XC8
if(Session2_ADC_UART_default_default_XC8_FILE_TYPE_compile)
add_library(Session2_ADC_UART_default_default_XC8_compile OBJECT ${Session2_ADC_UART_default_default_XC8_FILE_TYPE_compile})
    Session2_ADC_UART_default_default_XC8_compile_rule(Session2_ADC_UART_default_default_XC8_compile)
    list(APPEND Session2_ADC_UART_default_library_list "$<TARGET_OBJECTS:Session2_ADC_UART_default_default_XC8_compile>")
endif()

add_executable(${Session2_ADC_UART_default_image_name} ${Session2_ADC_UART_default_library_list})

target_link_libraries(${Session2_ADC_UART_default_image_name} PRIVATE ${Session2_ADC_UART_default_default_XC8_FILE_TYPE_link})

# Add the link options from the rule file.
Session2_ADC_UART_default_link_rule(${Session2_ADC_UART_default_image_name})


# Post build target to copy built file to the output directory.
add_custom_command(TARGET ${Session2_ADC_UART_default_image_name} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E make_directory ${Session2_ADC_UART_default_output_dir}
                    COMMAND ${CMAKE_COMMAND} -E copy ${Session2_ADC_UART_default_image_name} ${Session2_ADC_UART_default_output_dir}/${Session2_ADC_UART_default_original_image_name}
                    BYPRODUCTS ${Session2_ADC_UART_default_output_dir}/${Session2_ADC_UART_default_original_image_name})
