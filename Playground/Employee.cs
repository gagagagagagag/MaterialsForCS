
namespace Playground
{
    public abstract class Employee
    {
        protected readonly string name;
        private string companyName;

        public string CompanyName
        {
            get => companyName;
            set => companyName = value;
        }

        public string Name
        {
            get => name;
        }
        private decimal salary;


        protected Employee(string name, string companyName, decimal salary)
        {
            this.name = name;
            this.companyName = companyName;
            this.salary = salary;
        }

        protected Employee(string name, decimal salary)
        {
            this.name = name;
            this.salary = salary;
        }

        public void IncreaseSalary(decimal value)
        {
            this.salary += value;
        }

        public decimal GetSalary()
        {
            return this.salary;
        }

        public abstract void Work();
    }
}