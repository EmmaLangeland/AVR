# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "/home/august/Git/avrkurs/Session3/TWI.X/out/Session3_TWI/default.cmf"
  "/home/august/Git/avrkurs/Session3/TWI.X/out/Session3_TWI/default.hex"
  "/home/august/Git/avrkurs/Session3/TWI.X/out/Session3_TWI/default.hxl"
  "/home/august/Git/avrkurs/Session3/TWI.X/out/Session3_TWI/default.mum"
  "/home/august/Git/avrkurs/Session3/TWI.X/out/Session3_TWI/default.o"
  "/home/august/Git/avrkurs/Session3/TWI.X/out/Session3_TWI/default.sdb"
  "/home/august/Git/avrkurs/Session3/TWI.X/out/Session3_TWI/default.sym"
  )
endif()
