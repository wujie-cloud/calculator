/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-10-07 11:56:07
 * @LastEditTime : 2024-12-16 21:26:58
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : ParseMathExpression.h
 * @     © 2024 FeiYehua
 */
//
    /*******************************************************************************
            
            File name:     ParseMathExpression.h
            Author:        FeiYehua
            
            Description:   Created for Calculator in 2024
            
            History:
                    2024/10/7: File created.
            
    ********************************************************************************/
    

#ifndef ParseMathExpression_h
#define ParseMathExpression_h


int parseMathExpression(char*,double*,int*,int*,double);
//核心计算函数。
//解析一个字符数组中存储的表达式。
//第一个参数，是目标计算表达式；
//第二个参数存储解析得到的数值
//第三个参数，存储解析得到的数字数量；
//第四个参数，存储计算优先级，用来解决括号嵌套等运算顺序问题
//第五个参数为预留参数。
#endif /* ParseMathExpression_h */
