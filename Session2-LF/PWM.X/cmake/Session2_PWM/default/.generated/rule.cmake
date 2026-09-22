# The following functions contains all the flags passed to the different build stages.

<<<<<<< HEAD
set(PACK_REPO_PATH "/home/august/.mchp_packs" CACHE PATH "Path to the root of a pack repository.")
=======
set(PACK_REPO_PATH "/home/sebgab/.mchp_packs" CACHE PATH "Path to the root of a pack repository.")
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c

function(Session2_PWM_default_default_XC8_assemble_rule target)
    set(options
        "-c"
        "${MP_EXTRA_AS_PRE}"
        "-mcpu=AVR128DB48"
<<<<<<< HEAD
        "-g"
        "-x"
        "assembler-with-cpp"
        "-mdfp=${PACK_REPO_PATH}/Microchip/AVR-Dx_DFP/2.3.272/xc8"
        "-Wl,--gc-sections"
        "-O0"
=======
        "-mdfp=${PACK_REPO_PATH}/Microchip/AVR-Dx_DFP/2.3.272/xc8"
        "-Wl,--gc-sections"
        "-O1"
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
        "-ffunction-sections"
        "-fdata-sections"
        "-fshort-enums"
        "-fno-common"
        "-funsigned-char"
        "-funsigned-bitfields"
        "-Wall"
        "-L${CMAKE_CURRENT_SOURCE_DIR}/../../.."
        "-gdwarf-3"
        "-mconst-data-in-progmem"
<<<<<<< HEAD
        "-mno-const-data-in-config-mapped-progmem"
        "-Wa,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1")
=======
        "-Wa,--defsym=__MPLAB_BUILD=1")
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__AVR128DB48__"
<<<<<<< HEAD
        PRIVATE "__DEBUG=1"
        PRIVATE "DEBUG"
=======
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
        PRIVATE "XPRJ_default=default")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(Session2_PWM_default_default_XC8_assemblePreprocess_rule target)
    set(options
        "-c"
        "${MP_EXTRA_AS_PRE}"
        "-mcpu=AVR128DB48"
<<<<<<< HEAD
        "-g"
=======
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
        "-x"
        "assembler-with-cpp"
        "-mdfp=${PACK_REPO_PATH}/Microchip/AVR-Dx_DFP/2.3.272/xc8"
        "-Wl,--gc-sections"
<<<<<<< HEAD
        "-O0"
=======
        "-O1"
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
        "-ffunction-sections"
        "-fdata-sections"
        "-fshort-enums"
        "-fno-common"
        "-funsigned-char"
        "-funsigned-bitfields"
        "-Wall"
        "-L${CMAKE_CURRENT_SOURCE_DIR}/../../.."
        "-gdwarf-3"
        "-mconst-data-in-progmem"
<<<<<<< HEAD
        "-mno-const-data-in-config-mapped-progmem"
        "-Wa,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1")
=======
        "-Wa,--defsym=__MPLAB_BUILD=1")
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__AVR128DB48__"
<<<<<<< HEAD
        PRIVATE "__DEBUG=1"
        PRIVATE "DEBUG"
=======
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
        PRIVATE "XPRJ_default=default")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(Session2_PWM_default_default_XC8_compile_rule target)
    set(options
        "-c"
        "${MP_EXTRA_CC_PRE}"
        "-mcpu=AVR128DB48"
        "-x"
        "c"
        "-mdfp=${PACK_REPO_PATH}/Microchip/AVR-Dx_DFP/2.3.272/xc8"
        "-Wl,--gc-sections"
<<<<<<< HEAD
        "-O0"
=======
        "-O1"
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
        "-ffunction-sections"
        "-fdata-sections"
        "-fshort-enums"
        "-fno-common"
        "-funsigned-char"
        "-funsigned-bitfields"
        "-Wall"
        "-L${CMAKE_CURRENT_SOURCE_DIR}/../../.."
        "-gdwarf-3"
<<<<<<< HEAD
        "-mconst-data-in-progmem"
        "-mno-const-data-in-config-mapped-progmem")
=======
        "-mconst-data-in-progmem")
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__AVR128DB48__"
<<<<<<< HEAD
        PRIVATE "__DEBUG=1"
        PRIVATE "DEBUG"
=======
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
        PRIVATE "XPRJ_default=default")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(Session2_PWM_default_link_rule target)
    set(options
        "-Wl,-Map=mem.map"
        "${MP_EXTRA_LD_PRE}"
        "-mcpu=AVR128DB48"
        "-Wl,--defsym=__MPLAB_BUILD=1"
        "-mdfp=${PACK_REPO_PATH}/Microchip/AVR-Dx_DFP/2.3.272/xc8"
        "-Wl,--gc-sections"
<<<<<<< HEAD
        "-O0"
=======
        "-O1"
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
        "-ffunction-sections"
        "-fdata-sections"
        "-fshort-enums"
        "-fno-common"
        "-funsigned-char"
        "-funsigned-bitfields"
        "-Wall"
        "-L${CMAKE_CURRENT_SOURCE_DIR}/../../.."
        "-gdwarf-3"
        "-mconst-data-in-progmem"
<<<<<<< HEAD
        "-mno-const-data-in-config-mapped-progmem"
        "-Wl,--memorysummary,memoryfile.xml"
        "-Wl,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1")
    list(REMOVE_ITEM options "")
    target_link_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__DEBUG=1"
        PRIVATE "XPRJ_default=default")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
function(Session2_PWM_default_objcopy_avr_rule target)
    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${OBJCOPY}
        ARGS -O ihex ${Session2_PWM_default_image_name} ${Session2_PWM_default_image_base_name}.hex
        WORKING_DIRECTORY ${Session2_PWM_default_output_dir})
endfunction()
=======
        "-Wl,--memorysummary,memoryfile.xml")
    list(REMOVE_ITEM options "")
    target_link_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target} PRIVATE "XPRJ_default=default")
    target_include_directories(${target} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../../..")
endfunction()
>>>>>>> a1370d1d27a3cdb330f7d8876be52095cd09e09c
