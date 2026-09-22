# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/august/Git/avrkurs/Session3/ADC-OLED.X/out/Session3_ADC-OLED/default.cmf"
  "/home/august/Git/avrkurs/Session3/ADC-OLED.X/out/Session3_ADC-OLED/default.hex"
  "/home/august/Git/avrkurs/Session3/ADC-OLED.X/out/Session3_ADC-OLED/default.hxl"
  "/home/august/Git/avrkurs/Session3/ADC-OLED.X/out/Session3_ADC-OLED/default.mum"
  "/home/august/Git/avrkurs/Session3/ADC-OLED.X/out/Session3_ADC-OLED/default.o"
  "/home/august/Git/avrkurs/Session3/ADC-OLED.X/out/Session3_ADC-OLED/default.sdb"
  "/home/august/Git/avrkurs/Session3/ADC-OLED.X/out/Session3_ADC-OLED/default.sym"
  )
endif()
