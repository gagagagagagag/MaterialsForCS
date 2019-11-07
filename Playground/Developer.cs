using System;

namespace Playground
{
    public class Developer : Employee
    {
        private string [] programmingLanguages;
        public Developer ( string name, string companyName, decimal salary, string [] programmingLanguages) : base (name, companyName, salary)
        {
            this.programmingLanguages = programmingLanguages;
        }

        public Developer(string name, decimal salary) : base(name, salary)
        {
        }

        public string[] ProgrammingLanguages
        {
            get => programmingLanguages;
            set => programmingLanguages = value;
        }

        public override void Work()
        {
            Console.WriteLine($"Developer {this.name} writes code");
        }
    }
}