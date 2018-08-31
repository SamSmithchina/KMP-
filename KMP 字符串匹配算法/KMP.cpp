//实现KMP算法， 掌握KMP算法在字符串匹配的高效原理

#include <iostream>
#include <string>

using namespace std;

//根据匹配字符串，求得该字符串在当前字符位置j时，下一次要匹配移动的字符数k ; next[j] =k;
// @input:
//		strAdapt, 匹配字符串
//	@output 
//		输出当前匹配串最大相同子串长度，即下次移动字符数的位置K，保存在数组 Next[]
int* KMP_Next(string strAdapt)
{
	int *iNext = new int[strAdapt.length()];

	iNext[0] = -1;
	int j = 0;
	int k = -1;
	while (j < strAdapt.length() - 1)
	{
		if (k == -1 || strAdapt.at[j] == strAdapt.at[k])
		{
			iNext[++j] = ++k;
		}
		else
		{
			k = iNext[k];
		}
	}
	return iNext;
}

//KMP算法，strAdapt字符串 对 strTarget字符串 进行匹配，
//常规字符串匹配是strAdapt逐字与目标串stTarget匹配，时间复杂度是O（Length(strTarget)* length(strAdapt));
//KMP算法思想是匹配串自身有从头部开始的子串strHeadSub，与在中间位置的子串strAnotherSub相同，下次匹配串就移动到相同子串strAmotherSub后面,
//需要用KMP_Next（)函数来计算匹配串不同位置的两个匹配子串长度，长度就是下一移动的位置；
//@input：
//		strAdapt 匹配串
//		strTarget 目标串
//@output :
//		iPosition 返回匹配串第一次匹配目标串的位置， 如果始终不匹配， 则输出-1；
int KMP(string strAdapt, string strTarget)
{
	int iTargetPos = 0;
	int iAdaptPos = 0;
	int iTemp = 0;
	int iAdaptLength = strAdapt.length();	//避免访问越界，设置访问范围
	int *iNext;// = new int[iAdaptLength];

	cout << "匹配串 ： " << strAdapt << endl;
	cout << "目标串 ： " << strTarget << endl;

	iNext = KMP_Next(strAdapt);
	for (; iTemp <= strTarget.length();)
	{
		if (iAdaptLength == (iTemp - iTargetPos))
		{
			cout << "KMP 找到目标串匹配上匹配串，位置 " << iTargetPos << endl;
			return iTargetPos;
		}

		if (strAdapt.at(iAdaptPos) == strTarget.at(iTemp))
		{
			iTemp++;
			iAdaptPos++;
		}
		else
		{
			iTargetPos += iNext[iAdaptPos];
			iTemp = iTargetPos;
		}
	}
}

int main()
{
	string "";

}