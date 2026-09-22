# The following variables contains the files used by the different stages of the build process.
set(Session2_Timer_default_default_XC8_FILE_TYPE_assemble)
set_source_files_properties(${Session2_Timer_default_default_XC8_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)
set(Session2_Timer_default_default_XC8_FILE_TYPE_assemblePreprocess)
set_source_files_properties(${Session2_Timer_default_default_XC8_FILE_TYPE_assemblePreprocess} PROPERTIES LANGUAGE ASM)
set(Session2_Timer_default_default_XC8_FILE_TYPE_compile "${CMAKE_CURRENT_SOURCE_DIR}/../../../Timer.X/main.c")
set_source_files_properties(${Session2_Timer_default_default_XC8_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(Session2_Timer_default_default_XC8_FILE_TYPE_link)

# The (internal) path to the resulting build image.
set(Session2_Timer_default_internal_image_name "${CMAKE_CURRENT_SOURCE_DIR}/../../../_build/Session2_Timer/default/default.elf")

# The name of the resulting image, including namespace for configuration.
set(Session2_Timer_default_image_name "Session2_Timer_default_default.elf")

# The name of the image, excluding the namespace for configuration.
set(Session2_Timer_default_original_image_name "default.elf")

# The output directory of the final image.
set(Session2_Timer_default_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/Session2_Timer")
