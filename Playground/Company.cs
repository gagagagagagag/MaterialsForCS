using System.Diagnostics.CodeAnalysis;
using System.Linq;

namespace Playground
{
    public class Company
    {
        private readonly string name;
        private System.Collections.Generic.List<Employee> employees;
        private static int NumOfEmp;

        public Company(string name)
        {
            this.name = name;
            employees = new System.Collections.Generic.List<Employee>();
        }

        public void AddEmployee(Employee x)
        {
            this.employees.Add(x);
            NumOfEmp++;
        }

        public int NumberOfEmployees()
        {
            return employees.Count;
        }

        public void Hire(params Employee [] employees)
        {
            foreach (Employee employee in employees)
            {
                employee.CompanyName = this.name;
                AddEmployee(employee);
                System.Console.WriteLine($"Company {this.name} hired new Tester/Developer - {employee.Name}");
                NumOfEmp++;

            }
        }

        public (decimal min, decimal max, decimal avg) CalcSalaries()
        {
            decimal sum = 0;
            decimal min=employees[0].GetSalary();
            decimal max = 0;
            decimal avg;
            
            foreach (Employee emp in this.employees)
            {
                sum += emp.GetSalary();

                if (emp.GetSalary() > max)
                {
                    max = emp.GetSalary();
                }

                if (emp.GetSalary() < min)
                {
                    min = emp.GetSalary();
                }
                
                
            }

            avg = sum / employees.Count;
            return (min: min, max: max, avg: avg);
        }

        public void MakeTests()
        {
            foreach (Employee emp in this.employees)
            {
                if (emp is Tester)
                {
                    emp.Work();
                }
            }
        }

        public void IncreaseSalaries<T>(int percentage)
        {
            foreach (Employee emp in this.employees)
            {
                var x = percentage / 100;
                if (emp is T)
                {
                    emp.IncreaseSalary(emp.GetSalary() * x);
                }
            }
        }

        public void IncreaseSalaries(int percentage, Employee emp)
        {
            if (emp.CompanyName != this.name)
            {
                return;
                
            }

            emp.IncreaseSalary(emp.GetSalary() * ((decimal)percentage/100));
            
        }

        public bool HireDeveloper(Developer d, string language)
        {
            if (d.ProgrammingLanguages.Contains(language))
            {
                this.AddEmployee(d);
                return true;
            }

            return false;
        }
        
    }
}







