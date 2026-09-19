# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_Timer/default.cmf"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_Timer/default.hex"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_Timer/default.hxl"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_Timer/default.mum"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_Timer/default.o"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_Timer/default.sdb"
  "/home/spheal/git/ov/avrkurs/Session2-LF/out/Session2_Timer/default.sym"
  )
endif()
