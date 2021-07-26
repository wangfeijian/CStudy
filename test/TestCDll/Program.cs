using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace TestCDll
{
    class Program
    {
        enum SysBitReg
        {
            测试1,
            寄存器
        }

        enum SysIntReg
        {
            IntTestOne,
            IntTestTwo,
        }

        enum SysDoubleReg
        {
            DoubleTestOne,
            DoubleTestTwo,
        }

        enum SysStringReg
        {
            StrTestOne,
            StrTestTwo,
        }
        static void Main(string[] args)
        {
            //int a = mul(1, 2);
            //int b = dive(2, 3);
            //Console.WriteLine(a);
            //int current = GetCurUser();
            //Console.WriteLine(current);
            //ChangeUser(1, "test456");
            //current = GetCurUser();
            //Console.WriteLine(current);
            //current=ChangePassword(2, "test7893", "test789");
            //Console.WriteLine(current);
            SetBit((int)SysBitReg.测试1,(char)1);
            SetBit((int)SysBitReg.寄存器,(char)0);
            Console.WriteLine(GetBit((int)SysBitReg.测试1)==1);
            Console.WriteLine(GetBit((int)SysBitReg.寄存器)==1);

            SetInt((int)SysIntReg.IntTestOne,100);
            SetInt((int)SysIntReg.IntTestTwo,200);
            Console.WriteLine(GetInt((int)SysIntReg.IntTestOne));
            Console.WriteLine(GetInt((int)SysIntReg.IntTestTwo));

            SetDouble((int)SysDoubleReg.DoubleTestOne,123.5);
            SetDouble((int)SysDoubleReg.DoubleTestTwo,133.5);
            Console.WriteLine(GetDouble((int)SysDoubleReg.DoubleTestOne));
            Console.WriteLine(GetDouble((int)SysDoubleReg.DoubleTestTwo));

            SetString((int)SysStringReg.StrTestOne, "This is test");
            SetString((int)SysStringReg.StrTestTwo, "This is test two");
            IntPtr ptr1=GetString((int)SysStringReg.StrTestOne);
            IntPtr ptr2 = GetString((int)SysStringReg.StrTestTwo);
            string str1 = Marshal.PtrToStringAnsi(ptr1);
            string str2 = Marshal.PtrToStringAnsi(ptr2);
            Console.WriteLine(str1);
            Console.WriteLine(str2);
            Console.ReadKey();
        }

     

        //注意此处调用需要指定呼叫约定
        [DllImport("TestDll.dll", CallingConvention=CallingConvention.Cdecl,CharSet = CharSet.Unicode)]
        static extern int mul(int a, int b);

        [DllImport("TestDll.dll", CallingConvention=CallingConvention.Cdecl,CharSet = CharSet.Unicode)]
        static extern int dive(int a, int b);

        [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int GetCurUser();

        [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int ChangeUser(int nNewUser, string szPassword);

        [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int ChangePassword(int nUser, string szPassword, string szNewPassword);

         [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern char GetBit(int index);

         [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern void SetBit(int index, char value);

         [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int GetInt(int index);

         [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern void SetInt(int index, int value);

         [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern double GetDouble(int index);

         [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern void SetDouble(int index, double value);

        // c中的char *返回，在c#中需要通过IntPtr来接收
         [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern IntPtr GetString(int index);

         [DllImport("SecurityLib.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern void SetString(int index, string str);


    }
}
