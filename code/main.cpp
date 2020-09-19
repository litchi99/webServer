/*
 * @Author       : mark
 * @Date         : 2020-06-18
 * @copyleft Apache 2.0
 */ 
#include <unistd.h>
#include "server/webserver.h"

int main() {
    /* 守护进程 后台运行 */
    //daemon(1, 0); 
    WebServer server(
        1316, 3, 5000, true,        /* 端口 ET模式 timeoutMs  优雅退出  */
        "47.115.79.112", 3306, "root", "888888", "cppdb", /* Mysql配置 */
        12, 6, true, 0, 1024);              /* 连接池数量 线程池数量 日志开关 日志等级 日志异步队列容量 */
    server.Start();
} 
  