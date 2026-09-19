# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_PWM/default.cmf"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_PWM/default.hex"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_PWM/default.hxl"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_PWM/default.mum"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_PWM/default.o"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_PWM/default.sdb"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_PWM/default.sym"
  )
endif()
