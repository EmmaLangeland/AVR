# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/august/Git/avrkurs/Session2-LF/Timer.X/out/Session2_Timer/default.cmf"
  "/home/august/Git/avrkurs/Session2-LF/Timer.X/out/Session2_Timer/default.hex"
  "/home/august/Git/avrkurs/Session2-LF/Timer.X/out/Session2_Timer/default.hxl"
  "/home/august/Git/avrkurs/Session2-LF/Timer.X/out/Session2_Timer/default.mum"
  "/home/august/Git/avrkurs/Session2-LF/Timer.X/out/Session2_Timer/default.o"
  "/home/august/Git/avrkurs/Session2-LF/Timer.X/out/Session2_Timer/default.sdb"
  "/home/august/Git/avrkurs/Session2-LF/Timer.X/out/Session2_Timer/default.sym"
  )
endif()
