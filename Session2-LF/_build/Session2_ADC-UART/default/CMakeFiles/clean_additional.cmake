# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_ADC-UART/default.cmf"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_ADC-UART/default.hex"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_ADC-UART/default.hxl"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_ADC-UART/default.mum"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_ADC-UART/default.o"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_ADC-UART/default.sdb"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_ADC-UART/default.sym"
  )
endif()
