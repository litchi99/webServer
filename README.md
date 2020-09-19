# webServer
Coding by cpp in CLion, this project is used to learning how to build a static webServer.


## 报错处理
### 1. 在项目中使用MySQL
- ubuntu下安装环境包: `sudo apt-get install libmysqlclient-dev`
- 由于g++默认环境中未包含mysql.h库, 需要手动安装, 否则会抛出: mysql.h没有那个文件或目录
- 在CMakeLists.txt文件中添加链接信息`target_link_libraries(webServer libmysqlclient.so)`，第一个参数为项目名称
- 通过`sudo dpkg -l`查看mysql环境包的安装详情: `libmysqlclient-dev 5.7.31-0ubuntu0.16.04.1 amd64 MySQL database development files`

### 2. 在项目中使用pthread线程池
- ubuntu下安装环境包: `sudo apt-get install libpthread-stubs0-dev`
- 在CMakelists.txt文件中添加链接信息`target_link_libraries(webServer libpthread.so)`
- 通过`sudo dpkg -l`查看mysql环境包的安装详情: `libpthread-stubs0-dev:amd64 0.3-4 amd64 pthread stubs not provided by native libc, development files`