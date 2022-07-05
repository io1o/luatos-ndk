/*
 * @Author: CX 863025212@qq.com
 * @Date: 2022-07-04 19:32:23
 * @LastEditors: CX 863025212@qq.com
 * @LastEditTime: 2022-07-05 17:46:35
 * @FilePath: \LuatideNdk\example\helloworld\c\src\HelloWorld.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "HelloWorld.h"
int HelloFunc()
{
    static int aaa=0;
    return aaa++;
}
