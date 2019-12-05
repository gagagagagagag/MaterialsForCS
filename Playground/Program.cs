using System;
using System.Collections.Generic;
using System.Linq;

namespace Playground
{
    class Program
    {

        static void Main(string[] args)
        {
            Random r = new Random(500);
            Console.WriteLine("--------ETAP I-----------");
            ////testing extension methods
            bool isItTrue = 5.CheckDivision(3);
            Console.WriteLine(isItTrue);
            isItTrue = 5.CheckDivision(5);
            Console.WriteLine(isItTrue);
            int val = 10;
            for (int i = 1; i <= val; i++)
                Console.WriteLine("is {0} divisible by {1}? \t {2}", val, i, val.CheckDivision(i));
            Console.WriteLine();
            string testString = "hskjfdhkjewrhkjewlfhsalkjfadshlkjfahewkjfhkjdsalhfgalkjewf";
            Console.WriteLine(testString);
            Console.WriteLine(testString.TransformString());

            Console.WriteLine("\n--------ETAP III-----------\n");
            ////testing standard queue
            int[] valuesForQueue = new int[20];

            GenericQueue<int> queue = new MyQueue<int>();
            for (int i = 0; i < valuesForQueue.Length; i++)
            {
                valuesForQueue[i] = r.Next(100);
                queue.Enqueue(valuesForQueue[i]);
                Console.WriteLine(queue.ToString());
            }

            Console.WriteLine("MyQueue size: " + queue.Count);

            queue.Dequeue();
            Console.WriteLine(queue.ToString());
            Console.WriteLine("Size is: " + queue.Count);

            queue.Dequeue();
            Console.WriteLine(queue.ToString());
            Console.WriteLine("Size is: " + queue.Count);

            queue.Dequeue();
            Console.WriteLine(queue.ToString());
            Console.WriteLine("Size is: " + queue.Count);

            var top = queue.Peek();
            Console.WriteLine("top: {0}, Size is: {1} ", top, queue.Count);
            queue.Enqueue(99);
            top = queue.Peek();
            Console.WriteLine("top: {0}, Size is: {1} ", top, queue.Count);

            GenericQueue<int> queue2 = new MyQueue<int>();
            for (int i = 0; i < 10; i++)
                queue2.Enqueue(r.Next(100));
            Console.WriteLine(queue2.ToString());
            // no exception expected
            while (queue2.Count != 0)
            {
                Console.WriteLine(queue2.ToString());
                queue2.Dequeue();
            }
            try
            {
                queue2.Dequeue();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception! : " + e.Message);
            }

            try
            {
                top = queue2.Peek();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception! : " + e.Message);
            }

            Console.WriteLine("\n--------ETAP IV-----------\n");
            ////testing priority queue
            queue = new MyPriorityQueue<int>();
            for (int i = 0; i < valuesForQueue.Length; i++)
            {
                queue.Enqueue(valuesForQueue[i]);
                Console.WriteLine(queue.ToString());
            }

            Console.WriteLine("MyQueue size: " + queue.Count);

            queue.Dequeue();
            Console.WriteLine(queue.ToString());
            Console.WriteLine("Size is: " + queue.Count);

            queue.Dequeue();
            Console.WriteLine(queue.ToString());
            Console.WriteLine("Size is: " + queue.Count);

            queue.Dequeue();
            Console.WriteLine(queue.ToString());
            Console.WriteLine("Size is: " + queue.Count);

            top = queue.Peek();
            Console.WriteLine("top: {0}, Size is: {1} ", top, queue.Count);
            queue.Enqueue(99);
            top = queue.Peek();
            Console.WriteLine("top: {0}, Size is: {1} ", top, queue.Count);

            queue2 = new MyPriorityQueue<int>();
            for (int i = 0; i < 10; i++)
                queue2.Enqueue(r.Next(100));
            Console.WriteLine(queue2.ToString());
            // no exception expected
            while (queue2.Count != 0)
            {
                Console.WriteLine(queue2.ToString());
                queue2.Dequeue();
            }
            try
            {
                queue2.Dequeue();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception! : " + e.Message);
            }

            try
            {
                top = queue2.Peek();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception! : " + e.Message);
            }

            Console.WriteLine("\n--------ETAP V-----------\n");
            //using lambda 

            int[] randomIntegers = new int[100];
            for (int i = 0; i < randomIntegers.Length; i++)
                randomIntegers[i] = r.Next(1, 100);
            IEnumerable<int> filtered = null;//
            //filtered = ... here write Where statement to get even elements from randomIntegers.
            filtered = randomIntegers.Where(item => item % 2 == 0);
            foreach(var i in filtered)
                Console.Write(i + " ");

            List<Book> books = new List<Book>() {
             new Book { Name = "Star Wars", Year = 2000 },
             new Book { Name = "Lord of The Rings", Year = 1954 },
             new Book { Name = "Math is fun", Year = 1950 }
          };
            IEnumerable<Book> newBooksList = null;
            //newBooksList = ... here write Select statement to create new list with transformed elements from books collection
            newBooksList = books.Select(book => new Book{Name = book.Name, Year = book.Year - 100});
            foreach (var item in newBooksList)
                Console.WriteLine(item);

            int yearSum = 0;
            //yearsSum = ... here write Sum statement to sum years of all of the elements from books list.
            yearSum = books.Sum(book => book.Year);
            Console.WriteLine("Sum is: " + yearSum);
        }
    }
}
