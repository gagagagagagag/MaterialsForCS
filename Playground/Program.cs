using System;

namespace Playground
{
    class Program
    {
        static void Main(string[] args)
        {
            var jp = new Company("Jebac psy");
            var Kuba = new Developer("Jakub Przywara", 300000);

            jp.Hire(Kuba);
            
            Console.WriteLine(jp.CalcSalaries());
        }
    }
}