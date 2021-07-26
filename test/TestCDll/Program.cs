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
        static void Main(string[] args)
        {
            //int a = mul(1, 2);
            //int b = dive(2, 3);
            //Console.WriteLine(a);
            int current = GetCurUser();
            Console.WriteLine(current);
            ChangeUser(1, "test456");
            current = GetCurUser();
            Console.WriteLine(current);
            current=ChangePassword(2, "test7893", "test789");
            Console.WriteLine(current);
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
    }
}
