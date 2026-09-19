# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_ADC-UART/default.cmf"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_ADC-UART/default.hex"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_ADC-UART/default.hxl"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_ADC-UART/default.mum"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_ADC-UART/default.o"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_ADC-UART/default.sdb"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_ADC-UART/default.sym"
  )
endif()
