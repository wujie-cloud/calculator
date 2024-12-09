/*
* @Author       : FeiYehua
 * @Date         : 2024-10-15 16:48:00
 * @LastEditTime : 2024-12-03 09:59:29
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : GetValue.c
 *      © 2024 FeiYehua
 */
//
    /*******************************************************************************
            
            File name:     GetValue.c
            Author:        FeiYehua
            
            Description:   Created for Calculator in 2024
            
            History:
                    2024/10/7: File created.
            
    ********************************************************************************/
    

#include "GetValue.h"
#include <stdio.h>
#include <math.h>
#include <errno.h>
int getTypeOfPri(int i)
{
    if(i>=0)
    {
        return i;
    }
    return -1;
}
int getValue(double* mathExpression,int* locOfPri,int numCount, double* result)
{
#if DEBUG
    for(int i=0;i<numCount;i++)
    {
        printf("%Lf,%d\n",mathExpression[i],locOfPri[i]);
    }
    printf("\n");
#endif
    int flag=0;
    for(int i=1;i<numCount;i++)
    {
        //用一个flag标志^的类型
        //如果此前读到过-3，即涉及括号，则再次读到3时，locOfPri[i-1]=0
        //如果没有，则locOfPri[i-1]*=-1
//        示例0：
//        5.000000,0                                        5.000000,0
//        2.718282,1                         -------->>>    0.000000,-1
//        2.000000,3                                        7.389056,1
//        flag=0，计算乘方后应该将1前移并补上-1
//        示例1:
//        算式：5*e^(1+1)
//        5.000000,0                                        5.000000,0
//        0.000000,-1                                       0.000000,-1
//        2.718282,1                         -------->>>    0.000000,0
//        2.000000,3 i                                      7.389056,1 i
//        flag=1,则需要将locOfPri[i-1]置0
        switch(locOfPri[i])
        {
            case 3:
            {
                mathExpression[i]=pow(mathExpression[i-1],mathExpression[i]);
                mathExpression[i-1]=0;
                locOfPri[i]=locOfPri[i-1];
                //locOfPri[i-1]=0;
                switch (flag) {
                    case 1:
                        locOfPri[i-1]=0;
                        break;
                    case 0:
                        locOfPri[i-1]*=-1;
                        break;
                    default:
                        break;
                }
                flag=0;
                break;
            }
            case -3:
            {
                flag=1;
                //printf("%Lf,i\n",mathExpression[i]);
                int startOfBracket=i;
                i++;
                while(locOfPri[i]!=3)
                {
                    locOfPri[i]=0;
                    i++;
                }
                i--;
//                操作结束后：
//                  5.000000,0
//                  2.718282,1
//                  0.000000,-3 startOfBracket
//                  0.000000，0 i
//                  2.000000,3
//
//                  5.000000,0                                          5.000000,0
//                  2.718282,1                                          0.000000,-1
//                  0.000000,-3 startOfBracket，i        -------->>>    2.718282,1 startOfBracket，i
//                  2.000000,3                                          2.000000,3
                mathExpression[i]=mathExpression[startOfBracket-1];
                mathExpression[startOfBracket-1]=0;
                locOfPri[i]=locOfPri[startOfBracket-1];
                locOfPri[startOfBracket]=(startOfBracket==i ? locOfPri[startOfBracket] : 0);
//              如果3、-3标记下标只差1，那么不继续修改locOfPri[startOfBracket]；否则置0
                locOfPri[startOfBracket-1]*=-1;
                //乘-1，标记出现了中间需要被忽略的0
                break;
            }
            default:
                break;
        }
    }
    for(int i=1;i<numCount;i++)
    {
        switch(getTypeOfPri(locOfPri[i]))
        {
            case 1:
            {
                mathExpression[i]=mathExpression[i-1]*mathExpression[i];
                mathExpression[i-1]=0;
                locOfPri[i]=0;
                break;
            }
            case 2:
            {
                mathExpression[i]=mathExpression[i-1]/mathExpression[i];
                mathExpression[i-1]=0;
                locOfPri[i]=0;
                break;
            }
            case -1:
            {
                int startOfBracket=i;
                i++;
                while(locOfPri[i]!=locOfPri[startOfBracket]*-1)
                {
                    locOfPri[i]=0;
                    i++;
                }
                i--;
                mathExpression[i]=mathExpression[startOfBracket-1];
                mathExpression[startOfBracket-1]=0;
                locOfPri[startOfBracket]=0;
            }
        }
    }
    for(int i=0;i<numCount;i++)
    {
        *result+=mathExpression[i];
        mathExpression[i]=0;
    }
    return 0;
}
