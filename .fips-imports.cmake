#
# generated by 'fips gen', don't edit, don't add to version control!
#
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glfw/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glfw/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glfw/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glfw/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glfw/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glfw/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glfw/glfw/include")
macro(fips_import_fips_glfw_glfw3)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glfw/." "fips-glfw_glfw3")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_fips_glfw_glfw3()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glm/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glm/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glm/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glm/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glm/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glm/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-glm/glm")
add_definitions(-DGLM_FORCE_RADIANS=1)
add_definitions(-DGLM_FORCE_CTOR_INIT=1)
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-libcurl/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-libcurl/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-libcurl/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-libcurl/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-libcurl/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-libcurl/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-libcurl")
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-remotery/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-remotery/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-remotery/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-remotery/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-remotery/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-remotery/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-remotery/Remotery/lib")
macro(fips_import_fips_remotery_Remotery)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-remotery/." "fips-remotery_Remotery")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_fips_remotery_Remotery()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-unittestpp/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-unittestpp/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-unittestpp/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-unittestpp/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-unittestpp/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-unittestpp/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-unittestpp")
macro(fips_import_fips_unittestpp_unittestpp)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-unittestpp/UnitTest++" "fips-unittestpp_unittestpp")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_fips_unittestpp_unittestpp()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-vld/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-vld/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-vld/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-vld/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-vld/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-vld/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-vld")
macro(fips_import_fips_vld_vld)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-vld/." "fips-vld_vld")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_fips_vld_vld()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-zlib/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-zlib/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-zlib/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-zlib/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-zlib/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-zlib/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-zlib")
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-zlib/zlib")
macro(fips_import_fips_zlib_zlib)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-zlib/zlib" "fips-zlib_zlib")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_fips_zlib_zlib()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/gliml/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/gliml/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/gliml/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/gliml/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/gliml/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/gliml/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/gliml")
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-imgui/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-imgui/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-imgui/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-imgui/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-imgui/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-imgui/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-imgui/imgui")
macro(fips_import_fips_imgui_imgui)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-imgui/." "fips-imgui_imgui")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_fips_imgui_imgui()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code")
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules")
macro(fips_import_oryol_Core)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules/Core" "oryol_Core")
    set(FIPS_IMPORT)
endmacro()
macro(fips_import_oryol_Gfx)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules/Gfx" "oryol_Gfx")
    set(FIPS_IMPORT)
endmacro()
macro(fips_import_oryol_Resource)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules/Resource" "oryol_Resource")
    set(FIPS_IMPORT)
endmacro()
macro(fips_import_oryol_Assets)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules/Assets" "oryol_Assets")
    set(FIPS_IMPORT)
endmacro()
macro(fips_import_oryol_HttpFS)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules/HttpFS" "oryol_HttpFS")
    set(FIPS_IMPORT)
endmacro()
macro(fips_import_oryol_Dbg)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules/Dbg" "oryol_Dbg")
    set(FIPS_IMPORT)
endmacro()
macro(fips_import_oryol_LocalFS)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules/LocalFS" "oryol_LocalFS")
    set(FIPS_IMPORT)
endmacro()
macro(fips_import_oryol_IO)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules/IO" "oryol_IO")
    set(FIPS_IMPORT)
endmacro()
macro(fips_import_oryol_Input)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol/code/Modules/Input" "oryol_Input")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports/oryol")
    fips_import_oryol_Core()
    fips_import_oryol_Gfx()
    fips_import_oryol_Resource()
    fips_import_oryol_Assets()
    fips_import_oryol_HttpFS()
    fips_import_oryol_Dbg()
    fips_import_oryol_LocalFS()
    fips_import_oryol_IO()
    fips_import_oryol_Input()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-turbobadger/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-turbobadger/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-turbobadger/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-turbobadger/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-turbobadger/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-turbobadger/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-turbobadger/turbobadger/src/tb")
macro(fips_import_fips_turbobadger_turbobadger)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-turbobadger/." "fips-turbobadger_turbobadger")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_fips_turbobadger_turbobadger()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-nuklear/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-nuklear/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-nuklear/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-nuklear/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-nuklear/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-nuklear/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-nuklear")
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-bullet/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-bullet/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-bullet/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-bullet/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-bullet/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-bullet/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-bullet/bullet3/src")
macro(fips_import_fips_bullet_Bullet)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-bullet/." "fips-bullet_Bullet")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_fips_bullet_Bullet()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-soloud/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-soloud/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-soloud/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-soloud/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-soloud/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-soloud/lib/${FIPS_PLATFORM_NAME}")
endif()
macro(fips_import_fips_soloud_soloud)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/fips-soloud/." "fips-soloud_soloud")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_fips_soloud_soloud()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-animation/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-animation/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-animation/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-animation/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-animation/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-animation/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-animation/src")
macro(fips_import_oryol_animation_Anim)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-animation/src/Anim" "oryol-animation_Anim")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_oryol_animation_Anim()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-fileformats/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-fileformats/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-fileformats/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-fileformats/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-fileformats/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-fileformats/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-fileformats")
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-imgui/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-imgui/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-imgui/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-imgui/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-imgui/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-imgui/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-imgui/src")
macro(fips_import_oryol_imgui_IMUI)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-imgui/src/IMUI" "oryol-imgui_IMUI")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_oryol_imgui_IMUI()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-nuklear/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-nuklear/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-nuklear/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-nuklear/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-nuklear/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-nuklear/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-nuklear/src")
macro(fips_import_oryol_nuklear_NKUI)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-nuklear/src/NKUI" "oryol-nuklear_NKUI")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_oryol_nuklear_NKUI()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-sound/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-sound/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-sound/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-sound/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-sound/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-sound/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-sound/src")
macro(fips_import_oryol_sound_Sound)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-sound/src/Sound" "oryol-sound_Sound")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_oryol_sound_Sound()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-tbui/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-tbui/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-tbui/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-tbui/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-tbui/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-tbui/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-tbui/src")
macro(fips_import_oryol_tbui_TBUI)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-tbui/src/TBUI" "oryol-tbui_TBUI")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_oryol_tbui_TBUI()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/cjson/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/cjson/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/cjson/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/cjson/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/cjson/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/cjson/lib/${FIPS_PLATFORM_NAME}")
endif()
include_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/cjson/cJSON")
macro(fips_import_cjson_cjson)
    set(FIPS_IMPORT 1)
    add_subdirectory("/home/sipax/Skola/S0012D-Spelmotorarkitektur/cjson/." "cjson_cjson")
    set(FIPS_IMPORT)
endmacro()
if (FIPS_AUTO_IMPORT)
    fips_ide_group("Imports")
    fips_import_cjson_cjson()
    fips_ide_group("")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-samples/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-samples/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-samples/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-samples/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-samples/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/oryol-samples/lib/${FIPS_PLATFORM_NAME}")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/pybind11/fips-include.cmake")
    include("/home/sipax/Skola/S0012D-Spelmotorarkitektur/pybind11/fips-include.cmake")
elseif (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/pybind11/fips-files/include.cmake")
    include ("/home/sipax/Skola/S0012D-Spelmotorarkitektur/pybind11/fips-files/include.cmake")
endif()
if (EXISTS "/home/sipax/Skola/S0012D-Spelmotorarkitektur/pybind11/lib/${FIPS_PLATFORM_NAME}")
    link_directories("/home/sipax/Skola/S0012D-Spelmotorarkitektur/pybind11/lib/${FIPS_PLATFORM_NAME}")
endif()
