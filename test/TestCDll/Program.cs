using System;
using System.Collections.Generic;
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
            Console.WriteLine("请输入两个数：");
            string aStr = Console.ReadLine();
            string bStr = Console.ReadLine();

            int a = int.Parse(aStr);
            int b = int.Parse(bStr);

            Console.WriteLine($"{a} * {b} = {mul(a, b)}");
            Console.WriteLine($"{a} / {b} = {dive(a, b)}");

            Console.ReadKey();
        }

        //注意此处调用需要指定呼叫约定
        [DllImport("TestDll.dll", CallingConvention=CallingConvention.Cdecl)]
        static extern int mul(int a, int b);

        [DllImport("TestDll.dll", CallingConvention=CallingConvention.Cdecl)]
        static extern int dive(int a, int b);
    }
}
