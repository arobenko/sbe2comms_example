set (ALL_MESSAGES_LIB "all_messages")

######################################################################

function (cc_plugin_all_messages)
    set (name "${ALL_MESSAGES_LIB}")

    set (src
        field.cpp
        message/Car.cpp
    )

    add_library (${name} STATIC ${src})
    target_link_libraries (${name} ${CC_PLUGIN_LIBRARIES})
    qt5_use_modules(${name} Core)
endfunction()

######################################################################

function (cc_plugin variant)
    set (name "extension_${variant}")

    set (meta_file "${CMAKE_CURRENT_SOURCE_DIR}/plugin_${variant}.json")
    set (stamp_file "${CMAKE_CURRENT_BINARY_DIR}/plubin_${variant}_refresh_stamp.txt")

    if ((NOT EXISTS ${stamp_file}) OR (${meta_file} IS_NEWER_THAN ${stamp_file}))
        execute_process(
            COMMAND ${CMAKE_COMMAND} -E touch ${CMAKE_CURRENT_SOURCE_DIR}/${variant}Plugin.h)

        execute_process(
            COMMAND ${CMAKE_COMMAND} -E touch ${stamp_file})
    endif ()

    set (src
        ${variant}TransportMessage.cpp
        ${variant}Protocol.cpp
        ${variant}Plugin.cpp
    )

    set (hdr
        ${variant}Plugin.h
    )

    qt5_wrap_cpp(moc ${hdr})

    add_library (${name} SHARED ${src} ${moc})
    target_link_libraries (${name} ${ALL_MESSAGES_LIB} ${CC_PLUGIN_LIBRARIES})
    qt5_use_modules (${name} Core)
    install (
        TARGETS ${name}
        DESTINATION ${PLUGIN_INSTALL_DIR})

    if (OPT_FULL_SOLUTION)
        add_dependencies(${name} ${CC_EXTERNAL_TGT})
    endif ()
endfunction()

######################################################################

if (NOT Qt5Core_FOUND)
    message (WARNING "Can NOT compile protocol plugin due to missing QT5 Core library")
    return ()
endif ()

if (CMAKE_COMPILER_IS_GNUCC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-backtrace-limit=0")
endif ()

cc_plugin_all_messages()
cc_plugin ("MessageHeaderFrame")
cc_plugin ("OpenFramingHeaderFrame")

FILE(GLOB_RECURSE plugin.headers "*.h")
add_custom_target(cc_plugin.headers SOURCES ${plugin.headers})

