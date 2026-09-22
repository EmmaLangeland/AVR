# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_PWM/default.cmf"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_PWM/default.hex"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_PWM/default.hxl"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_PWM/default.mum"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_PWM/default.o"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_PWM/default.sdb"
  "/home/august/Git/avrkurs/Session2-LF/out/Session2_PWM/default.sym"
  )
endif()
