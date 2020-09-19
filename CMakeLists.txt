cmake_minimum_required(VERSION 3.17)
project(WebServer_mark)

set(CMAKE_CXX_STANDARD 14)

include_directories(code)
include_directories(code/buffer)
include_directories(code/config)
include_directories(code/http)
include_directories(code/log)
include_directories(code/pool)
include_directories(code/server)
include_directories(code/timer)
include_directories(resources)
include_directories(resources/css)
include_directories(resources/fonts)
include_directories(resources/images)
include_directories(resources/js)
include_directories(resources/video)

add_executable(WebServer_mark
        code/buffer/buffer.cpp
        code/buffer/buffer.h
        code/config/config.h
        code/http/httpconn.cpp
        code/http/httpconn.h
        code/http/httprequest.cpp
        code/http/httprequest.h
        code/http/httpresponse.cpp
        code/http/httpresponse.h
        code/log/blockqueue.h
        code/log/log.cpp
        code/log/log.h
        code/pool/sqlconnpool.cpp
        code/pool/sqlconnpool.h
        code/pool/sqlconnRAII.h
        code/pool/threadpool.h
        code/server/epoller.cpp
        code/server/epoller.h
        code/server/webserver.cpp
        code/server/webserver.h
        code/timer/heaptimer.cpp
        code/timer/heaptimer.h
        code/main.cpp
        resources/css/animate.css
        resources/css/bootstrap.min.css
        resources/css/font-awesome.min.css
        resources/css/magnific-popup.css
        resources/css/style.css
        resources/fonts/fontawesome-webfont.eot
        resources/fonts/fontawesome-webfont.svg
        resources/fonts/fontawesome-webfont.ttf
        resources/fonts/fontawesome-webfont.woff
        resources/fonts/fontawesome-webfont.woff2
        resources/fonts/FontAwesome.otf
        resources/images/favicon.ico
        resources/images/instagram-image1.jpg
        resources/images/instagram-image2.jpg
        resources/images/instagram-image3.jpg
        resources/images/instagram-image4.jpg
        resources/images/instagram-image5.jpg
        resources/images/profile-image.jpg
        resources/js/bootstrap.min.js
        resources/js/custom.js
        resources/js/jquery.js
        resources/js/jquery.magnific-popup.min.js
        resources/js/magnific-popup-options.js
        resources/js/smoothscroll.js
        resources/js/wow.min.js
        resources/video/xxx.mp4
        resources/400.html
        resources/403.html
        resources/404.html
        resources/405.html
        resources/error.html
        resources/index.html
        resources/login.html
        resources/picture.html
        resources/register.html
        resources/video.html
        resources/welcome.html)

# 链接mysql外部库
target_link_libraries(WebServer_mark libmysqlclient.so)
# 链接libpthread外部库
target_link_libraries(WebServer_mark libpthread.so)

#add_custom_target(WebServer_mark COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/resources ${CMAKE_CURRENT_SOURCE_DIR}/)
# copy_directory拷贝文件夹, copy拷贝文件
add_custom_command(TARGET WebServer_mark PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources/ $<TARGET_FILE_DIR:WebServer_mark>/resources)