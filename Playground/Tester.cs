using System;

namespace Playground
{
    public class Tester:Employee
    {
        public Tester(string name, string companyName, decimal salary) : base( name, companyName,  salary)
        {
            
        }

        public Tester(string name, decimal salary) : base(name, salary)
        {
        }

        public override void Work()
        {
            Console.WriteLine($"Tester {this.name} writes code");
        }
    }
}